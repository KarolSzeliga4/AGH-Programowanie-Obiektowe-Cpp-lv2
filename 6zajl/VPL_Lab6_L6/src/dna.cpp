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
    std::vector<Nucleotide> v = dna_.down_chain;
    for(int i=0; i< size1_2 ; i++){
        x= v[i];
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}

DNA::DNA(GeneSeq& S1, GeneSeq& S2): GeneSeq( S1.get_sequence() ), down_chain(S2.get_sequence()) {}

DNA::DNA(std::vector< Nucleotide > A, std::vector< Nucleotide > B): GeneSeq( A ), down_chain(B) {}


// DNA::DNA(): GeneSeq( S1.get_sequence() ){
//     int size1_2 = S1.get_sequence().size();
//     std::vector< Nucleotide > sec_ch = S2.get_sequence();
//     for(int i=0; i< size1_2 ; i++)
//         chain.push_back(sec_ch[i]);
// }

std::vector< Nucleotide > DNA::operator[](int a) const{
    if(a == 0){
        return chain;
    }
    else{
        return down_chain;
    }
    
}