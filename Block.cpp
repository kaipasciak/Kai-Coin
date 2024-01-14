//
// Created by Kai Pasciak on 12/23/23.
//

#include "Block.h"

Block::Block(){
    this->prevHash = "0";
    this->timestamp = time(nullptr);
    this->nonce = 0;
    this->hash = "genesisBlock";
}


Block::Block(string prevHash, vector<Transaction> transactions){
    this->prevHash = prevHash;
    this->transactions = transactions;
    std::time_t currentTime = std::time(nullptr);
    timestamp = static_cast<uint32_t>(currentTime);
}

void Block::setHash(string hash){
    this->hash = hash;
}

string Block::getPreviousHash(){
    return prevHash;
}

string Block::toString(){
    stringstream ss;
    ss << prevHash << transactions[0].toString() << transactions[1].toString() << transactions[2].toString() << to_string(timestamp);
    return ss.str();
}