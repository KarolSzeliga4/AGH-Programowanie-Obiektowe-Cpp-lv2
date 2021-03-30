 #include "vector.h"



using namespace MyStuff;

vector::vector(unsigned s): siz(s), tab(new int[s])
{
	for(int a = 0; a < siz ; a++)
	{
		tab[a] = 0;
	}
}

vector::vector(const vector& C)
{
	siz = C.siz;
	tab = new int[siz];
	for(int a = 0; a < siz ; a++)
	{
		tab[a] = C.tab[a];
	}
}

vector::~vector()
{
	delete[] tab;
}

vector& vector::operator=(const vector& C)
{
	delete[] tab;
	siz = C.siz;
	tab = new int[siz];
	for(int a = 0; a < siz ; a++)
	{
		tab[a] = C.tab[a];
	}
	return *this;
}

int& vector::operator[](unsigned a)
{
	return tab[a];
}

int vector::size()
{
	return siz;
}

ostream& operator<<(ostream& o, MyStuff::vector& v)
{
	for (int i = 0; i < v.size(); ++i)
		{
			o<<v[i]<<" ";
		}
		return o;
}

void vector::push_back(int a)
{
	vector C = *this;
	delete[] tab;
	tab = new int[siz+1];
	for (int i = 0; i < siz; ++i)
	{
		tab[i]=C[i];
	}
	tab[siz] = a;
	siz++;
}

void vector::pop_back()
{
	vector C = *this;
	delete[] tab;
	siz--;
	tab = new int[siz];
	for (int i = 0; i < siz; ++i)
	{
		tab[i]=C[i];
	}
}
























// using namespace MyStuff;

// vector::vector(int s): siz(s), tab(new int[s]){ 
// for(int i =0; i<siz; i++){ 
// tab[i] = 0;} 
// }

// vector::vector(const vector &tocp){
//     siz = tocp.siz;
//     tab = new int[siz];
//     for(int i =0; i<siz; i++) 
//         tab[i] = tocp.tab[i];
// }

// vector::~vector(){
//     delete[] tab;
// }

// int& vector::operator[](int i){
//     return tab[i];
// }

// int vector::size(){
//     return siz;
// }

// std::ostream& operator<<(std::ostream &o , MyStuff::vector &toshow){
//     for(int i=0; i< toshow.siz ; i++)
//         o<< toshow.tab[i]<<" ";
    
//     return o;
// }

// vector& vector::operator=(const vector& A){
//     delete[] tab;
//     siz = A.siz;    
//     tab = new int[siz];
//     for(int i =0; i<siz; i++) 
//         tab[i] = A.tab[i];

//     return *this;   
// }

// void vector::push_back(int m){
//     MyStuff::vector P = *this;
    
//     delete[] tab;
//     siz++;
//     tab = new int[siz];

//     for(int i =0; i< siz-1 ; i++) 
//         tab[i] = P.tab[i];

//     tab[siz-1] = m;
// }  

// void vector::pop_back(int k){
//     MyStuff::vector P = *this;
    
//     delete[] tab;
//     siz = siz -k;
//     tab = new int[siz];

//     for(int i =0; i<siz; i++) 
//         tab[i] = P.tab[i];
// }

// void vector::pop_back(){
// int k=1;
//     vector P = *this;
    
//     delete[] tab;
//     siz = siz -k;
//     tab = new int[siz];

//     for(int i =0; i<siz; i++) 
//         tab[i] = P.tab[i];
// }
