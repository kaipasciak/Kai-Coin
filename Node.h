//
// Created by Kai Pasciak on 12/23/23.
//

#ifndef KAICOIN_NODE_H
#define KAICOIN_NODE_H

#include "Block.h"
#include "Blockchain.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <vector>

class Node {
private:
    Block currentBlock;
    int chainLength;
    int nonce;
    double balance;
    string address;
    string hash;

public:
    Node(string address);
    /**
     * If the current length of the block chain increases, the node knows that a new block has been added
     * so it should abandon the block it's currently working on and start mining the next block.
     */
    void checkLength(vector<Block> blockchainCopy, Block nextBlock);

    /**
     * Called in checkLength() as long as the blockchain length goes up before it has finished mining the block.
     * The node will take the block from the end of the blockchain and begin mining.
     */

    void updateBlock(Block nextBlock);

    /**
     * Use SHA 256 to try different values for nonce
     */

    void setBalance(double change);

    string getAddress();

    double getBalance();

    void resetNonce();

    int getNonce();

    bool mineBlock(int difficulty);

    string sha256(const string& str);

    string getHash();

};


#endif //KAICOIN_NODE_H
