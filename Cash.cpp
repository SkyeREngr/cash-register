#include "Cash.h"

using namespace std;

extern CashRegister c1;

//constructors
Cash::Cash(){
    cashIn = 0.0;
    cashOut = 0.0;
    totalCharge = priceTotal;
    paymentComplete = 0;
}

Cash::Cash(double aTotal){
    cashIn = 0.0;
    cashOut = 0.0;
    totalCharge = aTotal;
}

//Cash::~Cash(){}

//getters and setters
double Cash::getCashIn(){
    return cashIn;
}

double Cash::getCashOut(){
    cashOut = cashIn - totalCharge;
    return cashOut;
}

void Cash::setTotalCharge(double aNum){
    totalCharge = aNum;
}

//methods
void Cash::addCash(double aNum){
    cashIn = cashIn + aNum;
    if(cashIn >= totalCharge){
        paymentComplete = 1;
    }
}

void Cash::removeCash(double aNum){
    cashIn = cashIn - aNum;
    if(cashIn < totalCharge){
        paymentComplete = 0;
    }
}

void Cash::printCashIn(){
    cout << cashIn << endl;
}

void Cash::printCashOut(){
    cashOut = cashIn - totalCharge;
    cout << cashOut << endl;
}