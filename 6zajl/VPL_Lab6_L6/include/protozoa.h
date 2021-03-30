#pragma once 
#include "gene_utils.h"
#include "organism.h"

class Protozoa: public Organism{
 public:
    using Organism::Organism;
    Organism* reproduce(Organism* P){
    	if(get_name() == P->get_name()){
    		DNA dna = DNA(kod[0],P->get_dna()[1]);
        	Organism* A = new Protozoa(get_name().c_str(), mutation(dna) );
        	return A;
        }
        else return nullptr;
    }
    
    ~Protozoa(){}
};