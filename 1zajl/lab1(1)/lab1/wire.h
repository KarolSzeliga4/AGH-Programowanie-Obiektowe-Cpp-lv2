#pragma once 

class QuantumWire
{
    public:
        QuantumWire(double, int);
        QuantumWire( const QuantumWire &);
        QuantumWire(QuantumWire &&);
        ~QuantumWire();
    private:
        double _drut_dlu;
        bool* _tab_cz; 
        int _ile_cz;
}
