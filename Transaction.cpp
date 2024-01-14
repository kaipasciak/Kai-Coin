//
// Created by Kai Pasciak on 12/23/23.
//
#include "Transaction.h"



Transaction::Transaction(string sender, string recipient, double amount){
    this->amount = amount;
    this->sender = sender;
    this->recipient = recipient;
}

string Transaction::getSender(){
    return sender;
}

string Transaction::getRecipient(){
    return recipient;
}

double Transaction::getAmount(){
    return amount;
}

void Transaction::confirm(){

}

string Transaction::toString(){
    stringstream transactionString;
    transactionString << sender << recipient << amount;
    return transactionString.str();
}