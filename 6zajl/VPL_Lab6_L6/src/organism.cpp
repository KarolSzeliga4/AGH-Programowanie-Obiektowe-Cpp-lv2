#include "organism.h"

Organism::Organism(const char* A, DNA D): name(A), kod(D) {}

std::string Organism::get_name() const{
    return name;
}

DNA Organism::get_dna() const{
   return kod;     
}

void Organism::operator<<(const Virus& A){
    int a = rand()%2;
    int siz = kod.get_sequence().size();
    
    int start = rand()% siz;
    int vsiz = A.get_RNA()->get_sequence().size();
    for( int i = start ; i < start+vsiz ; i++){
        if(i < siz){
            if(a) kod.set_chain(0)[i] = A.get_RNA()->get_sequence()[i-start]; 
            else  kod.set_chain(1)[i] = A.get_RNA()->get_sequence()[i-start]; 
        }
        else{
            if(a) kod.set_chain(0)[i-siz] = A.get_RNA()->get_sequence()[i-start]; 
            else  kod.set_chain(1)[i-siz] = A.get_RNA()->get_sequence()[i-start]; 
        }
    }
}