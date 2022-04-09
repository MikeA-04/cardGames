/*
	Name:	Michelle Apreza
	File:	Player.h
	Date:	02/10/2020
		Updated: 03/02/2020
	Class:	CIS 2220
*/

#include <string>
#pragma once

class Player
{
	// private member variables
	private:
		std::string username;
		int IDnumber;
		double credits;
		int wins;
		int losses;
	// public member functions
	public:
		// constructors
		Player();
		Player(const std::string &user, int id, double creds, int win, int loss);
		// setters
		void setUsername(const std::string &user);
		void setID(int id);
		void setCredits(double cred);
		void fixCredits(double cred);
		void setWins(int w);
		void setLosses(int l);
		// getters
		std::string getUsername();
		int getID();
		double getCredits();
		int getWins();
		int getLosses();
};