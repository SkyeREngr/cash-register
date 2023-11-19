#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Goal: 
//Currently: 

class Inventory{
    public:
        Inventory();
        Inventory(string aName, double aPrice, int aStock, int aID);
        //~Inventory();
        string getItemName();
        double getItemPrice();
        int getItemStock();
        int getItemID();
        void setItemName(string aName);
        void setItemPrice(double aPrice);
        void setItemStock(int aStock);
        void setItemID(int aID);
        //Inventory checkAttributes(int aID);
        void equals(Inventory aItem);
        void printInfo1();
        void printInfo2();
    private:
        int itemID;
        string itemName;
        double itemPrice;
        int itemStock;
};

#endif