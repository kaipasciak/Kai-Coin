//
// Created by Kai Pasciak on 12/23/23.
//

#ifndef KAICOIN_TRANSACTION_H
#define KAICOIN_TRANSACTION_H

#include "Wallet.h"
#include <string>
#include <sstream>
using namespace std;

class Transaction {
private:
    string sender;
    string recipient;
    double amount;
    bool confirmed;

public:
    Transaction();

    Transaction(string sender, string recipient, double amount);

    string getSender();

    string getRecipient();

    double getAmount();

    void confirm();

    string toString();
};


#endif //KAICOIN_TRANSACTION_H
