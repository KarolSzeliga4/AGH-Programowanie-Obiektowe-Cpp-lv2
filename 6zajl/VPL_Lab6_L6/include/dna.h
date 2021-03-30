#pragma once
#include "gene_sequence.h"

class DNA: public GeneSeq
{
public:
    friend std::ostream& operator<<( std::ostream& out, const DNA& dna_);
    DNA(std::vector< Nucleotide >,std::vector< Nucleotide >);
    DNA(GeneSeq &, GeneSeq &);
    //DNA();
    
    std::vector< Nucleotide > operator[](int a) const;
    std::vector< Nucleotide >& set_chain(int a){if(a == 0) return chain; else return down_chain;} 
private:
    std::vector< Nucleotide > down_chain;
};