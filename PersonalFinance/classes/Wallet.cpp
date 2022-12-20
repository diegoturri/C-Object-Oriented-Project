//
// Created by Diego on 04/12/22.
//

#include "Wallet.h"
#include "Transaction.h"
#include "Comparator.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

Wallet::Wallet() {
    balance=0;
    transactions={};
    this->refresh();
}


std::ostream &operator<<(ostream &out, const Wallet w) {
    out <<w.balance;
    return out;
}


void Wallet::refresh() {
    int control=0;
    Transaction transaction;
    string line, page;
    string transactionTag = "<TRANSACTION>";
    string transactionTagEnd = "</TRANSACTION>";
    ifstream inputFile("wallet.xml");
    string transactionToParse;
    balance = 0;
    transactions={};

    try {
        //extracting the transactions from the file
        while (getline(inputFile, line)){
                if (line.find(transactionTag) != string::npos)
                    control = 1;
                if (line.find(transactionTagEnd) != string::npos) {
                    control = 0;
                    transactions.push_back(transaction.parseTransaction(transactionToParse));
                    transactionToParse = "";
                }
                if (control == 1)
                    transactionToParse.append(line);

                line.erase();
        }
        //
    }catch (runtime_error &e){
        cout <<e.what() <<endl;
        exit(0);
    }

    balance = tot(transactions);
}


void Wallet::addBalance(int toAdd, string description) {
    if (toAdd < 0)
        throw runtime_error("A transaction can't have a negative value!");
    if (description == "")
        throw runtime_error("A description can't be empty!");

    Transaction transaction("income", description, toAdd, time(0));
    transactions.push_back(transaction);
    balance+=toAdd;
    cout <<"Your provvisory balance is: " <<balance <<" type 'save' to make the transactions so far permanent!" <<endl;
}


void Wallet::subtractBalance(int toSubtract, string description) {
    if (toSubtract < 0)
        throw runtime_error("A transaction can't be have a negative value!");
    if (description == "")
        throw runtime_error("A description can't be empty!");

    Transaction transaction("outcome", description, toSubtract, time(0));

    if (balance >= toSubtract) {
        transactions.push_back(transaction);
        balance -= toSubtract;
    }else {
        cout << endl << "Your balance is: " << balance << endl;
        throw runtime_error("Balance is not enough to complete the operation!");
    }
    cout <<"Your provvisory balance is: " <<balance <<endl;
}


void Wallet::save() {
    if (transactions.size() == 0)
        throw runtime_error("You don't have any transactions ready to be saved!");
    ofstream file;
    file.open("wallet.xml");

    for (auto t: transactions) {
        file <<t;
    }
}


void Wallet::initialize() {
    ofstream out("wallet.xml");
    transactions = {};
    balance=0;
}


void Wallet::report(string type) {
    this->refresh();
    auto transactionsCopy = transactions;

    if (type != "")
        sort(transactionsCopy.begin(), transactionsCopy.end(), Comparator(type));

    for (auto t: transactionsCopy) {
        cout <<t <<endl;
    }

    cout <<"Incomes: " <<totIncomes(transactions) <<endl
         <<"Outcomes: " <<totOutcomes(transactions) <<endl
         <<"Difference: " <<totIncomes(transactions)-totOutcomes(transactions) <<endl
         <<"Balance: " <<balance <<endl <<endl <<endl;
}
