#include "gene_sequence.h"

std::ostream& operator<<( std::ostream& out, const GeneSeq& seq_)
{
    int size = seq_.chain.size();
    char x;
    for(int i=0; i< size ; i++){
        x = seq_.chain[i];
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}