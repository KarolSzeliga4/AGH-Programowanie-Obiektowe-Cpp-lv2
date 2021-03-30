#include "game.h"
Game::Game(): Nick("Noname"){} 
							   // virtual Dtor potrzebny, bo w main występuje 
Game::~Game(){}                // delete (&Game) --> wykona się wtedy destruktor Sappera a nie Game
void Game::new_player(std::string N){ Nick = N;}