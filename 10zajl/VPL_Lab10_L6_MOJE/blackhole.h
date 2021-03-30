// Tutaj należy pisać program

#pragma once
#include<iostream>

using namespace std;

//const double G=6.67e-11, S=2e30, c=3e8;// nie wiem czy najlepsze miejsce na stałe

class BlackHole{
private:
	static double G=6.67e-11, S=2e30, c=3e8;
    string name;
    double mas; //troche niedopatrzone nazwy
    double pro;
    double odl;
    double wzor_pro(){return 2*G*S*mas/c/c/1000;} //wzór zwraca km // niesprecyzowano jednostek promienia

public:
    friend ostream& operator<<(ostream& out, const BlackHole& A){
        out<<A.name<<" : M=" << A.mas << " solar mass, Rh="<< A.pro << " km, dist="<< A.odl<<" pc\n";
        return out;
    }
    BlackHole(const string& a= " ", double m= 0, double o=0): name(a), mas(m), pro(wzor_pro()), odl(o){} 
    string get_name() const{return name;}                 // konstruktor ()  potrzebny do pustej mapy 
    double get_mass() const{return mas;}
    double get_Rh() const{return pro;} //metoda zwracajaca odleglosc
        
    
};

double operator""_pc(long double a){ //operator literalu
    return a*3.1e13;
}