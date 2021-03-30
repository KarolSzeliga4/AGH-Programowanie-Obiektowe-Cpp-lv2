// Tutaj należy wpisać kod
#pragma once

#include<iostream>
#include <vector>
#include<array>
#include <tuple>

using namespace std;
typedef tuple<int,int,int,int,int> Time;

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
	constexpr size_t k[5] = {0,1,2,3,4};
    Time sum {get<k[0]>(A)+get<k[0]>(B),get<k[1]>(A)+get<k[1]>(B), get<k[2]>(A)+get<k[2]>(B), get<k[3]>(A)+get<k[3]>(B), get<k[4]>(A)+get<k[4]>(B)} ;
    // for(constexpr auto& i: k)
    // 	get<i>(sum) = get<i>(A)+get<i>(B);
   	return sum;
}

Time operator""_sec(long long unsigned int s){
    Time t {s/HM/HM/D/L, s/HM/HM/D%L, s/HM/HM%D, s/HM%HM, s%HM};
    return t;
}

Time operator""_yrs( long long unsigned int l){
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
        Human(const string a, Time b ): name(a),t_hum(b),c_clo(0){} 
        string get_name()const {return name;}
        void update_time(Time a){
        	t_hum = {get<0>(t_hum)+ get<0>(a), get<1>(t_hum)+ get<1>(a), get<2>(t_hum)+ get<2>(a), get<3>(t_hum)+ get<3>(a), get<4>(t_hum)+ get<4>(a)};
        }
        Time get_age()const {return t_hum;}
        int get_c()const {return c_clo;}
        void for_c(){c_clo ++;}
};

class Clone : public Human{
    public:
        Clone(Human& h): Human(h.get_name() + "_" + to_string(h.get_c()+1) , h.get_age() ) { h.for_c(); }
};


