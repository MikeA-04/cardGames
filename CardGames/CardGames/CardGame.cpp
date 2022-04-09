/*
    Name:	Michelle Apreza
    File:	CardGame.cpp
    Date:	03/07/2020
    Class:	CIS 2220
*/

#include "CardGame.h"
#include <stdlib.h>

void CardGame::setBet(double b)
{ bet = b; }

double CardGame::getBet()
{ return bet; }

int CardGame::getCard()
{
	static int card;
	card = (rand() % 13) + 1;
	return card;
}

std::string CardGame::realCard(int card)
{
    switch (card)
    {
      case 1:
        return "A";
      case 11:
        return "J";
      case 12:
        return "Q";
      case 13:
        return "K";
      default:
          return std::to_string(card);
    }
}

int CardGame::compare(int card1, int card2)
{
    if (card1 > card2)
        return 1;
    else if (card1 < card2)
        return 0;
    else
        return -1;
}