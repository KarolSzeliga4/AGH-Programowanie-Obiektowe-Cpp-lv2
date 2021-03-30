#include <sapper_board.h>

int match(int a){  // ograniczenie parametrów planszy 
	if(a < 5)a =5;
	if(a > 20)a =20;
	return a;
}
int matchBombs(int x, int y, int a){
	if(a < 2) a = 2;
	if(a > x*y/3) a = x*y/3;
	return a;
}
SapperBoard::SapperBoard(int sizex,int sizey,int ileChceBomb): Board( match(sizex), match(sizey), matchBombs(sizex, sizey, ileChceBomb) ) {}
SapperBoard::~SapperBoard(){}

int SapperBoard::get_geometry(int x1y2b3) const{ // zwraca odziedziczone składniki Boarda 
	if(x1y2b3 == 1) return _sizex; 
	if(x1y2b3 == 2) return _sizey;
	if(x1y2b3 == 3) return _ilosc; // ilosc bomb i wymiary już ograniczone 
	return 0;
}

double SapperBoard::get_params(int a) const{return 0.;} // ma być nieużywana
