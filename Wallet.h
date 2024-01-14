//
// Created by Kai Pasciak on 12/23/23.
//

#ifndef KAICOIN_WALLET_H
#define KAICOIN_WALLET_H

#include <string>
using namespace std;

class Wallet {
private:
    string address;
    double balance;
    double MIN_BALANCE = 0;

public:
    Wallet(string address, double balance);

    double getBalance();

    void setBalance(double change);

    string getAddress();
};


#endif //KAICOIN_WALLET_H
