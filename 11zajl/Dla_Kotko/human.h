// Tutaj należy wpisać kod
#pragma once

#include<iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef Time Time;

const int HM = 60; // przydałby się własny namespace
const int D = 24;
const int L = 365;

ostream& operator <<(ostream& out, const Time& A){
        out<<get<0>(A)<<"y: ";
        out<<get<1>(A)<<"d: ";
        out<<get<2>(A)<<"h: ";
        out<<get<3>(A)<<"m: ";
        out<<get<4>(A)<<"s ";
    return out;
} 

Time operator+(const Time& A, const Time& B){
    Time sum{get<0>(A)+ get<0>(B), get<1>(A)+ get<1>(B), get<2>(A)+ get<2>(B), get<3>(A)+ get<3>(B), get<4>(A)+ get<4>(B)};
    return sum;
}

Time operator""_sec(long long unsigned int s){
    Time t {static_cast<int>(s/HM/HM/D/L), static_cast<int>(s/HM/HM/D%L),static_cast<int>(s/HM/HM%D),static_cast<int>(s/HM%HM),static_cast<int>(s%HM)};
    return t;
}

Time operator""_yrs(long long unsigned int l){
    Time t {static_cast<int>(l), 0,0,0,0};
    return t;
}

long long unsigned int to_sec(Time A){
    return get<4>(A)+ HM*get<3>(A) + HM*HM*get<2>(A)+ D*HM*HM*get<1>(A) + L*D*HM*HM*get<0>(A);
}

Time from_sec(int s){
    return operator""_sec(s);
}

class Human{
    protected:
        string name;
        Time t_hum;
        int c_clo;
    public:
        Human(): name(" "),t_hum(make_tuple(0,0,0,0,0)),c_clo(0){}
        Human(const string a, Time b ): name(a),t_hum(b),c_clo(0){} 
        string get_name()const {return name;}
        Time get_age()const {return t_hum;}
        int get_c()const {return c_clo;}
        void for_c(){c_clo ++;}
};

class Clone : public Human{
    public:
        Clone(Human& h){
            h.for_c();
                name = h.get_name() + "_" + to_string(h.get_c());
            t_hum = h.get_age();
        }
};


