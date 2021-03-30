#pragma once
#include "board.h"
#include <iostream>

class Game
{
public:
	Game();
	virtual ~Game(); // potrzebny virtualny przez użycie wskaźnika polimorficznego
	void new_player(std::string);
	
	virtual void new_board(const Board&)=0; // czysto virtualne funkcje, przymus przeładowania
	virtual void print_board()=0;
	virtual bool operator()(int,int)=0; 
private:
	std::string Nick;
};