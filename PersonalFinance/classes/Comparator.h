//
// Created by Diego on 11/12/22.
//

#ifndef PERSONALFINANCE_COMPARATOR_H
#define PERSONALFINANCE_COMPARATOR_H


#include "Transaction.h"

class Comparator {
public:
    Comparator(string type0);
    bool operator()(Transaction, Transaction);
private:
    string type;
};


#endif //PERSONALFINANCE_COMPARATOR_H
