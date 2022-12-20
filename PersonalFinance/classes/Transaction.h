//
// Created by Diego on 04/12/22.
//

#ifndef PERSONALFINANCE_TRANSACTION_H
#define PERSONALFINANCE_TRANSACTION_H
#include <string>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

class Transaction {
    friend std::ostream &operator << (std::ostream &out, Transaction t);
    friend int totIncomes(vector<Transaction> t0){
        int res=0;
        for (auto t: t0) {
            if (t.type=="income")
                res += t.amount;
        }
        return res;
    };
    friend int totOutcomes(vector<Transaction> t0){
        int res=0;
        for (auto t: t0) {
            if (t.type=="outcome")
                res += t.amount;
        }
        return res;
    };
    friend int tot(vector<Transaction> t0){
        int res=0;
        for (auto t: t0) {
            if (t.type=="income")
                res += t.amount;
            if (t.type=="outcome")
                res -= t.amount;
        }
        return res;
    };

public:
    Transaction(string type0 = "", string description0 = "", int amount0=0, time_t time0 = time(0));
    Transaction parseTransaction(string page);
    bool operator>(Transaction t) const;
    bool operator<(Transaction t) const;
    bool betterThan(Transaction t);
    bool worseThan(Transaction t);

private:
    int amount;
    long dataValue;
    string type, description;
};


#endif //PERSONALFINANCE_TRANSACTION_H
