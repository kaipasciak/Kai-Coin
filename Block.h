//
// Created by Kai Pasciak on 12/23/23.
//

#ifndef KAICOIN_BLOCK_H
#define KAICOIN_BLOCK_H

#include "Transaction.h"
#include <vector>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class Block {
private:
    string prevHash;
    string hash;
    uint32_t timestamp;
    int nonce;

public:
    vector<Transaction> transactions;

    Block();

    Block(string prevHash,vector<Transaction> transactions);

    string getPreviousHash();

    void setHash(string hash);

    void addTransaction(string transaction);

    string toString();
};


#endif //KAICOIN_BLOCK_H
