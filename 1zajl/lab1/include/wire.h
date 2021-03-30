#pragma once 
#include<iostream>


class QuantumWire
{
    public:
    	friend std::ostream& operator<<(std::ostream& o, const QuantumWire&);
    	friend QuantumWire operator*(double, const QuantumWire&);

    	QuantumWire();
        QuantumWire(double, int);
        QuantumWire( const QuantumWire &);
        QuantumWire(QuantumWire &&);
        ~QuantumWire();

        QuantumWire& operator=(const QuantumWire &);
        QuantumWire& operator=(QuantumWire &&);
        QuantumWire operator!() const;
        QuantumWire operator*(double) const;
        QuantumWire& operator*=(double);
        bool operator[](int i);
        bool operator()(const QuantumWire&, const QuantumWire&);
        operator int();
    private:
        double _drut_dlu;
        int _ile_cz;
        bool* _tab; 
};