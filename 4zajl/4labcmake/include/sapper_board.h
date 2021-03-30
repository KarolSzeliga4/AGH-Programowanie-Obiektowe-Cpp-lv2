#pragma once
#include <iostream>
#include <board.h>


class SapperBoard: public Board
{
public:
	SapperBoard(int,int,int);
	~SapperBoard();
	int get_geometry(int) const; //przymusowo przeładowane metody Boarda
	double get_params(int) const;
};