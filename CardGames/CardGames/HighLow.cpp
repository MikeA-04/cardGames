/*
	Name:	Michelle Apreza
	File:	HighLow.cpp
	Date:	03/07/2020
	Class:	CIS 2220
*/

#include "HighLow.h"

double HighLow::getMultiplier(char type)
{
	switch (currentCard)
	{
	case 2:
	{
		if (type == 'l')
			return pays[1][0];
		else
			return pays[1][1];
	}
	case 3:
	{
		if (type == 'l')
			return pays[2][0];
		else
			return pays[2][1];
	}
	case 4:
	{
		if (type == 'l')
			return pays[3][0];
		else
			return pays[3][1];
	}
	case 5:
	{
		if (type == 'l')
			return pays[4][0];
		else
			return pays[4][1];
	}
	case 6:
	{
		if (type == 'l')
			return pays[5][0];
		else
			return pays[5][1];
	}
	case 7:
	{
		if (type == 'l')
			return pays[6][0];
		else
			return pays[6][1];
	}
	case 8:
	{
		if (type == 'l')
			return pays[7][0];
		else
			return pays[7][1];
	}
	case 9:
	{
		if (type == 'l')
			return pays[8][0];
		else
			return pays[8][1];
	}
	case 10:
	{
		if (type == 'l')
			return pays[9][0];
		else
			return pays[9][1];
	}
	case 11:
	{
		if (type == 'l')
			return pays[10][0];
		else
			return pays[10][1];
	}
	case 12:
	{
		if (type == 'l')
			return pays[11][0];
		else
			return pays[11][1];
	}
	default:
		return 1.0;
	}
}

int HighLow::compare(int current, int next)
{
	if (current > next)
		return 1;
	else if (current < next)
		return 0;
	else
		return -1;
}

HighLow::HighLow(double bet)
{
	// get first card
	do
	{
		currentCard = getCard();
	} while ((currentCard == 1) || (currentCard == 13));
	// set pay = bet
	setBet(bet);
	pay = bet;
}

void HighLow::setCurrentCard(int card)
{ currentCard = card; }

int HighLow::getCurrentCard()
{ return currentCard; }

void HighLow::setNextCard(int card)
{ nextCard = card; }

int HighLow::getNextCard()
{ return nextCard; }

void HighLow::setPay(double multiplier)
{ pay *= multiplier; }

int HighLow::getPay()
{ return pay; }
