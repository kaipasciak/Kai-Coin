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
    while (true) {
        cin >> numWallets;
        // Validate input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter an integer: " << endl;
        }
        else
            break;
    }

    // Initialize wallet addresses and balances
    for (int i = 1; i <= numWallets; i++){
        string address;
        cout << "Create address for wallet " << i << ": " << endl;
        cin >> address;

        while (true) {
            double balance;
            // Validate balance input
            cout << "Enter starting balance for wallet " << i << ": " << endl;
            cin >> balance;
            if (cin.fail()) {
                cout << "Please enter numerical value for starting balance" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                Blockchain.addWallet(address, balance);
                break;
            }
        }
    }
    // Add nodes to network
    int numNodes;
    while (true) {
        cout << "Enter the number of nodes: " << endl;
        cin >> numNodes;
        if (cin.fail()) {
            cout << "Please enter integer value for number of nodes" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            break;
    }
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
            while (true) {
                cout << "Enter amount: " << endl;
                cin >> amount;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter numerical value for transaction amount" << endl;
                }
                else
                    break;
            }

            string recipient;
            cout << "Enter recipient address: " << endl;
            cin >> recipient;
            Blockchain.addTransaction(sender, recipient, amount);
            int more;
            cout << "Enter another? (1: Yes, 2: No) " << endl;
            while (true) {
                cin >> more;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Please enter 1 or 2" << endl;
                }
                else if (more > 2 or more < 1){
                    cout << "Please enter 1 or 2" << endl;
                }
                else
                    break;
            }
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


