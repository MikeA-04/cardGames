/*
	Name:	Michelle Apreza
	File:	Blackjack.h
	Date:	03/06/2020
	Class:	CIS 2220
*/

#pragma once
#include "CardGame.h"

class Blackjack : public CardGame
{
	private:
		int dealerCard1 = 0;
		int dealerCard2 = 0;
		int dealerHand = 0;
		int playerCard1 = 0;
		int playerCard2 = 0;
		int playerHand = 0;
	public:
		// constructor
		Blackjack();
		int getDealerCard1();
		int getDealerCard2();
		int getPlayerCard1();
		void fixPlayerHand();
		int getPlayerCard2();
		int getDealerHand();
		void addToDealerHand(int value);
		int getPlayerHand();
		void addToPlayerHand(int value);
		virtual int compare(int playerH, int dealerH) override;
};