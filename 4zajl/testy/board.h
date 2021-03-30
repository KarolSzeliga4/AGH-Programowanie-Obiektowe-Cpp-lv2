#pragma once
#include <iostream>

class Board
{
public:
	Board(int,int,int); // nieograniczone wymiary i parametr

	virtual ~Board();   // virtual wymusza działanie pochodnego destruktora przy: delete (&Board)   

	virtual int get_geometry(int) const; //   nie można zrobić =0 const;  
	virtual double get_params(int) const;//   więc w .cpp dodany cout zabezpieczający
protected:
	int _sizex; //nie mogą być private, bo używa ich SapperBoard
	int _sizey;
	int _ilosc;
};
