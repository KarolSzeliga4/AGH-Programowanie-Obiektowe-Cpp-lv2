// Tutaj należy pisać program

#pragma once
#include<algorithm>
#include <initializer_list>
#include<vector>
#include <functional>
#include<iostream>
#include<map>
#include "blackhole.h"

using namespace std;
                        //nie ma lepszego sposobu na inicjalizacje?
 map<int,string> lit = {{0,"I."},{1,"II."},{2,"III."},{3,"IV."},{4,"V."}};  //pomocnicza mapa 
                                                                            //przy zmianie na const błędy

class BHCatalogue{
private:
    map<string,BlackHole> cat;
    int ile = 0; // aktualna wielkość katalogu
public:
    void add(const BlackHole& A){// dwie funkcje add, chyba najłatwiej
        if(ile<5){
            cat.insert(std::pair<std::string, BlackHole>(lit[ile], A)); // użyta pomocnicza mapa
            ile++;
        }
        else   cout<<">> Catalogue full. \""<< A.get_name() <<"\" not added.\n";
    }

    void add(std::initializer_list<BlackHole> A){ 
        for(auto&v: A) add(v);
    }
    BlackHole get(const string& num){ // jak nie zwracam referencji wyskakują błędy // gettery powinny być const...
        return cat[num];
    }
    map<string,BlackHole> get_map()const{return cat;}
    
    vector<BlackHole> get_ordered_by_mass() const{
        vector<BlackHole> vec;
        map< string, BlackHole > m = cat; // bez tego błędy przy: cat[ lit[i] ]
        for(int i =0; i<ile; i++) vec.push_back(m[lit[i]]);
        
        sort(begin(vec),end(vec), [](BlackHole &A, BlackHole &B){return A.get_mass()<B.get_mass();});// sortowanie według masy
        return vec;
    }
    
    std::vector<BlackHole> get_custom(std::function< bool(const BlackHole& bh_) > fun){ //metoda zwracajaca porzadany wektor czarnych dziur
            std::vector<BlackHole> nowy;
            for(auto &x:cat){
                if(fun(x.second)){
                    nowy.push_back(x.second);
                }
            }
            return nowy;
         }
};