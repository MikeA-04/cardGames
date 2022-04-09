/*
    Name:	Michelle Apreza
    File:	PlayerManager.h
    Date:	02/10/2020
        Updated: 03/06/2020
    Class:	CIS 2220
*/

#include <vector>
#include "Player.h"
#pragma once

// Singleton Design
class PlayerManager
{
    // private member variables and methods
    private:
        std::vector<Player*> players;
        Player currentP;
        void modifyFile();
        // pointer to PlayerManager object
        static PlayerManager* Instance;
        // constructor
        PlayerManager();
    // public member functions
    public:
        // returns pointer to PlayerManager object
        static PlayerManager* getInstance();
        // member functions
        void addUser(const std::string &user, double creds);
        void removeUser(int id);
        void listUsers();
        void modifyUser(int id);
        void showPlayer();
        int selectNewPlayer();
        void modifyRecord(double outcome, int index, int specificUpdate);
        void modifyRecord(int index, int specificUpdate, double bet);
        double returnCPCred();
};