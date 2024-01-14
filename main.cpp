#include "Blockchain.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Initialize blockchain object
    Blockchain Blockchain;

    // Add wallets to network
    int numWallets;
    cout << "Enter the number of wallets: " << endl;
    cin >> numWallets;
    for (int i = 1; i <= numWallets; i++){
        string address;
        cout << "Create address for wallet " << i << ": " << endl;
        cin >> address;
        double balance;
        cout << "Enter starting balance for wallet " << i << ": " << endl;
        cin >> balance;
        Blockchain.addWallet(address, balance);
    }
    // Add nodes to network
    int numNodes;
    cout << "Enter the number of nodes: " << endl;
    cin >> numNodes;
    vector<Node*> nodes;
    for (int i = 1; i <= numNodes; i++){
        string address;
        cout << "Enter an address for node " << i << endl;
        cin >> address;
        Blockchain.addNode(address);
    }

    while (true) {
        // Create transactions
        while (true) {
            string sender;
            cout << "Enter sender address: " << endl;
            cin >> sender;
            double amount;
            cout << "Enter amount: " << endl;
            cin >> amount;
            string recipient;
            cout << "Enter recipient address: " << endl;
            cin >> recipient;
            Blockchain.addTransaction(sender, recipient, amount);
            int more;
            cout << "Enter another? (1: Yes, 2: No) " << endl;
            cin >> more;
            if (more != 1)
                break;
        }

        // Run nodes here in a loop until the length of the blockchain increases by one
        cout << "Running network nodes now" << endl;
        int round = 0;
        while (true) {
            round++;
            cout << "Round: " << round << endl;
            if (Blockchain.runNodes())
                break;

        }

        cout << "Wallet balances: " << endl;
        for (int i = 0; i < numWallets; i++)
            cout << Blockchain.wallets[i].getAddress() << " " << Blockchain.wallets[i].getBalance() << endl;

        cout << "Node balances: " << endl;
        for (int i = 0; i < numNodes; i++)
            cout << Blockchain.nodes[i]->getAddress() << " " << Blockchain.nodes[i]->getBalance() << endl;

        string response;
        cout << "Continue running? (1: Yes, 2: No) " << endl;
        cin >> response;
        if (response != "1")
            break;
    }

    return 0;
}


