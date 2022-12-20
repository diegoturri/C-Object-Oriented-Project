//
// Created by Diego on 04/12/22.
//

#include <iostream>
#include "Transaction.h"
#include <vector>
#include <ctime>

using namespace std;

Transaction::Transaction(string type0, string description0, int amount0, time_t time0) {
    type=type0;
    description=description0;
    amount=amount0;
    dataValue = time0;
}

std::ostream &operator<<(ostream &out, const Transaction t) {
    string time = asctime(localtime(&t.dataValue)); //this converstion inserts a '\n' that has to be removed to make the data look better

    out <<"<TRANSACTION>" <<endl
        <<"<TYPE>" <<t.type <<"</TYPE>" <<endl
        <<"<DESCRIPTION>" <<t.description <<"</DESCRIPTION>" <<endl
        <<"<AMOUNT>"<<t.amount <<"</AMOUNT>" <<endl
        <<"<DATA_VALUE>" <<t.dataValue <<"</DATA_VALUE>" <<endl
        <<"<DATA>" <<time.substr(0, time.size()-1) <<"</DATA>" <<endl //remove the '\n' as told above
        <<"</TRANSACTION>" <<endl <<endl;
    return out;
}

Transaction Transaction::parseTransaction(string page) {
    //tags
    string typeTag = "<TYPE>";
    string typeTagEnd = "</TYPE>";
    string descriptionTag = "<DESCRIPTION>";
    string descriptionTagEnd = "</DESCRIPTION>";
    string amountTag = "<AMOUNT>";
    string amountTagEnd = "</AMOUNT>";
    string dataValueTag = "<DATA_VALUE>";
    string dataValueTagEnd = "</DATA_VALUE>";
    //

    //finding and assigning the values
    if (page.find(typeTag) != string::npos && page.find(typeTagEnd) != string::npos)
        type = page.substr((page.find(typeTag)+typeTag.length()),(page.find(typeTagEnd)-page.find(typeTag)-typeTag.length()));
    if (page.find(descriptionTag) != string::npos && page.find(descriptionTagEnd) != string::npos)
        description = page.substr((page.find(descriptionTag)+descriptionTag.length()),(page.find(descriptionTagEnd)-page.find(descriptionTag)-descriptionTag.length()));
    if (page.find(amountTag) != string::npos && page.find(amountTagEnd) != string::npos)
        amount = atoi(page.substr((page.find(amountTag)+amountTag.length()),(page.find(amountTagEnd)-page.find(amountTag)-amountTag.length())).data());
    if (page.find(dataValueTag) != string::npos && page.find(dataValueTagEnd) != string::npos)
        dataValue = atoi(page.substr((page.find(dataValueTag) + dataValueTag.length()),(page.find(dataValueTagEnd) - page.find(dataValueTag) - dataValueTag.length())).data());
    //

    if (type == "" || description == "" || amount < 0 || dataValue <= 0)
        throw runtime_error("Something went wrong during the parsing of the Transactions!");

    return *this;
}

bool Transaction::operator>(Transaction t) const {
    if (this->amount >= t.amount)
        return true;
    return false;
}

bool Transaction::operator<(Transaction t) const {
    if (this->amount <= t.amount)
        return true;
    return false;
}

bool Transaction::betterThan(Transaction t) {
    if (this->type=="income" && t.type=="outcome")
        return true;
    if (std::equal(this->type.begin(), this->type.end(), t.type.begin(), t.type.end())) {
        if (type=="income" && this->amount >= t.amount)
            return true;
        if (type=="outcome" && this->amount <= t.amount)
            return true;
    }

    return false;
}

bool Transaction::worseThan(Transaction t) {
    if (this->type=="outcome" && t.type=="income")
        return true;
    if (std::equal(this->type.begin(), this->type.end(), t.type.begin(), t.type.end())) {
        if (type == "outcome" && this->amount >= t.amount)
            return true;
        if ((type == "income" && this->amount <= t.amount))
            return true;
    }

    return false;
}
