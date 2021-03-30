#pragma once 
#include "gene_utils.h"
#include "organism.h"

class Bacteria: public Organism{
 public:
    using Organism::Organism;
    Organism* reproduce(Organism* = nullptr){
        Organism* A = new Bacteria(get_name().c_str(), mutation(kod));
        
        return A;
    }
    
    ~Bacteria(){}
};