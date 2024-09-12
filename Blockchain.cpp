//
// Created by Kai Pasciak on 12/23/23.
//

#include "Blockchain.h"

Blockchain::Blockchain(){
    chain.emplace_back();
    difficulty = 2;
}

void Blockchain::addWallet(string address, double balance){
    wallets.emplace_back(address,balance);
}

void Blockchain::addNode(string address){
    nodes.emplace_back(new Node(address));
}

void Blockchain::addTransaction(string sender, string recipient, double amount){
    mempool.emplace_back(sender, recipient, amount);
}

void Blockchain::addBlock(){
    chain.push_back(nextBlock);
}

// TODO: implement
int Blockchain::getLength(){
    return chain.size();
}

Block Blockchain::getLastBlock(){
    return chain.back();
}

void Blockchain::setNextBlock(){
/*
    if (mempool.size() >= 3) {
        vector<Transaction> newBlockTransactions = {};
        for (int i = 0; i < NUM_BLOCK_TRANSACTIONS; i++) {
            newBlockTransactions.push_back(mempool.front());
            mempool.erase(mempool.begin());
        }
        string lastBlockHash = getLastBlock().getPreviousHash();
        Block newBlock = Block(lastBlockHash, newBlockTransactions);
        nextBlock = newBlock;
    }
    */

    vector<Transaction> newBlockTransactions;
    int numTransactions = min(NUM_BLOCK_TRANSACTIONS, static_cast<int>(mempool.size()));

    // Transactions to be added to the next block
    for (int i = 0; i < numTransactions; ++i) {
        newBlockTransactions.push_back(mempool.front());
        mempool.erase(mempool.begin());
    }

    if (!newBlockTransactions.empty()) {
        string lastBlockHash = getLastBlock().getPreviousHash();
        Block newBlock(lastBlockHash, newBlockTransactions);
        nextBlock = newBlock;
    }


}

Block Blockchain::getNextBlock(){
    return nextBlock;
}


bool Blockchain::runNodes(){
    setNextBlock();

    for (Node *node : nodes){
        node->checkLength(chain, nextBlock);

        if (node->mineBlock(difficulty)) {
            string hash = node->getHash();
            cout << "Node " << node->getAddress() << " mined the block. Hash: " << hash << " Nonce: " << node->getNonce() << endl;
            node->resetNonce();
            nextBlock.setHash(hash);
            node->setBalance(1);

            // Finalize transactions between wallets
            for (Transaction transaction : nextBlock.transactions){
                double change = transaction.getAmount();
                string recipient = transaction.getRecipient();
                string sender = transaction.getSender();

                bool valid = false;
                for (Wallet& wallet : wallets){
                    if (wallet.getAddress() == sender){
                        if (wallet.getBalance() >= change){
                            valid = true;
                            wallet.setBalance(-change);
                        }
                    }
                }

                for (Wallet& wallet : wallets){
                    if (valid and wallet.getAddress() == recipient){
                        wallet.setBalance(change);
                    }
                }
            }

            // update difficulty at the end of this
            int oldDifficulty = difficulty;
            // TODO: functionality for changing difficulty
            // difficulty = nodes.size();
            cout << "difficulty updated from " << oldDifficulty << " to " << difficulty << endl;
            addBlock();
            return true;
        }
    }
    return false;
}