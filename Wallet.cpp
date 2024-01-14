//
// Created by Kai Pasciak on 12/23/23.
//

#include "Wallet.h"
Wallet::Wallet(string address, double balance){
    this->address = address;
    this->balance = balance;
}

double Wallet::getBalance(){
    return balance;
}

void Wallet::setBalance(double change){
    if (balance + change >= 0)
        balance += change;
}

string Wallet::getAddress(){
    return address;
}