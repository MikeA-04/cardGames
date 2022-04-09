/*
	Name:	Michelle Apreza
	File:	HighLow.h
	Date:	03/07/2020
	Class:	CIS 2220
*/

#pragma once
#include "CardGame.h"

class HighLow : public CardGame
{
	// private member variables
	private:
		int currentCard = 0;
		int nextCard = 0;
		int pay = 0;
		double pays[13][2] = 
		{{1.0, 1.0}, {10.7, 1.1}, {5.3, 1.1}, 
		{3.5, 1.1}, {2.6, 1.3}, {2.1, 1.5}, 
		{1.87, 1.87}, {1.5, 2.1}, {1.3, 2.6},
		{1.1, 3.5}, {1.1, 5.3}, {1.1, 10.7}, {1.0, 1.0}};
	public:
		// constructor
		HighLow(double bet);
		// member functions
		void setCurrentCard(int card);
		int getCurrentCard();
		void setNextCard(int card);
		int getNextCard();
		void setPay(double multiplier);
		int getPay();
		// get appropriate multiplier
		double getMultiplier(char type);
		virtual int compare(int current, int next) override;
};