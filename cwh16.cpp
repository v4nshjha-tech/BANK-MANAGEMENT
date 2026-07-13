#include <iostream>
#include <fstream>
using namespace std;

class Bankaccount {
private:
    int accNo;
    char name[50];
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void showAccount() {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    void deposit() {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw() {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;
        if (amt <= balance) {
            balance -= amt;
            cout << "Withdraw Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    int getAccNo() {
        return accNo;
    }
};


void writeAccount() {
    Bankaccount acc;
    ofstream outFile("bank.dat", ios::binary | ios::app);
    acc.createAccount();
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(acc));
    outFile.close();
}


void displayAccount(int num) {
    Bankaccount acc;
    ifstream inFile("bank.dat", ios::binary);
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.getAccNo() == num) {
            acc.showAccount();
            found = true;
        }
    }

    if (!found)
        cout << "Account not found!\n";

    inFile.close();
}


void modifyAccount(int num, int type) {
    Bankaccount acc;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);
    bool found = false;

    while (!file.eof() && !found) {
        streampos pos = file.tellg();
        file.read(reinterpret_cast<char*>(&acc), sizeof(acc));

        if (acc.getAccNo() == num) {
            if (type == 1)
                acc.deposit();
            else
                acc.withdraw();

            file.seekp(pos);
            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));
            found = true;
        }
    }

    if (!found)
        cout << "Account not found!\n";

    file.close();
}


int main() {
    int choice, accNo;

    do {
        cout << "\n--- BANK MANAGEMENT SYSTEM ---";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit";
        cout << "\n3. Withdraw";
        cout << "\n4. Check Balance";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            writeAccount();
            break;
        case 2:
            cout << "Enter Account No: ";
            cin >> accNo;
            modifyAccount(accNo, 1);
            break;
        case 3:
            cout << "Enter Account No: ";
            cin >> accNo;
            modifyAccount(accNo, 2);
            break;
        case 4:
            cout << "Enter Account No: ";
            cin >> accNo;
            displayAccount(accNo);
            break;
        case 5:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}