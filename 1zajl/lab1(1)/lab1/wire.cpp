#include "wire.h"
#include <iostream>

QuantumWire::QuantumWire(double drut_dlu = 1., int ile_cz = 2):_drut_dlu(drut_dlu) , _ile_cz(ile_cz){
    _tab_cz = new bool[_ile_cz];
    for(int i=0; i<_ile_cz; ++i)
        _tab_cz[i] = rand(2);
}
QuantumWire::QuantumWire( const QuantumWire & A){
    _drut_len = A._drut_len;
    _ile_cz = A._ile_cz;
    _tab_cz = new bool[_ile_cz];
    for(int i=0; i<_ile_cz; ++i)
        _tab_cz[i] = A._tab_cz[i];
}
QuantumWire::QuantumWire(QuantumWire && A){
    
}

QuantumWire::~QuantumWire(){
    delete [] _tab_cz;
}
