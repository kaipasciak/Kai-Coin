//
// Created by Kai Pasciak on 12/23/23.
//

#ifndef KAICOIN_BLOCKCHAIN_H
#define KAICOIN_BLOCKCHAIN_H

#include "Block.h"
#include "Node.h"
#include "Wallet.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Node;

class Blockchain {
private:
    int difficulty;

    vector<Transaction> mempool;
    vector<Block> chain;
    Block nextBlock;
    int NUM_BLOCK_TRANSACTIONS = 3;

public:
    vector<Node*> nodes;

    vector<Wallet> wallets;

    Blockchain();

    void addNode(string address);

    void addWallet(string address, double balance);

    void addTransaction(string sender, string recipient, double amount);

    void addBlock();

    Block getLastBlock();

    void setNextBlock();

    Block getNextBlock();

    // void updateDifficulty();

    int getLength();

    bool runNodes();


};


#endif //KAICOIN_BLOCKCHAIN_H
