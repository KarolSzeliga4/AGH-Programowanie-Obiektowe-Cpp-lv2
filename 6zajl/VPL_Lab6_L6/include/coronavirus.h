#pragma once
#include <iostream>
#include "virus.h"

class CoronaVirus: public Virus {
public:
    CoronaVirus(const char*, const char*, std::vector<Nucleotide>);
    CoronaVirus();
    CoronaVirus(CoronaVirus&&);
    CoronaVirus(CoronaVirus&);
    ~CoronaVirus();
    CoronaVirus& operator=(const CoronaVirus&);
    CoronaVirus& operator=(CoronaVirus&&);
    std::string get_animal_host() const;
private:
    std::string imieZ;
};