/*
	Name:	Michelle Apreza
	File:	Player.cpp
	Date:	02/10/2020
		Updated: 03/02/2020
	Class:	CIS 2220
*/

#include "Player.h"
#include <iostream>
#include <string>

// constructors
Player::Player() :username(" "), IDnumber(0), credits(0), wins(0), losses(0)
{ /* Nothing */ }

Player::Player(const std::string &user, int id, double creds, int win, int loss) : 
	username(user), IDnumber(id), credits(creds), wins(win), losses(loss) 
{ /* Nothing */ }

// member functions
void Player::setUsername(const std::string &user)
{ username = user; }

void Player::setID(int id)
{ IDnumber = id; }

void Player::setCredits(double cred)
{ credits = cred; }

void Player::fixCredits(double cred)
{ credits += cred; }

void Player::setWins(int w)
{ wins = w; }

void Player::setLosses(int l)
{ losses = l; }

std::string Player::getUsername()
{ return username; }

int Player::getID()
{ return IDnumber; }

double Player::getCredits()
{ return credits; }

int Player::getWins()
{ return wins; }

int Player::getLosses()
{ return losses; }