#pragma once 

#include "virus.h"
#include "dna.h"
#include <iostream>

class Organism{
 public:
    Organism(const char*, DNA);
    std::string get_name() const;
    DNA get_dna() const;
    virtual Organism* reproduce(Organism* = nullptr )= 0;
    void operator<<(const Virus&);
    
    virtual ~Organism(){}
protected:
    std::string name;
    DNA kod;
};