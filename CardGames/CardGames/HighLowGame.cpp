/*
    Name:	Michelle Apreza
    File:	HighLowGame.cpp
    Date:	03/07/2020
    Class:	CIS 2220
*/

#include <iostream>
#include "HighLow.h"

static double HighLowGame(double bet)
{
    int choice;
    char hORl = 'h';
    
    // create HighLow object
    HighLow HL(bet);

    // loop for game
    while (true)
    {
        system("CLS");
        // Display player's current card
        std::cout << "Your card: " << HL.realCard(HL.getCurrentCard()) << std::endl;

        // Let user bet or quit
        std::cout << std::endl
            << "Do you bet:\n 1. High (" << HL.getMultiplier('h') << ")\n"
            << " 2. Low (" << HL.getMultiplier('l') << ")\n"
            << " 3. Quit\n" 
            << " Enter your choice: ";
        std::cin >> choice;

        // pull out next card
        HL.setNextCard(HL.getCard());
        std::cout << "The next card: " << HL.realCard(HL.getNextCard()) << std::endl;

        switch (choice)
        {
            // High bet
            case 1:
            {
                if (HL.compare(HL.getCurrentCard(), HL.getNextCard()) == 0)
                {
                    std::cout << "You win!" << std::endl;
                    HL.setPay(HL.getMultiplier('h'));
                    // Set the current card to nextCard if appropriate else get appropriate card
                    if ((HL.getNextCard() != 1) && (HL.getNextCard() != 13))
                        HL.setCurrentCard(HL.getNextCard());
                    else
                    {
                        do
                        {
                            HL.setCurrentCard(HL.getCard());
                        } while ((HL.getCurrentCard() == 1) || (HL.getCurrentCard() == 13));
                    }
                }
                else if (HL.compare(HL.getCurrentCard(), HL.getNextCard()) == -1)
                    std::cout << "It's a draw!" << std::endl;
                else
                {
                    std::cout << "You lost!" << std::endl;
                    system("PAUSE");
                    return (-1 * HL.getBet());
                }
                system("PAUSE");
                break;
            }
            // Low bet
            case 2:
            {
                if (HL.compare(HL.getCurrentCard(), HL.getNextCard()) == 1)
                {
                    std::cout << "You win!" << std::endl;
                    HL.setPay(HL.getMultiplier('l'));
                    // Set the current card to nextCard if appropriate else get appropriate card
                    if ((HL.getNextCard() != 1) && (HL.getNextCard() != 13))
                        HL.setCurrentCard(HL.getNextCard());
                    else
                    {
                        do
                        {
                            HL.setCurrentCard(HL.getCard());
                        } while ((HL.getCurrentCard() == 1) || (HL.getCurrentCard() == 13));
                    }
                }
                else if (HL.compare(HL.getCurrentCard(), HL.getNextCard()) == -1)
                    std::cout << "It's a draw!" << std::endl;
                else
                {
                    std::cout << "You lost!" << std::endl;
                    system("PAUSE");
                    return (-1 * HL.getBet());
                }
                system("PAUSE");
                break;
            }
            // Quit
            case 3:
            {
                system("CLS");
                std::cout << "You won! Your pay is " << HL.getPay() << std::endl;
                return HL.getPay();
            }
            default:
            {
                std::cout << "Enter a valid choice.\n";
                system("PAUSE");
                break;
            }
        }

    }
}