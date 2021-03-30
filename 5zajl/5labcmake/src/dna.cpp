#include "dna.h"

std::ostream& operator<<( std::ostream& out, const DNA& dna_){
    int size1_2 = dna_.chain.size();
    char x;
    for(int i=0; i< size1_2 ; i++){
        x= dna_.chain[i];
        out<<x<<" ";
    }
    out<<"\n";
    for(int i=0; i< size1_2 ; i++)
        out<<"| ";
    out<<"\n";
    std::vector<Nucleotide> v = dna_.down_chain.get_sequence();
    for(int i=0; i< size1_2 ; i++){
        x= v[i];
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}

DNA::DNA(GeneSeq& S1, GeneSeq& S2): GeneSeq( S1.get_sequence() ), down_chain(S2.get_sequence()) {}