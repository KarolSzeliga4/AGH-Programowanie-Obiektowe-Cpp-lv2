#include "board.h"

Board::Board(int x, int y, int p): _sizex(x), _sizey(y), _ilosc(p) {}

Board::~Board(){}

int Board::get_geometry(int) const{
	std::cout<<"przeladuj get_geometry!";
	return 0;
}
double Board::get_params(int) const{
	std::cout<<"przeladuj get_params!";
	return 0.;
}