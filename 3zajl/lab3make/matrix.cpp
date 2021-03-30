#include "vector.h"
#include "matrix.h"
using namespace MyStuff;

matrix::matrix(): _sizx(0), _sizy(0), _wskv(nullptr){}

matrix::matrix(int sx, int sy): _sizx(sx), _sizy(sy), _wskv(new vector*[_sizy]){
	for (int i = 0; i < _sizy; ++i)
	{
		_wskv[i]= new vector(_sizx); //inicjuje _sizy wierszy(wektorów) wypełnionych 0 
	}
}

matrix::matrix(const matrix& tocp){
	_sizx = tocp._sizx;
	_sizy = tocp._sizy;
	_wskv = new vector*[_sizy];
	for (int i = 0; i < _sizy; ++i)
	{
		_wskv[i]= new vector(_sizx);
		*(_wskv[i])= *(tocp._wskv[i]);
	}
}

matrix::matrix(matrix&& tomv){
	_sizx =std::move(tomv._sizx);
	_sizy =std::move(tomv._sizy);
	_wskv =std::__exchange(tomv._wskv, nullptr);
}


matrix::~matrix(){
	if(_wskv != nullptr){
		for (int i = 0; i < _sizy; ++i)
		{
			delete _wskv[i];
		}
		delete [] _wskv;
	}
}

matrix& matrix::operator=(const matrix &A){
	if(&A == this)
		return *this;

	if(_wskv != nullptr){
		for (int i = 0; i < _sizy; ++i) //aby móc uzupełnić na nowo macierz muszę pozbyć się jej zawartości  
		{
			delete _wskv[i]; 
		}
		delete [] _wskv;
	}
	_sizx = A._sizx;
	_sizy = A._sizy;
	_wskv = new vector*[_sizy];
	for (int i = 0; i < _sizy; ++i)
	{
		_wskv[i]= new vector(_sizx);
		*(_wskv[i]) = *(A._wskv[i]);
	}
	return *this;
}

matrix& matrix::operator=(matrix &&A){
	if(&A == this)
		return *this;

	if(_wskv != nullptr){
		for (int i = 0; i < _sizy; ++i) //aby móc uzupełnić na nowo macierz muszę pozbyć się jej zawartości  
		{
			delete _wskv[i]; 
		}
		delete [] _wskv;
		_sizx=0;
		_sizy=0;
	}
	std::swap(_sizx,A._sizx);
	std::swap(_sizy,A._sizy);
	std::swap(_wskv,A._wskv); //zamienia cały blok pamięci, wraz ze wszystkimi wektorami
	return *this;
	
}


std::ostream& operator<<(std::ostream &o,const MyStuff::matrix &toShow){
	if(toShow._wskv == nullptr){
		o<<"pusta macierz!\n";
		return o;
	}
	else{
		for (int i = 0; i < toShow._sizy; ++i)
		{
			o<< *(toShow._wskv[i])<<"\n"; //użycie wyświetlania z klasy vector
		}
		o<<"\n";	
		return o;
	}
}

vector& matrix::operator[](int i) const{
	if(i>=_sizy || i<0)
	{
		std::cout<<"ERROR:vec[i<0||i>sizy], zwracam tab[0]!";
		return *(_wskv[0]);
	}
	else{
		return *(_wskv[i]);
	}
}

void matrix::fill(const vector* tabv, int siztab){
if(_wskv != nullptr){
	if(_sizy != siztab || _sizx != tabv->size() )
		std::cout<<"nie da sie wypelnic: nie pasuje wymiar";
	else{
		for (int i = 0; i < siztab; ++i)
		{
			*(_wskv[i]) = tabv[i]; //wykorzystanie operatora klasy vector = (kopiującego)
		}
	}
}
}

matrix matrix::operator+(const matrix& A) const{ //zakładam, że nie dodajemy pustych macierzy
	int maxY, maxX;
	if(_sizy > A._sizy) //ustalam rozmiary dla macierzy wynikowej
		maxY = _sizy;
	else
		maxY = A._sizy;

	if(_sizx > A._sizx) 
		maxX = _sizx;
	else
		maxX = A._sizx;

	matrix sum(maxX,maxY); //macierz wypełniona samymi 0

	for (int i = 0; i < _sizy; ++i) 
		for (int j = 0; j < _sizx; ++j)
 			sum[i][j] = (*this)[i][j]; // dodaje do macierzy pierwszą macierz

 	for (int i = 0; i < A._sizy; ++i)  // dodaje do macierzy drugą macierz
		for (int j = 0; j < A._sizx; ++j)
 			sum[i][j] += A[i][j];
	
	return sum;
}

matrix matrix::operator*(const matrix& A) const{
	if( _sizx != A._sizy || (_sizx == 0 && A._sizy==0) ){
		std::cout<<"ERROR: nie pasują wymiary! zwracam *this";
		return *this;
	}  
	matrix mult(A._sizx, _sizy); //wypełniona zerami

	for (int i = 0; i < _sizy; ++i) 
	{
		for (int j = 0; j < A._sizx; ++j) // algorytm mnożenia macierzy
		{
			for (int k = 0; k < _sizx; ++k)
			{
				mult[i][j] += (*this)[i][k] * A[k][j];  
			}
		}
	}

	return mult;
}
