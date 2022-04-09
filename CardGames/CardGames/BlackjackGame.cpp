/*
    Name:	Michelle Apreza
    File:	BlackjackGame.cpp
    Date:	03/07/2020
    Class:	CIS 2220
*/

#include "Blackjack.h"
#include <iostream>

static double BlackjackGame(double bet)
{
    int choice = 0, nextCard = 0;

    // Create Blackjack object
    Blackjack b;
    b.setBet(bet);

    // Show hands
    std::cout << "\t\tDealer: " << b.getDealerCard1() << "   ?\n\n"
        << "\tYour hand: " << b.realCard(b.getPlayerCard1()) << "   " << b.realCard(b.getPlayerCard2()) << std::endl;

    // Check if dealer has an ace or 10 for a chance at immediate blackjack, else continue with the game
    if (((b.getDealerCard1() == 1) || (b.getDealerCard1() == 10)) && b.getDealerHand() == 21)
    {
        if (b.getPlayerHand() == 21)
        {
            std::cout << "\tThe dealer has a Blackjack! But so do you! It's a draw!" << std::endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            std::cout << "\nThe dealer has a Blackjack! You do not! You lose!" << std::endl;
            system("PAUSE");
            return (-1 * b.getBet());
        }
    }

    // Ask player what value they want their ace to be if any are present
    if ((b.getPlayerCard1() == 1) && (b.getPlayerCard2() == 1))
    {
        std::cout << "\nYou have a Aces! Do you want the first to be worth 1 or 11? ";
        std::cin >> choice;
        while ((choice != 1) && (choice != 11))
        {
            std::cout << "Enter a valid choice: ";
            std::cin >> choice;
        }
        if (choice == 1)
            b.fixPlayerHand();

        std::cout << "What about the second (1 or 11)? ";
        std::cin >> choice;
        while ((choice != 1) && (choice != 11))
        {
            std::cout << "Enter a valid choice: ";
            std::cin >> choice;
        }
        if (choice == 1)
            b.fixPlayerHand();
        if (b.getPlayerHand() > 21)
        {
            std::cout << "Bust! You lose!" << std::endl;
            system("PAUSE");
            return (-1 * b.getBet());
        }
    }
    else if ((b.getPlayerCard1() == 1) || (b.getPlayerCard2() == 1))
    {
        std::cout << "\nYou have an Ace! Do you want it to be worth 1 or 11? ";
        std::cin >> choice;
        while ((choice != 1) && (choice != 11))
        {
            std::cout << "Enter a valid choice: ";
            std::cin >> choice;
        }
        if (choice == 1)
            b.fixPlayerHand();
    }

    // Ask player if they wish to surrender
    std::cout << "\nDo you wish to surrender (1/2 of your bet is lost) (1 for Yes, 2 for No)? ";
    std::cin >> choice;
    while ((choice != 1) && (choice != 2))
    {
        std::cout << "Enter a valid number: ";
        std::cin >> choice;
    }
    if (choice == 1)
    {
        b.setBet(b.getBet() / 2);
        std::cout << "You have lost half of your bet." << std::endl;
        system("PAUSE");
        return -999;
    }
    
    do
    {
        system("CLS");
        // Show hands
        std::cout << "\t\tDealer: " << b.getDealerCard1() << "   ?\n\n"
            << "\tYour hand total: " << b.getPlayerHand() << std::endl << std::endl;
        std::cout << "1. Hit (take another card)\n" 
            << "2. Stand (take no more cards)\n" 
            << "Enter your choice: ";
        std::cin >> choice;
        while ((choice != 1) && (choice != 2))
        {
            std::cout << "Enter a valid choice: ";
            std::cin >> choice;
        }
        if (choice == 1)
        {
            nextCard = b.getCard();
            std::cout << "You got a(n) ";
            if (nextCard == 1)
            {
                std::cout << "Ace. Do you wish it to be worth 1 or 11? ";
                std::cin >> choice;
                while ((choice != 1) && (choice != 11))
                {
                    std::cout << "Enter a valid number (1 or 11): ";
                    std::cin >> choice;
                }
                b.addToPlayerHand(choice);
            }
            else if ((nextCard == 11) || (nextCard == 12) || (nextCard == 13))
            {
                std::cout << b.realCard(nextCard) << ".\n";
                b.addToPlayerHand(10);
            }
            else
                std::cout << nextCard;
            b.addToPlayerHand(nextCard);
        }

        // Check if player busts
        if (b.getPlayerHand() > 21)
        {
            std::cout << "Bust! You lose!";
            system("PAUSE");
            return (-1 * b.getBet());
        }
    } while (choice != 2);

    // Turn over dealer's second card
    system("CLS");
    std::cout << "\t\tDealer: " << b.realCard(b.getDealerCard1()) << " " << b.realCard(b.getDealerCard2()) << std::endl;
    std::cout << "\n\n\tYour hand total: " << b.getPlayerHand() << std::endl << std::endl;

    if (b.getDealerHand() < 17)
    {
        nextCard = b.getCard();
        if ((b.getDealerHand() < 11) && (nextCard == 1))
            nextCard = 11;
        else if (nextCard > 10)
            nextCard = 10;
        b.addToDealerHand(nextCard);
        std::cout << "The dealer's hand is less than 17!"
            << "The dealer drew a card and now has the total of "<< b.getDealerHand() << std::endl;
    }

    // Determine outcome
    switch (b.compare(b.getPlayerHand(), b.getDealerHand()))
    {
        case 0:
            return 0;
        case 1:
            return b.getBet();
        case 2:
            return b.getBet();
        case -1:
            return (-1 * b.getBet());
    }
}