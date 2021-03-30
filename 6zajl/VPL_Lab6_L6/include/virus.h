#pragma once
#include <iostream>
#include "gene_sequence.h"

class Virus{
public:
    Virus(const char*);
    Virus(Virus&&);
    Virus(Virus&);
    Virus& operator=(const Virus& );
    Virus& operator=(Virus&&);
    void set_RNA(const std::vector<Nucleotide> );
    std::string get_name() const;
    GeneSeq* get_RNA() const;
    int& get_age();
    ~Virus();
protected:
    std::string imie;
    GeneSeq *wrna;
    int wiek;
};