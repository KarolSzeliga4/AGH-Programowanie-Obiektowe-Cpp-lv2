#include "coronavirus.h"

CoronaVirus::CoronaVirus(const char* A, const char* Z, std::vector<Nucleotide> V): Virus(A), imieZ(Z) {
    wrna = new GeneSeq(V);
}

CoronaVirus::CoronaVirus(): Virus("Noname"), imieZ("Unknown"){}

CoronaVirus::CoronaVirus(CoronaVirus&& A): Virus(std::move(A)), imieZ( std::move(A.imieZ) ){std::cout<<"konstr.przen.\n";}

CoronaVirus::CoronaVirus(CoronaVirus& A): Virus(A), imieZ( A.imieZ ){std::cout<<"konstr.kp\n";} //zwiększanie wieku A w Ctorze Virus()

CoronaVirus::~CoronaVirus(){}

CoronaVirus& CoronaVirus::operator=(CoronaVirus&& A){
	// if(this != &A)
	// 	return *this;

	// if(wrna != nullptr)
	// 	delete wrna;
	
	// std::swap(A.imie,imie);
 //    std::swap(A.wrna,wrna);
 //    std::swap(A.wiek,wiek);
	std::cout<<"op=przen\n";
	(*this).Virus::operator=(A);
    std::swap(A.imieZ,imieZ);
    return *this;
}

CoronaVirus& CoronaVirus::operator=(CoronaVirus& A){
	// if(this != &A)
	// 	return *this;

	// if(wrna != nullptr)
	// 	delete wrna;

	// imie = A.imie;
 //    wrna = new GeneSeq( A.wrna->get_sequence() );
 //    wiek = 0;
	(*this).Virus::operator=(A);
    imieZ = A.imieZ;
    std::cout<<"op=kp\n";
    return *this;

}

std::string CoronaVirus::get_animal_host() const{
    return imieZ;
}