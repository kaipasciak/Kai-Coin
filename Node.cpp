//
// Created by Kai Pasciak on 12/23/23.
//

#include "Node.h"
#include <iostream>

Node::Node(string address){
    balance = 0;
    chainLength = 0;
    nonce = 0;
    hash = "";
    this->address = address;
}

void Node::checkLength(vector<Block> blockchainCopy, Block nextBlock){
    int length = blockchainCopy.size();
    if (length > chainLength)
        updateBlock(nextBlock);
}

void Node::updateBlock(Block nextBlock){
    currentBlock = nextBlock;
}

void Node::setBalance(double change){
    balance += change;
}

string Node::getAddress(){
    return address;
}

double Node::getBalance(){
    return balance;
}

void Node::resetNonce(){
    nonce = 0;
}

int Node::getNonce(){
    return nonce;
}

bool Node::mineBlock(int difficulty){
    cout << "Node: mineblock. Difficulty: " << difficulty << endl;


    string blockString = currentBlock.toString();
    cout << "Node: blockString = " << blockString << endl;

    string blockHeader = "1 to " + address + blockString;
    cout << "Node: blockHeader = " << blockHeader << endl;


    string thisHash = sha256(blockHeader + to_string(nonce));
    cout << "Node: thisHash = " << thisHash << endl;

    hash = thisHash;
    int zeroes = 0;
    for (char ch : thisHash){
        if (ch == '0')
            zeroes++;
        else
            break;
    }
    if (zeroes >= difficulty) {
        return true;
    }
    else
        nonce++;
    return false;
}

string Node::sha256(const string& str){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.length());
    SHA256_Final(hash, &sha256);

    stringstream ss;

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ss << hex << setw(2) << setfill('0') << static_cast<int>( hash[i] );
    }

    return ss.str();
}

string Node::getHash(){
    return hash;
}