#include "wire.h"

using namespace std;

QuantumWire::QuantumWire():_drut_dlu(0), _ile_cz(0), _tab(nullptr){}

QuantumWire::QuantumWire(double drut_dlu, int ile_cz):_drut_dlu(drut_dlu), _ile_cz(ile_cz), _tab(new bool[_ile_cz]){
   	for(int i=0; i<_ile_cz; ++i)
       	_tab[i] = rand() % 2;
}

QuantumWire::QuantumWire( const QuantumWire& A){
    _drut_dlu = A._drut_dlu;
    _ile_cz = A._ile_cz;

    if(A._tab != nullptr){
    	_tab = new bool[_ile_cz];
    	//cout<<"\nkopiujący konstr.\n";
    	for(int i=0; i<_ile_cz; ++i)
    	    _tab[i] = A._tab[i];
	}
	else _tab = nullptr;

}

QuantumWire::QuantumWire(QuantumWire && A){
    _drut_dlu =std::move(A._drut_dlu);
    _ile_cz = std::move(A._ile_cz);

    if(A._tab != nullptr)
    	_tab = std::__exchange(A._tab, nullptr);
    else 
    	_tab = nullptr;
    //cout<<"\nprzenoszcy konstr.\n";
}

std::ostream& operator<<(std::ostream& o, const QuantumWire& A){
	o<<"length: "<<A._drut_dlu<<", quanta: ";
	for(int i=0; i<A._ile_cz; ++i)
		o<<A._tab[i]<<" ";
	return o;
}

QuantumWire::~QuantumWire(){
	//cout<<"\ndest.\n";
	if(_tab != nullptr)
    	delete [] _tab;
}

QuantumWire QuantumWire::operator!() const {
	QuantumWire B = *this;
	for(int i=0; i<B._ile_cz ;i++)
	{
		B._tab[i] = !B._tab[i];
	}
	return B;
}

QuantumWire operator*(double a, const QuantumWire& A){
	QuantumWire B = A;
	B._drut_dlu *= a; 
	return B;
}

QuantumWire QuantumWire::operator*(double a) const {
	QuantumWire B = *this;
	B._drut_dlu *= a; 
	return B;
}

QuantumWire& QuantumWire::operator*=(double a){
	_drut_dlu *= a; 
	return *this;
}

bool QuantumWire::operator[](int i){
	return _tab[i];
}

QuantumWire::operator int(){
	return _ile_cz;
}

QuantumWire& QuantumWire::operator=(const QuantumWire & A){
	if(this == &A)
		return *this;
	
	if(_tab != nullptr)
		delete [] _tab;

	_drut_dlu = A._drut_dlu;
	_ile_cz = A._ile_cz;

	if(A._tab != nullptr){
		_tab = new bool[_ile_cz];
		for(int i=0; i<_ile_cz ;i++)
			_tab[i]= A._tab[i];
	}
	else
		_tab = nullptr;

	return *this;
}
QuantumWire& QuantumWire::operator=(QuantumWire && A ){
	if(this == &A)
		return *this;
	if(_tab != nullptr)
		delete [] _tab;

	_drut_dlu = std::move(A._drut_dlu);
	_ile_cz = std::move(A._ile_cz);

	if(A._tab != nullptr) _tab = std::__exchange(A._tab, nullptr);
    else _tab = nullptr;
	
	return *this;
}

bool QuantumWire::operator()(const QuantumWire& A, const QuantumWire& B){
	return A._drut_dlu > B._drut_dlu;
}