//Wen Qian Zheng
//October 15th, 2024
//Homework 3

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    /*
    ifstream trans("trans.txt"); // pulls from file trans.txt
    float bal, change; // declares float variables
    char transType;
    trans >> balance; // taking first value from transactions then putting it in our balance

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

    cout << "\nFinal Balance: " << fixed << setprecision(2) << bal;

    trans.close();
    */
    ifstream trans("trans.txt");
    ofstream note("note.txt");
    float startBal, bal, change, transDone, Dep, With;
    char transType;

    //Setup Starting Balance
    trans >> bal;
    startBal = bal;

    //Outputs Starting Balance and Table Header
    note << "Starting Balance: " << fixed << setprecision(2) << startBal << endl << endl;
    setfill(".");
    note << right << "Type" << setw(10) << "Amount" << setw(20) << "Balance" << endl;

    while (!trans.eof()) { //loops
        // takes our trans type
        trans >> transType; // and then stores it
        // trans amount
        trans >> change; // stores it
        transDone++; // append 1

        switch(transType) // different cases 
        {
            case 'W':
                bal -= change;
                With += change;
                break;
            case 'D':
                bal += change;
                Dep += change;
                break;
        }

        setfill("_");
        note << right << transType << setw(13) << fixed << setprecision(2) << change << setw(20) << bal << endl;
    }

    note << "\nTransaction Count: \n" << transDone << endl;
    note << "Deposits: \n" << fixed << setprecision(2) << Dep << endl;
    note << "Withdraws: \n" << fixed << setprecision(2) << With << endl;
    note << "Balance: \n" << fixed << setprecision(2) << bal << endl;

    trans.close();
    note.close();
    return 0;
}
