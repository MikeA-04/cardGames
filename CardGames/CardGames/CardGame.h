/*
	Name:	Michelle Apreza
	File:	CardGame.h
	Date:	03/07/2020
	Class:	CIS 2220
*/

#pragma once
#include <string>

class CardGame
{
	// private
	private:
		// hold player's bet
		double bet = 0.0;
	// public
	public:
		// sets and returns player's bet
		void setBet(double b);
		double getBet();
		// return random number between 1 and 13
		int getCard();
		// returns what string to print out (for cards)
		std::string realCard(int card);
		// compares cards and returns a number (children will redefine and appropriate action will be carried out)
		virtual int compare(int card1, int card2);
};