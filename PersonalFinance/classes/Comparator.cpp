//
// Created by Diego on 11/12/22.
//

#include "Comparator.h"

Comparator::Comparator(string type0) {
    type=type0;
}

bool Comparator::operator()(Transaction t1, Transaction t2) {
    if (type == "income first")
        return t1.betterThan(t2);
    if (type == "outcome first")
        return t1.worseThan(t2);
    if (type=="all")
        return t1>t2;
    return true;
}
