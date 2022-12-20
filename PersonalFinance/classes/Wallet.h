//
// Created by Diego on 04/12/22.
//

#ifndef PERSONALFINANCE_WALLET_H
#define PERSONALFINANCE_WALLET_H
#include <string>
#include "Transaction.h"
#include <vector>

using namespace std;

class Wallet {
    friend std::ostream &operator << (std::ostream &out, Wallet w);
public:
    Wallet();
    void refresh();
    void addBalance(int toAdd, string description);
    void subtractBalance(int toSubtract, string description);
    void save();
    void initialize();
    void report(string type="");
private:
    int balance;
    vector<Transaction> transactions;
};


#endif //PERSONALFINANCE_WALLET_H
