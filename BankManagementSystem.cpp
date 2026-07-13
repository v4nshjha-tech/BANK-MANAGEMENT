#include <iostream>
#include <fstream>
#include<iomanip>
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
    cout << fixed << setprecision(2);

<<<<<<< HEAD
    cout << "\n==============================";
    cout << "\nAccount No      : " << accNo;
    cout << "\nAccount Holder  : " << name;
    cout << "\nBalance         : ₹" << balance;
    cout << "\n==============================\n";
=======
 cout << "\n==============================\n";
cout << "Account Number : " << accNo << endl;
cout << "Account Holder : " << name << endl;
cout << "Balance        : Rs. " << fixed << setprecision(2) << balance << endl;
cout << "==============================\n";
>>>>>>> c24da26 (Added README and project screenshots)
}

    void deposit() {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        
       if(amt<=0)
{
    cout<<"Invalid Amount!\n";
    return;
}

balance+=amt;
     cout<<"\n=================================\n";
cout<<"Deposit Successful\n";
<<<<<<< HEAD
cout<<"Updated Balance : ₹"<<balance;
cout<<"\n=================================\n";
}

    void withdraw() {
        float amt;
      cout << "\nWithdrawal Successful!\n";
cout << "Remaining Balance : ₹" << fixed << setprecision(2) << balance << endl;
        

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

bool accountExists(int accNo)
{
    Bankaccount acc;
    ifstream file("bank.dat", ios::binary);

    while(file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
    {
        if(acc.getAccNo()==accNo)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
void writeAccount()
{
    Bankaccount acc;
=======
cout<<"Updated Balance : Rs"<<balance;
cout<<"\n=================================\n";
}

void withdraw()
{
    float amt;

    cout << "Enter amount to withdraw: ";
    cin >> amt;

    if(amt <= 0)
    {
        cout << "Invalid Amount!\n";
        return;
    }

    if(amt > balance)
    {
        cout << "Insufficient Balance!\n";
        return;
    }

    balance -= amt;

    cout << "\n=================================\n";
    cout << "Withdrawal Successful\n";
    cout << "Remaining Balance : Rs. "
         << fixed << setprecision(2) << balance << endl;
    cout << "=================================\n";
}

int getAccNo()
{
    return accNo;
}
};

bool accountExists(int accNo)
{
    Bankaccount acc;
    ifstream file("bank.dat", ios::binary);

    while(file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
    {
        if(acc.getAccNo()==accNo)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
void writeAccount()
{
    Bankaccount acc;
>>>>>>> c24da26 (Added README and project screenshots)

    acc.createAccount();

    if(accountExists(acc.getAccNo()))
    {
        cout<<"\nAccount Number Already Exists!\n";
        return;
    }

    ofstream outFile("bank.dat", ios::binary|ios::app);

    outFile.write(reinterpret_cast<char*>(&acc), sizeof(acc));

    outFile.close();

    cout<<"\nAccount Created Successfully.\n";
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

   while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc)))
{
    streampos pos = file.tellg() - static_cast<streamoff>(sizeof(acc));

    if (acc.getAccNo() == num)
    {
        if(type == 1)
            acc.deposit();
        else
            acc.withdraw();

        file.seekp(pos);
        file.write(reinterpret_cast<char*>(&acc), sizeof(acc));

        found = true;
        break;
    }
}

    if (!found)
        cout << "Account not found!\n";

    file.close();
}


int main() {
    int choice, accNo;

    do {
    cout << "\n=========================================\n";
cout << "        🏦 BANK MANAGEMENT SYSTEM\n";
cout << "=========================================\n";
cout << "1. Create Account\n";
cout << "2. Deposit Money\n";
cout << "3. Withdraw Money\n";
cout << "4. Check Balance\n";
cout << "5. Exit\n";
cout << "=========================================\n";
cout << "Enter Your Choice : ";
   while(!(cin>>choice))
{
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"Invalid Input!\n";
}

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
          cout<<"\n=================================\n";
cout<<" Thank You For Using\n";
cout<<" BANK MANAGEMENT SYSTEM\n";
cout<<" Developed By Vansh Jha\n";
cout<<"=================================\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
