#include "sapper.h"

Sapper::Sapper(): Game(), _plansza(nullptr), _x(0), _y(0), _ileBomb(0), _shoots(0){}
 Sapper::~Sapper(){
 	if(_plansza != nullptr)
		delete _plansza;
 }

void Sapper::new_board(const Board& B){
	_x = B.get_geometry(1);
	_y = B.get_geometry(2);
	_ileBomb = B.get_geometry(3); // zbieranie danych z Board

	if(_plansza == nullptr) 
		_plansza = new matrix(_x,_y); //jeśli pierwsza gra, to tworzymy planszę 

	_shoots = 0; // nowa rozgrywka, resetuje _shoots

	int x_y =_x*_y;
	bool gdzieBomby[20*20]; // tablica do losowania miejsc bomb
	bool notfound;//bool do pętli while        
	for (int i = 0; i < 400; ++i)          // gdy nie ustalam wszystkich: błąd valgrinda przy X<Y
	{
		gdzieBomby[i] = false; // na początku nigdzie nie ma bomby
	}

	int a;
	for (int i = 0; i < _ileBomb; ++i) // TU LOSOWANIE MIEJSC BOMB, troche nieoptymalne
	{
		notfound = true;
		do
		{
			a = rand() % x_y;  // losuje miejsce dla bomby 
			if(!gdzieBomby[a]) 
			{ 				   // jeśli na miejscu nie ma bomby ustalamy tam bombę  
				gdzieBomby[a] = true;
				notfound = false;
			}
		} while(notfound);//szukamy miejsca dla następnej bomby
	}

	for (int i = 0; i < _y; ++i) // tam gdzie bomby -200, reszta -100
	{
		for (int j = 0; j < _x; ++j) 
		{
			if(gdzieBomby[i*_y +j]) (*_plansza)[i][j]=-200;
			else (*_plansza)[i][j]=-100;
		}
	}

	int xbomb, ybomb;
	// ustalanie ile bomb sąsiaduje z każdym polem
	for ( ybomb = 0; ybomb < _y; ++ybomb)
	{
		for ( xbomb = 0; xbomb < _x; ++xbomb) // przechodzę po tablicy gdzieBomby jak znajdę bobmę zwiększam 9 pól o 1 
		{
			if(gdzieBomby[ybomb*_y + xbomb])	
			{								 //kolejna bomba ma współrzędne [ybomb][xbomb]
				for (int i = -1; i < 2 ; ++i)
				{
					for (int j = -1; j < 2; ++j)
					{
						if((xbomb+i >= 0 && xbomb+i < _x) && (ybomb+j >= 0 && ybomb+j < _y))
							(*_plansza)[ybomb+j][xbomb+i]++;
					}
				}
			}
		}
	}
}
void Sapper::print_board(){ // funkcja zakłada, że tylko odkryte(+100) są miejsca bez bomb 
	std::cout<<"\n";

	for (int i = 0; i < _y; ++i)
	{
		for (int j = 0; j < _x; ++j)
		{
			if((*_plansza)[i][j]>=0) std::cout<<(*_plansza)[i][j]<<" ";//wyświetlam tylko odkryte pola
			else std::cout<<"* ";         // reszta ukryta pod gwiazdką
		}
		std::cout<<"\n";
	}
}
bool Sapper::operator()(int x,int y){
	if((x >= 0 && x < _x) && (y >= 0 && y < _y))
	{//jeśli trafiono w planszę
		
		if((*_plansza)[y][x]>-111 && (*_plansza)[y][x]<-80) 
		{// trafiono w pole bez bomby 
			
			(*_plansza)[y][x] = (*_plansza)[y][x] + 100;
			_shoots++;
			if(_shoots + _ileBomb == _x*_y)
			{
				std::cout<<"\nGood job! You survived!\n";
				return false;//wygrana
			}
			else return true;
		}
		else
		{// trafiono w pole z bombą lub ponownie w odkryte
			if((*_plansza)[y][x]>-201 && (*_plansza)[y][x]<-180)
			{
				std::cout<<"\n\n!!!   BOOOOM    !!!\n     Game Over \n";
				return false;//przegrana
			}
			else return true; // trafiono w pole już odkryte bez bomby
		}
	}
	else
	{//jeśli nie trafiono w planszę
		std::cout<<"\nout of range...\n\n";
		return true;
	}
}
