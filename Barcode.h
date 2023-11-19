#ifndef BARCODE_H
#define BARCODE_H   

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Goal: current
//Currently: recieves transaction num and creates/prints a unique barcode depending on each
//           individual integer in said transaction num
class Barcode{
    public:
        Barcode();
        Barcode(int aNum);
        //~Barcode();
        int getTransNum();
        string getBarcode();
        void setTransNum(int aNum);
        void setBarcode(int aNum);
        void printBarcode();
    protected:
        int transNum;
        string newBarcode;
};

#endif