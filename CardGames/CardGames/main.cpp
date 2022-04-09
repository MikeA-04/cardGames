/*
	Name:	Michelle Apreza
	File:	main.cpp
	Date:	02/10/2020
		Updated: 03/07/2020
	Class:	CIS 2220
*/

#include "Player.h"
#include "PlayerManager.h"
#include "BlackjackGame.cpp"
#include "HighLowGame.cpp"
#include <iostream>
#include <string>

int main()
{
	// Create PlayerManager to load file
	PlayerManager* instance = PlayerManager::getInstance();
	// Create int variables
	int choice, id, index = 0;
	double cred, bet, outcome;
	// Create string variable
	std::string user;
	// bool variable to see if user has selected a player
	bool haveCurrentPlayer = false;

	// Menu
	do
	{
		system("CLS");
		std::cout << "\tWelcome Manager.\n\n"
			<< " 1. Add a Player\n"
			<< " 2. Remove a Player\n"
			<< " 3. Modify a Players\n"
			<< " 4. List Players\n"
			<< " 5. Select a New Current Player\n"
			<< " 6. Show Current Player\n"
			<< " 7. Play Blackjack Hand\n"
			<< " 8. Play High - Low Hand\n"
			<< " 9. Exit\n"
			<< "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
			case 1:
			{
				system("CLS");
				std::cout << "Enter the username of the new player: ";
				std::cin >> user;
				std::cout << "Enter the credits of the new player: ";
				std::cin >> cred;
				instance->addUser(user, cred);
				break;
			}
			case 2:
			{
				system("CLS");
				std::cout << "Enter the ID number of the player you wish to remove: ";
				std::cin >> id;
				instance->removeUser(id);
				break;
			}
			case 3:
			{
				system("CLS");
				std::cout << "Enter the ID number of the player you wish to modify: ";
				std::cin >> id;
				instance->modifyUser(id);
				break;
			}
			case 4:
			{
				system("CLS");
				instance->listUsers();
				break;
			}
			case 5:
			{
				system("CLS");
				// Select new current player
				index = instance->selectNewPlayer();
				haveCurrentPlayer = true;
				break;
			}
			case 6:
			{
				system("CLS");
				if (haveCurrentPlayer == false)
				{
					std::cout << "Please select a player." << std::endl;
					break;
				}
				// Show current player
				instance->showPlayer();
				break;
			}
			case 7:
			{
				system("CLS");
				// Check to see if a player has been picked
				if (haveCurrentPlayer == false)
				{
					std::cout << "Please select a player." << std::endl;
					system("PAUSE");
					break;
				}
				// Check to see if there are any credits
				if (instance->returnCPCred() == 0)
				{
					std::cout << "You do not have enough credits to play. Please add more credits.\n";
					system("PAUSE");
				}
				else
				{
					std::cout << "The current player has " << instance->returnCPCred() << " credits.\n";
					do
					{
						std::cout << "Enter a valid bet: ";
						std::cin >> bet;
					} while ((bet <= 0) || (bet > instance->returnCPCred()));
					// Set appropriate number with function
					if (bet == instance->returnCPCred())
					{
						outcome = BlackjackGame(bet);
						if (outcome == -999)
						{
							instance->modifyRecord(index, 0, bet);
						}
						else
						{
							instance->modifyRecord(outcome, index, 0);
						}
					}
					else
					{
						outcome = BlackjackGame(bet);
						if (outcome == -999)
						{
							instance->modifyRecord(index, 1, bet);
						}
						else
						{
							instance->modifyRecord(outcome, index, 1);
						}
					}
				}
				break;
			}
			case 8:
			{
				system("CLS");
				// Check to see if a player has been picked
				if (haveCurrentPlayer == false)
				{
					std::cout << "Please select a player." << std::endl;
					system("PAUSE");
					break;
				}
				// Check to see if there are any credits
				if (instance->returnCPCred() == 0)
				{
					std::cout << "You do not have enough credits to play. Please add more credits.\n";
					system("PAUSE");
				}
				else
				{
					std::cout << "The current player has " << instance->returnCPCred() << " credits.\n";
					do
					{
						std::cout << "Enter a valid bet: ";
						std::cin >> bet;
					} while ((bet <= 0) || (bet > instance->returnCPCred()));
					// Set appropriate number with function
					if (bet == instance->returnCPCred())
						instance->modifyRecord(HighLowGame(bet), index, 0);
					else
						instance->modifyRecord(HighLowGame(bet), index, 1);
				}
				break;
			}
			case 9:
				break;
			default:
			{
				std::cout << "Enter a valid number." << std::endl;
				break;
			}
		}
		system("PAUSE");
	} while (choice != 9);
	return 0;
}