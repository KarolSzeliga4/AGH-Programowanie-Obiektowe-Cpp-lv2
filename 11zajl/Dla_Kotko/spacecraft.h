// Tutaj należy wpisać kod
#pragma once
#include "human.h"
#include<iostream>
#include<function>
using namespace std;

class Spacecraft{
    private:
        vector<Human> po;
        double vel;
  public:
        Human operator[](string a){
            return po[0];
        }
        update_time(function<> f, 
				// fcja zwraca czas w układzie znajdującym sie w odl. r od masy M
				const decltype(1_yrs)& time) { 
					const double c = 3e8; // prędkość światła w [m/s]
					const double G = 6.67e-11; // stała grawitacji [m^3/kg/s^2]
					const double Msun=2e30; // masa słońca [kg] 
					const double lam=sqrt(1.-2.*G*M*Msun/r/c/c/1000.); 
					return from_sec(lam*to_sec(time)); } // skrócenie czasu;
			  , t);
};
