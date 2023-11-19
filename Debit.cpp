#include "Debit.h"

using namespace std;

//constructors
Debit::Debit(){
    cardNum = "0000000000000000";
    totalCharge = 0.0;
    cardAD = 0;
}

Debit::Debit(double aNum){
    cardNum = "0000000000000000";
    totalCharge = aNum;
    cardAD = 0;
}

void Debit::setTotalCharge(double aNum){
    totalCharge = aNum;
}

//~Debit(){}

//getters and setters
string Debit::getCardNum(){
    return cardNum;
}

bool Debit::getCardAD(){
    return cardAD;
}

string Debit::getCardType(){
    return cardType;
}

void Debit::setCardNum(string aNum){
    cardNum = aNum;
}

void Debit::setCardAD(bool aAD){
    cardAD = aAD;
}

void Debit::setCardType(string aType){
    cardType = aType;
}