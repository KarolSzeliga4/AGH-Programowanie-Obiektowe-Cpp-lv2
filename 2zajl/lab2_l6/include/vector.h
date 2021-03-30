#pragma once 
#include<iostream>

using namespace std;

namespace MyStuff {
 class vector;
 }
 	ostream& operator<<(ostream &, MyStuff::vector &);

namespace MyStuff 
{
	class vector
	{
		private:
			int siz;
			int *tab;
		public:
			vector(unsigned a);
			vector(const vector&);
			~vector();
			vector& operator=(const vector& C);
			int& operator[](unsigned);
			int size();
			void push_back(int );
			void pop_back();
			friend ostream& ::operator<<(ostream& o, MyStuff::vector&);
	};

}




























// namespace MyStuff {
// class vector;
// }
// 	std::ostream& operator<<(std::ostream &, MyStuff::vector &);

// namespace MyStuff {
// class vector { 
// public: 
// 		friend std::ostream & ::operator<<(std::ostream &o, MyStuff::vector &toshow);
// 		vector(int );
// 		vector(const vector &);
// 		~vector();
// 		int& operator[](int );
// 		int size();
// 		vector& operator=(const vector&);
//         void push_back(int ); 
//         void pop_back(int ); 
//         void pop_back(); 
// private:
// 	int siz;
// 	int *tab;
// };
// }
