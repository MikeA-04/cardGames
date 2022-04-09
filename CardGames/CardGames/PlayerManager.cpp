/*
	Name:	Michelle Apreza
	File:	PlayerManager.cpp
	Date:	02/10/2020
		Updated: 03/02/2020
	Class:	CIS 2220
*/

#include "PlayerManager.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>

PlayerManager* PlayerManager::Instance(nullptr);

PlayerManager::PlayerManager()
{
	// create variables
	std::string user;
	int id;
	double creds;
	int win, loss;
	// open file and read
	std::ifstream playersFile;
	playersFile.open("PlayerList.txt");
	if (playersFile.fail())
	{
		std::cout << "File Opening Error. Please Try Again." << std::endl;
		exit(1);
	}
	else
	{
		while (playersFile >> user >> id >> creds >> win >> loss)
			players.push_back(new Player(user, id, creds, win, loss));
		playersFile.close();
	}
}

// return pointer to PlayerManager
PlayerManager* PlayerManager::getInstance()
{
	if (Instance == nullptr)
	{
		Instance = new PlayerManager();
	}
	return Instance;
}

void PlayerManager::addUser(const std::string &user, double creds)
{
	// generate ID
	int idNum;
	bool unique;
	do
	{
		unique = true;
		idNum = (rand() % 9000) + 1000;
		for (unsigned int i = 0; i < players.size(); ++i)
			if (players[i]->getID() == idNum)
				unique = false;
	} while (unique == false);
	// Add new player to "players" vector
	players.push_back(new Player(user, idNum, creds, 0, 0));
	// Open file and add user
	std::ofstream file;
	file.open("PlayerList.txt", std::ios_base::app);
	if (file.fail())
	{
		std::cout << "File Opening Error. Please Try Again." << std::endl;
		exit(1);
	}
	else
		file << user << " " << idNum << " " << creds << " " << 0 << " " << 0 << std::endl;
	file.close();
	std::cout << "User Successfully Added.\n";
}

void PlayerManager::listUsers()
{
	std::cout << std::left << std::setw(20) << "Username" << "ID Number\tCredits\t  Wins\t Losses" << std::endl;
	for (unsigned int m = 0; m < players.size(); ++m)
	{
		std::cout << std::left << std::setw(20) << players[m]->getUsername()
			<< players[m]->getID() << "\t"
			<< players[m]->getCredits() << "\t  "
			<< players[m]->getWins() << "\t "
			<< players[m]->getLosses() <<  std::endl;
	}
}

void PlayerManager::removeUser(int id)
{
	int index = -1;
	for (unsigned int k = 0; k < players.size(); ++k)
	{
		if (players[k]->getID() == id)
			index = k;
	}
	if (index == -1)
		std::cout << "A user with the ID: " << id << " was not found. Please try again." << std::endl;
	else
	{
		players.erase(players.begin() + index);
		// Modify file
		modifyFile();
		std::cout << "Player successfully removed.\n";
	}
}

void PlayerManager::modifyUser(int id)
{
	int index = -1, choice;
	double creds;
	std::string user;
	for (unsigned int k = 0; k < players.size(); ++k)
	{
		if (players[k]->getID() == id)
			index = k;
	}
	if (index == -1)
		std::cout << "A user with the ID: " << id << " was not found. Please try again." << std::endl;
	else
	{
		std::cout << "Would you like to modify the username or credits available?\n" 
			<< " 1. Username\n" 
			<< " 2. Credits\n"
			<< "Enter your choice: ";
		std::cin >> choice;
		while ((choice != 1) && (choice != 2))
		{
			std::cout << "Enter a valid number: ";
			std::cin >> choice;
		}
		switch (choice)
		{
			case 1:
			{
				std::cout << "Enter the new username of the player: ";
				std::cin >> user;
				players[index]->setUsername(user);
				break;
			}
			case 2:
			{
				std::cout << "Enter the amount of credits of the player: ";
				std::cin >> creds;
				players[index]->setCredits(creds);
				break;
			}
		}

		// Modify file
		modifyFile();
		std::cout << "Player successfully modified.\n";
	}
}

void PlayerManager::showPlayer()
{
	std::cout << "Current Player:\n" << " Username: " << currentP.getUsername() << std::endl;
	std::cout << " ID Number: " << currentP.getID() << std::endl;	
	std::cout << " Credits: " << currentP.getCredits() << std::endl;
	std::cout << " Wins: " << currentP.getWins() << std::endl;
	std::cout << " Losses: " << currentP.getLosses() << std::endl;
}

int PlayerManager::selectNewPlayer()
{
	static int choice;
	std::cout << "Which player would you like to select? (Enter corresponding number): " << std::endl;
	std::cout << "   Username\t\tID" << std::endl;
	for (unsigned int k = 0; k < players.size(); ++k)
		std::cout << k + 1 << ". " << players[k]->getUsername() << "\t\t" << players[k]->getID() << std::endl;
	do 
	{
		std::cin >> choice;
	} while ((choice < 1) && (choice > players.size()));
	--choice;
	currentP.setUsername(players[choice]->getUsername());
	currentP.setID(players[choice]->getID());
	currentP.setCredits(players[choice]->getCredits());
	currentP.setWins(players[choice]->getWins());
	currentP.setLosses(players[choice]->getLosses());
	return choice;
}

void PlayerManager::modifyRecord(double outcome, int index, int specificUpdate)
{
	if (outcome == 0)
	{
		// 0 is a draw so nothing occurs (not even the credits are modified)
	}
	else if (outcome > 0)
	{
		// Update wins in currentP object
		currentP.setWins(currentP.getWins() + 1);
		// Update wins in players vector
		players[index]->setWins(currentP.getWins());
		// If specificUpdate == 1 then it means that the bet was NOT all of the available credits
		if (specificUpdate == 1)
		{
			// Update credits in currentP object
			currentP.fixCredits(outcome);
			// Update credits in players vector
			players[index]->fixCredits(outcome);
		}
		else
		{
			// Update credits in currentP object
			currentP.setCredits(outcome);
			// Update credits in players vector
			players[index]->setCredits(outcome);
		}
		// Modify file
		modifyFile();
	}
	else
	{
		// Update losses in currentP object
		currentP.setLosses(currentP.getLosses() + 1);
		// Update losses in players vector
		players[index]->setLosses(currentP.getLosses());
		// If specificUpdate == 1 then it means that the bet was NOT all of the available credits
		if (specificUpdate == 1)
		{
			// Update credits in currentP object
			currentP.fixCredits(outcome);
			// Update credits in players vector
			players[index]->fixCredits(outcome);
		}
		else
		{
			// Update credits in currentP object				
			currentP.setCredits(0);
			// Update credits in players vector
			players[index]->setCredits(0);
		}
		// Modify file
		modifyFile();
	}
}

void PlayerManager::modifyRecord(int index, int specificUpdate, double bet)
{
	// If user did NOT bet all of their credits
	if (specificUpdate == 1)
	{
		static double newCredits;
		newCredits = -(bet / 2);
		currentP.fixCredits(newCredits);
		players[index]->fixCredits(newCredits);
	}
	else
	{
		currentP.setCredits(bet / 2);
		players[index]->setCredits(currentP.getCredits());
	}
	// Modfy file
	modifyFile();
}

double PlayerManager::returnCPCred()
{ return currentP.getCredits(); }

void PlayerManager::modifyFile()
{
	std::ofstream file;
	file.open("PlayerList.txt");
	if (file.fail())
	{
		std::cout << "File Opening Error. Please Try Again." << std::endl;
		exit(1);
	}
	else
	{
		Player* ptr;
		for (unsigned int t = 0; t < players.size(); ++t)
		{
			ptr = players.at(t);
			file << ptr->getUsername() << " " << ptr->getID() << " " << ptr->getCredits()
				<< " " << ptr->getWins() << " " << ptr->getLosses() << std::endl;
		}
		file.close();
		std::cout << "Player successfully modified.\n";
	}
}
