#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <iostream>
#include <vector>

//Goal: current
//Currently: Add and pop charges to priceVec and priceTotal
class CashRegister{
    public:
        CashRegister();
        //~CashRegister();
        double getPriceTotal();
        char getPaymentMethod();
        bool getPaymentComplete();
        void setPaymentMethod(char aMethod);
        void setPaymentComplete(bool aT);
        void addPrice(double aPrice);
        void popPrice(char aPop);
        void printTotalPrice();
        void printVec();
    protected:
        std::vector<double> priceVec;
        double priceTotal;
        char paymentMethod;
        bool paymentComplete;
};

#endif