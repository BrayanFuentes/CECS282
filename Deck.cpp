#include "Deck.h"
#include "Card.h"

Deck::Deck()
{
	top = 0;

}

Card Deck::deal()
{
	return storage[top++];
}

void Deck::shuffle()
{

}

void Deck::display()
{

}

int Deck::CardsLeft()
{

}
