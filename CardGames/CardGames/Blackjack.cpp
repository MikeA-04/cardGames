/*
	Name:	Michelle Apreza
	File:	Blackjack.cpp
	Date:	03/07/2020
	Class:	CIS 2220
*/

#include "Blackjack.h"
#include <iostream>

Blackjack::Blackjack()
{
	// Give dealer and player 2 cards each
	dealerCard1 = getCard();
	dealerCard2 = getCard();
	playerCard1 = getCard();
	playerCard2 = getCard();
	// sum hands
	if ((dealerCard1 + dealerCard2) == 2)
		dealerHand = 12;
	else if (dealerCard1 == 1)
		dealerHand += 11;
	else if (dealerCard2 == 1)
		dealerHand += 11;
	if (dealerCard1 > 10)
		dealerHand += 10;
	if (dealerCard2 > 10)
		dealerHand += 10;
	if ((dealerCard1 > 1) && (dealerCard1 < 11))
		dealerHand += dealerCard1;
	if ((dealerCard2 > 1) && (dealerCard2 < 11))
		dealerHand += dealerCard2;

	if (playerCard1 == 1)
		playerHand += 11;
	if (playerCard2 == 1)
		playerHand += 11;
	if (playerCard1 > 10)
		playerHand += 10;
	if (playerCard2 > 10)
		playerHand += 10;
	if ((playerCard1 > 1) && (playerCard1 < 11))
		playerHand += playerCard1;
	if ((playerCard2 > 1) && (playerCard2 < 11))
		playerHand += playerCard2;
}

int Blackjack::getDealerCard1()
{ return dealerCard1; }

int Blackjack::getDealerCard2()
{ return dealerCard2; }

int Blackjack::getPlayerCard1()
{ return playerCard1; }

void Blackjack::fixPlayerHand()
{ playerHand -= 10; }

int Blackjack::getPlayerCard2()
{ return playerCard2; }

int Blackjack::getDealerHand()
{ return dealerHand; }

void Blackjack::addToDealerHand(int value)
{ dealerHand += value; }

int Blackjack::getPlayerHand()
{ return playerHand; }

void Blackjack::addToPlayerHand(int value)
{ playerHand += value; }

int Blackjack::compare(int playerH, int dealerH)
{
	// Determine outcome
	if (dealerH > 21)
	{
		std::cout << "The dealers busts! You win!" << std::endl;
		system("PAUSE");
		return 1;
	}
	else if (dealerH == playerH)
	{
		std::cout << "You both have equal hands! It's a draw!" << std::endl;
		system("PAUSE");
		return 0;
	}
	else if (dealerH < playerH)
	{
		std::cout << "Your hand is closer to 21! You win!" << std::endl;
		system("PAUSE");
		return 2;
	}
	else if (dealerH > playerH)
	{
		std::cout << "The dealer's hand is closer to 21! You lose!" << std::endl;
		system("PAUSE");
		return -1;
	}
}
