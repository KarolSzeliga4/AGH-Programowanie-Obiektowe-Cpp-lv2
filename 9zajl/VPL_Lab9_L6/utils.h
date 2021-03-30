// Tutaj proszę napisać pozostały kod
#pragma once
#include<functional>
#include<vector>

using namespace std;

typedef function <vector<double>()> f;
typedef vector< f > Program;

class Coordinates{
public:
    friend ostream& operator<<(ostream& a, const Coordinates& C);
    Coordinates(double a = 0, double b = 0): dl(a), sz(b){}
    Coordinates& operator +=(const Coordinates& C){
        dl += C.dl;
        sz += C.sz;
        return *this;
    }
    Coordinates& operator -=(const Coordinates& C){
        dl -= C.dl;
        sz -= C.sz;
        return *this;
    }
    vector<double> operator -(const Coordinates& C) const{
        return vector<double>{ dl - C.dl, sz - C.sz };
    }
    
//private:
     double dl;
     double sz;
};

ostream& operator<<(ostream& a, const Coordinates& C){
    a<<"("<< C.dl <<","<<C.sz<<")";
    return a;
}

namespace MarsRoutes{
    Program route1(){
        return { [](){ return vector<double>{1.,-1.}; }, [](){ return vector<double>{1.,0.}; }, [](){ return vector<double>{1.,-1.}; } };
    }
    Program go_to(const Coordinates& a, const Coordinates& b){
        
        return { [&a,&b](){ return vector<double>{b.dl - a.dl, b.sz - a.sz}; } };
    } 
}