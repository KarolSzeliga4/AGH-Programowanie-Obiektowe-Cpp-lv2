#include "virus.h"

Virus::Virus(const char* N): imie(N), wrna(nullptr), wiek(0){}

Virus::~Virus(){
    if(wrna)
        delete wrna;
}

Virus::Virus(Virus&& A){
	//std::cout<<"konst\n";
    imie = std::move(A.imie);
    wrna = std::move(A.wrna);
    wiek = std::move(A.wiek);
}
Virus::Virus( Virus& A){ //bez const
    imie = A.imie;
    if(A.wrna)
        wrna = new GeneSeq( A.wrna->get_sequence() );
    else        wrna = nullptr;
    wiek = 0;
    
    A.wiek++; //zwiększam wiek kopiowanego dlatego bez const 
}

Virus& Virus::operator=(Virus&& A){
    if(this != &A)
        return *this;
    //std::cout<<"opVirus=przen.\n";
    if(wrna != nullptr)
        delete wrna;
    
    std::swap(A.imie,imie);
    std::swap(A.wrna,wrna);
    std::swap(A.wiek,wiek);
    return *this;
}

Virus& Virus::operator=(const Virus& A){
    if(this != &A)
        return *this;
//std::cout<<"opVirus=kopiow.\n";
    if(wrna)
        delete wrna;

    imie = A.imie;
    if(A.wrna)
        wrna = new GeneSeq( A.wrna->get_sequence() );
    wiek = 0;

    return *this;

}

void Virus::set_RNA(const std::vector<Nucleotide> V ){
    wrna = new GeneSeq(V);
}

std::string Virus::get_name()const{
    return imie;
}

GeneSeq* Virus::get_RNA()const{
    return wrna;
}

int& Virus::get_age(){
    return wiek;
}