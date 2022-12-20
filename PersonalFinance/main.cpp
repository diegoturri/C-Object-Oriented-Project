#include <iostream>
#include "classes/Wallet.h"

using namespace std;

//EXAMPLE OF USE:
//Type +
//insert the amount of the transaction          (int)
//insert the description of the transaction     (string)
//now the provvisory balance is shown on the screen
//
//type 'save' in order to save the transactions inserted so far and be able to use them in the future
//you can see the new transactions from the file 'cmake-build-debug/wallet.xml'
//
//ONLY SAVED TRANSACTIONS WILL BE REPORTED BY THE 'report' COMMAND

int main() {
    bool loop = true;
    int amount=0;
    string choice, description;
    Wallet wallet;


    while (loop) {
        try {
            //initial command from the user
            cout <<endl <<endl
                 << "INSERT A COMMAND     ----after adding a transaction save it to make it official!" <<endl
                 << "commands -> Meaning:" <<endl
                 << "+ -> Add a sum" <<endl
                 << "- -> Subtract a sum" <<endl
                 << "save -> save the transactions" <<endl
                 << "reset -> erase all the transactions" <<endl
                 << "report -> Print a report (report--all, report--incomefirst and report--outcomefirst are the sorted versions)" <<endl
                 << "stop -> Finish the execution of the program" << endl
                 << "command: ";
            cin >> choice;
            //

            //decision handler
            if (choice == "+") {
                cout << "insert the amount to add: ";
                cin >> amount;
                cout << "insert the description of the transaction: ";
                cin.ignore();
                getline(cin, description);

                wallet.addBalance(amount, description);
            }
            if (choice == "-") {
                cout << "insert the amount to subtract: ";
                cin >> amount;
                cout << "insert the description of the transaction: ";
                cin.ignore();
                getline(cin, description);

                wallet.subtractBalance(amount, description);
            }
            if (choice == "save")
                wallet.save();
            if (choice == "reset")
                wallet.initialize();
            if (choice == "report")
                wallet.report("");
            if (choice == "report--all")
                wallet.report("all");
            if (choice == "report--incomefirst")
                wallet.report("income first");
            if (choice == "report--outcomefirst")
                wallet.report("outcome first");
            if (choice == "stop")
                loop = false;
            //
        }catch (runtime_error &e){
            cout <<e.what() <<endl;
            cin.clear();
        }
    }


    return 0;
}
