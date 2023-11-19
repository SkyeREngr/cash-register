// #include <iostream>
// #include <vector>
// #include <string>
// #include <fstream>

// #include "CashRegister.h"
// #include "Cash.h"
// #include "Debit.h"
// #include "Barcode.h"
// #include "Inventory.h"

// using namespace std;

// void InventoryInit();
// void TransNumInit();
// Inventory Scanner(int aID);
// Inventory CheckAttributes(int aID);
// string printReceipt();

// int transNum = 0;
// CashRegister c1;
// vector<Inventory> Inv = {};
// vector<Inventory> Queued = {};
// vector<string> QItemNames = {};
// vector<int> QItemIDs = {};
// vector<int> QItemStock = {};

// void InventoryInit(){
//     fstream infile;
//     string lineInput;

//     int myID;
//     int myStock;
//     double myPrice;
//     string myName;

//     infile.open("StoreInventory.txt", ios::in);

//     if(!infile){
//         cout << "File open failure!!!!" << endl;
//     }
    
//     //getline i and separate the numbers strings into itemName, itemPrice, and itemStock
//     for(int i = 0; i < 4; ++i){ //i < size of inventory (hardcoded)
//         Inventory item;

//         if(!infile.eof()){
//             getline(infile, lineInput, ' ');
//             myID = stoi(lineInput);
//             //cout << myID << " ";

//             getline(infile, lineInput, ' ');
//             myStock = stoi(lineInput);
//             //cout << myStock << " ";

//             getline(infile, lineInput, ' ');
//             myPrice = stod(lineInput);
//             //cout << myPrice << " ";

//             getline(infile, lineInput);
//             myName = lineInput;
//             //cout << myName << endl;
//         }

//         item.setItemID(myID);             //infile int from line i
//         item.setItemPrice(myPrice);       //infile double from line i
//         item.setItemStock(myStock);       //infile int from line i
//         item.setItemName(myName);         //infile string from line i
        
//         //item.printInfo();

//         //add items into Inv vector
//         Inv.push_back(item);
//     }
//     infile.close();
// }

// void TransNumInit(){
//     ifstream infile;
//     ofstream outfile;
//     string lineInput;

//     infile.open("RegTransNum.txt", ios::in);

//     if(!infile){
//         cout << "File open failure!!!!" << endl;
//     }

//     if(!infile.eof()){
//         getline(infile, lineInput);
//         transNum = stoi(lineInput);
//         cout << transNum << endl;
//     }

//     transNum = transNum + 1;

//     if(remove("RegTransNum.txt")){
//         cout << "File deletion successful" << endl;
//     }
//     else{ cout << "File deletion failure" << endl; }

//     outfile.open("RegTransNum.txt");
//     outfile << transNum << endl;
//     cout << transNum << endl;

//     infile.close();
// }

// //gets object with an ID equal to the passed in value
// Inventory Scanner(int aID){
//     Inventory nsItem;
//     nsItem.equals(CheckAttributes(aID));
//     return nsItem;
// }

// Inventory CheckAttributes(int aID){
//     Inventory cScanned;
//     for(int i = 0; i < Inv.size(); ++i){
//         if(Inv[i].getItemID() == aID){
//             cScanned = (Inv[i]);
//             cout << "Successful scan" << endl;
//             return cScanned;
//         }
//         else{
//             cout << "Failed iteration" << endl;
//         }
//     }
// }

// string printReceipt(){
//     cout << "Aldis";
//     cout << "\nDate";
//     cout << "\n1-800-555-5555";
//     cout << "\nCarson, CA 90111\n";
//     cout << transNum;
//     for(int i = 0; i < Queued.size(); ++i){
//         Queued[i].printInfo();
//     }
//     cout << "Subtotal: " << c1.getPriceTotal();
//     cout << "\nTax: 12% ";
//     cout << "\nTotal: " << (c1.getPriceTotal() * 1.12);
//     if(c1.getPaymentMethod() == 'c'){
//         double change = cashc.getCashOut();
//         int accNum = 0;
//     }
//     if(c1.getPaymentMethod() == 'd'){
//         double change = 0.0;
//         long long accNum = debitc.getCardNum();
//     }
//     cout << "\n# Items Sold: " << Queued.size();
//     Barcode b1;
//     b1.setBarcode(transNum);
//     b1.printBarcode();
// }

// int main(){
//     bool finished = 0;

//     do{
//         InventoryInit();
//         TransNumInit();

//         char pM;
//         double r1, r2, r3, r4;
//         string r5, r6;
//         long long r7;
//         bool myLoop = 0;

//         cout << "Welcome to Aldi's.";

//         //scanning loop
//         while(!myLoop){
//             cout << "\nPlease scan your items (Press Z to remove most recent item / Press F to finish): ";
//             cin >> r4;
//             if(r4 != 'F' | r4 != 'Z'){
//                 Inventory sItem = Scanner(r4);
//                 Queued.push_back(sItem);
//                 c1.addPrice(Queued[Queued.size()].getItemPrice());
//                 QItemNames.push_back(Queued[Queued.size()].getItemName());
//                 QItemIDs.push_back(Queued[Queued.size()].getItemID());
//                 QItemStock.push_back(Queued[Queued.size()].getItemID());
//             }
//             if(r4 == 'Z'){
//                 Queued.pop_back();
//                 c1.popPrice('p');
//                 QItemNames.pop_back();
//                 QItemIDs.pop_back();
//                 QItemStock.pop_back();
//             }
//             if(r4 == 'F'){
//                 myLoop = 1; 
//             }
//         }

//         //payment type
//         cout << "\nPlease select your payment type: ";
//         cin >> pM;
//         c1.setPaymentMethod(pM);

//         if(pM == 'c'){
//             Cash cashc(c1.getPriceTotal());
//             cout << "\nCash has been selected. Please insert bills and/or coins: ";
//             cin >> r1;
//             cashc.addCash(r1);
//             while(!(c1.getPaymentComplete())){
//                 cout << "\nInsufficient amount has been inserted. Please insert bills and/or coins: ";
//                 cin >> r2;
//                 if(r2 == 'r'){
//                     cout << "\nPlease specify amount to be removed";
//                     cin >> r3;
//                     cashc.removeCash(r3);
//                 }
//                 else{
//                     cashc.addCash(r2);
//                 }
//             }
//         }

//         if(pM== 'd'){
//             Debit debitc(c1.getPriceTotal());
//             cout << "\nDebit has been selected. Please insert your card type: ";
//             cin >> r5;

//             if(r5 == "Chase" || r5 == "Wells Fargo"){
//                 debitc.setCardType(r5);
//                 cout << "\nValid Card Company Entered.";
//             }
//             else{
//                 cout << "\nInvalid Card Company. Please try again: ";
//                 cin >> r6;
//                 if(r6 == "Chase" || r6 == "Wells Fargo"){
//                     debitc.setCardType(r6);
//                     cout << "\nValid Card Company Entered";
//                 }
//                 else{
//                     "\nInvalid Card Company Entered.";
//                     debitc.setCardType("Invalid");
//                 }
//             }

//             cout << "\nPlease insert your card number: ";
//             cin >> r7;
//             debitc.setCardNum(r7);

//             if(r7 > 1000000000000000){
//                 cout << "\nCard has been approved.";
//                 debitc.setCardAD(1);
//             }
//         }
//         printReceipt();

//     //finished?
//     cout << "\nfinished? y=1/n=0";
//     cin >> finished;
//     }while(!finished);
    



    // Inventory sItem = Scanner(272902); //scanner(VARIABLE) in a loop
    // Queued.push_back(sItem);

    //add all scanned items into their vectors
    //needs to happen every time an item is scanned
    // c1.addPrice(Queued[Queued.size()].getItemPrice());
    // QItemNames.push_back(Queued[Queued.size()].getItemName());
    // QItemIDs.push_back(Queued[Queued.size()].getItemID());
    // QItemStock.push_back(Queued[Queued.size()].getItemID());

    //pops most recent addition to all vectors
    //needs to happen every time an 'p' is inputted
    // c1.popPrice('p');
    // QItemNames.pop_back();
    // QItemIDs.pop_back();
    // QItemStock.pop_back();


    //needs to pass in c or d into paymentMethod from user input
    // if(c1.getPaymentMethod() == 'c'){
    //     Cash cashc(c1.getPriceTotal());
        //ask for cash in
        // while(!(c1.getPaymentComplete())){
            //ask for cash in again
            // if(userinput == 'r'){
            //     prompt for money to be removed
            //     cashc.removeCash(userinput2)
            // }
            // else{
            //     cashc.addCash(userinput)
            // }
        // }
    // }
    // else if(c1.getPaymentMethod() == 'd'){
    //     Debit debit(c1.getPriceTotal());
        //ask for debit card type
        //only accepts Chase and Wells Fargo
        // string userin1 = userinput;
        // if(userin1 == "Chase" || userin1 == "Wells Fargo"){
        //     debit.setCardType(userin1);
        // }
        // else{
        //     cout << "Invalid Card Company" << endl;
        // }

        //ask for debit card number
        //as long as debit card number has 16 digits
        // unsigned long long userin = userinput;
        //     if(userin2 > 1000000000000000){
        //         debit.setCardNum(userinp);
        //         c1.setPaymentComplete(1);
        //     }
        //     else{
        //         cout << "Invalid Card Number" << endl;
        //     }
    // }
    // else{
    //     cout << "Invalid Payment Method" << endl;
    // }

    // while(c1.getPaymentComplete()){
    //     ++transNum;
    //     Barcode barcode(transNum);
    //     string myBarcode = barcode.getBarcode();
    // }

    // if(sItem1.getItemName() == Inv2[1].getItemName()){
    //     cout << "Successful comparison 1" << endl;
    // }
    // else{ cout << "Unsuccessful comparison 1" << endl; }
    // sItem1.printInfo();

    //cout << "2" << endl;
    // Inventory sItem2 = Scanner(272903);

    // if(sItem2.getItemName() == Inv2[2].getItemName()){
    //     cout << "Successful comparison 2" << endl;
    // }
    // else{ cout << "Unsuccessful comparison 2" << endl; }
    // sItem2.printInfo();
    

    // Debit card;

    // Barcode b1;
    // b1.printBarcode();

    // Inv[2].printInfo(); //works!
    // wallet.printCashOut();
    
    //cout << c1.getPriceTotal() << endl; //object.func() works to return a value

    // return 0;
//}