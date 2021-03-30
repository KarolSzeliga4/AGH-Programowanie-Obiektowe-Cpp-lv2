#include "vector.h"

using namespace MyStuff;

vector::vector(): siz(0), tab(nullptr){} // pusty wektor

vector::vector(int s): siz(s), tab(new int[s]){ 
for(int i =0; i<siz; i++) 
	tab[i] = 0;
}

vector::vector(const vector &tocp){
    siz = tocp.siz;
    if(tocp.tab == nullptr){
    	tab= nullptr; 
    	if(siz!=0)std::cout<<"ERRORcpCtor\n";
    }
    else{
    	tab = new int[siz];
    	for(int i =0; i<siz; i++) 
        	tab[i] = tocp.tab[i];
    }
}

vector::vector(vector &&tomv): siz(std::move(tomv.siz)), tab(std::__exchange(tomv.tab, nullptr)){}

vector::~vector(){
	if(tab != nullptr) delete[] tab;
}

int& vector::operator[](int i) const{
	if((i>=siz && i<0) || tab ==nullptr)
	{
		std::cout<<"ERROR_op[]\n";
	}
    return tab[i];
}

int vector::size() const{
	return siz;
}

std::ostream& operator<<(std::ostream &o ,const MyStuff::vector &toshow){
    for(int i=0; i< toshow.siz ; i++)
        o<< toshow.tab[i]<<" ";
    if(toshow.tab == nullptr){
    	o<<"<-pusty wektor!";
    }
    return o;
}

vector& vector::operator=(const vector& A){
	if(this == &A)
		return *this;
	if(tab != nullptr)
    	delete[] tab;

    siz = A.siz;
    if(A.tab == nullptr){
    	tab= nullptr; 
    	if(siz!=0)std::cout<<"FINDerror_op=\n";
    }
    else{
    	tab = new int[siz];
    	for(int i =0; i<siz; i++) 
        	tab[i] = A.tab[i];
    }

    return *this;   
}

vector& vector::operator=(vector &&A){ // nie koniecznie wiem co zrobić, żeby na pewno to on
	if(this == &A)                     // był użyty ...a nie kopiujący 
		return *this;
	if(tab != nullptr){
    	delete[] tab; siz = 0;
	}

	std::swap(siz, A.siz);
	std::swap(tab, A.tab); //przesuwa całą tablice (wektor)
	//std::cout<<"op=vec";  // nie jestem pewny dlaczego został wykorzystany
	return *this;
}

vector vector::operator+(const vector& A) const{
	if(tab == nullptr) return A;
	if(A.tab == nullptr)return *this;

	int min;
	vector Sum;
	if(siz<A.siz){ //ustalam mniejszy 
		min = siz;
		Sum = A;   // dla ustalenia wielkości i ostatnich wartości wektora
	}
	else{
		min = A.siz;
		Sum = *this;
	}
	for (int i = 0; i < min; ++i)
	{
		Sum[i] = tab[i] + A.tab[i]; //poprzednia wartośc nie ma znaczenia
	}
	return Sum;
}
void vector::push_back(int m){
	if(tab == nullptr){
		siz = 1;
		tab = new int[siz];
		tab[0]= m;
	}
	else{
    	vector P = *this;
    
    	delete[] tab;
    	siz++;
    	tab = new int[siz];

	    for(int i =0; i< siz-1 ; i++) 
    	    tab[i] = P.tab[i];

    	tab[siz-1] = m;
	}
}  

void vector::pop_back(int k = 1){ // zmniejsza wektor o k wymiarów
if(k <= 0){
	std::cout<<"błedne użycie!pop_back";
}
else{
	if(k>=siz){
		if(k>siz){
			std::cout<<"wektor_size: "<< siz <<", nie da sie zmniejszyć o tyle!";
		}
		else{// k ==siz, więc robimy pusty wektor
			delete[] tab;
    		siz = 0;
		}
	}
	else{
    	vector P = *this;
    
    	delete[] tab;
    	siz = siz -k;
    	tab = new int[siz];
    	for(int i =0; i<siz; i++) 
        	tab[i] = P.tab[i];
	}
}
}
