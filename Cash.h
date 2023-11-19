#ifndef CASH_H
#define CASH_H

#include "CashRegister.h"
#include <iostream>

using namespace std;

//Goal: current
//Currently: Balances cash payments
class Cash : public CashRegister{
    public:
        Cash();
        Cash(double aNum);
        //~Cash();
        double getCashIn();
        double getCashOut();
        void setTotalCharge(double aNum);
        void addCash(double aNum);
        void removeCash(double aNum);
        void printCashIn();
        void printCashOut();
    private:
        double cashIn;
        double cashOut;
        double totalCharge;
};

#endif