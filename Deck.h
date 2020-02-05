#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h";

class Deck
{
private:
	int top;
	Card storage[52];
public:
	Deck();
	Card deal();
	void shuffle();
	void display();
	int CardsLeft();


};

#endif // !DECK_H
