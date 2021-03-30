#include "board.h"
#include "matrix.h"
#include "game.h"
#include <iostream>

using namespace MyStuff;

class Sapper: public Game
{
public:
	Sapper();
	~Sapper();
	void new_board(const Board&); 
	void print_board();
	bool operator()(int,int); 
private:
	matrix *_plansza; //używam new i delete
					  // jaki sposób jest najbardziej odpowiedni?
	
	//lepiej sie pozbyć tych składników?
	int _x;	  // lepszy: friend i możliwość czytania rozmiarów _planszy?, dodanie get_x() get_y() w matrixie? 
	int _y;   // czy branie zmiennych z board za pomocą friend Sapper? 
	int _ileBomb;
	
	int _shoots; //zmienna do wykrycia wygranej
};
