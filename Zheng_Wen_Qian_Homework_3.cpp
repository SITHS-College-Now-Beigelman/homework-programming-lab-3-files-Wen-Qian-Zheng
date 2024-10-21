//Wen Qian Zheng
//October 15th, 2024
//Homework 3

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    /*
    ifstream trans("transactions.txt");
    float bal, change;
    char transType;
    transactions >> balance;

    //Outputs Table Header
    setfill(' ');
    cout << right << "Type of Transaction" << setw(15) << "Amount" << setw(20) << "Balance" << endl;

    for(int i = 0; i < 7; i++) {
        trans >> transType;
        trans >> change;
        switch(transType)
        {
            case 'W':
                bal -= change;
                break;
            case 'D':
                bal += change;
                break;
        }
        setfill(".");
        cout << right << transType << setw(13) << fixed << setprecision(2) << change << setw(20) << bal << endl;
    }

    //Outputs Final Balance
    cout << "\nFinal Balance: " << fixed << setprecision(2) << bal;

    //Closes txt File
    trans.close();
    */

    //Setup Variables
    ifstream trans("transactions.txt");
    ofstream note("banknote.txt");
    float startBal, bal, change, transDone, totalDep, totalWith;
    char transType;

    //Setup Starting Balance
    trans >> bal;
    startBal = bal;

    //Outputs Starting Balance and Table Header
    note << "Starting Balance: " << fixed << setprecision(2) << startBal << endl << endl;
    setfill(".");
    note << right << "Type" << setw(10) << "Amount" << setw(20) << "Balance" << endl;

    //Repeat Until End of File
    while (!trans.eof()) {
        //Take the Transaction Type
        trans >> transType;
        //Take the Transaction Amount
        trans >> change;
        //Add 1 to Transactions Done
        transDone++;
        //Different Actions for Different Cases
        switch(transType) {
            case 'W':
                bal -= change;
                totalWith += change;
                break;
            case 'D':
                bal += change;
                totalDep += change;
                break;
        }
        //Outputs Data In a Set Format
        setfill(".");
        note << right << transType << setw(13) << fixed << setprecision(2) << change << setw(20) << bal << endl;
    }

    //Final Bank Info
    note << "\nTransactions Done: " << transDone << endl;
    note << "Total Deposits: " << fixed << setprecision(2) << totalDep << endl;
    note << "Total Withdraws: " << fixed << setprecision(2) << totalWith << endl;
    note << "Final Balance: " << fixed << setprecision(2) << bal << endl;
    
    //Closes txt Files
    trans.close();
    note.close();

    //Exits Successfully
    return 0;
}
