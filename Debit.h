#ifndef DEBIT_H
#define DEBIT_H

#include "CashRegister.h"
#include <iostream>
#include <string>

using namespace std;

//Goal: current
//Currently: Gets and sets card number, card type, and accepted/decline
class Debit : public CashRegister{
    public:
        Debit();
        Debit(double aNum);
        //~Debit();
        string getCardNum();
        bool getCardAD();
        string getCardType();
        void setTotalCharge(double aNum);
        void setCardNum(string aNum);
        void setCardAD(bool aAD);
        void setCardType(string aType);
    private:
        string cardNum;
        bool cardAD;
        double totalCharge;
        string cardType;
};

#endif