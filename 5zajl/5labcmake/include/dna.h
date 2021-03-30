#pragma once
#include "gene_sequence.h"

class DNA: public GeneSeq
{
public:
    friend std::ostream& operator<<( std::ostream& out, const DNA& dna_);
    DNA(GeneSeq &, GeneSeq &);
private:
    GeneSeq down_chain;
};
