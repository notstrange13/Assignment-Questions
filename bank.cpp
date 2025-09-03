#include <iostream>
using namespace std;

class Bank
{
private:
    int acno;
    int balance;

public:
    void getData();
    void deposit();
    void withdraw();
    void displayinfo();
};

void Bank::getData()
{
    acno = 123456;
    balance = 40000;
}

void Bank::deposit()
{
    int d;
    cout << "Enter deposit amount =";
    cin >> d;
    balance = balance + d;
}

void Bank::withdraw()
{
    int w;
    cout << "Enter withdraw amount =";
    cin >> w;
    if (balance >= w)
    {
        balance = balance - w;
    }
    else
    {
        cout << "Insufficient Balance" << endl;
    }
}

void Bank::displayinfo()
{
    cout << "Your current account details are" << endl;
    cout << "A/c no = " << acno << endl;
    cout << "Balance = " << balance << endl;
}

int main()
{
    Bank bank;
    int choice;
    bank.getData();
    bank.displayinfo();
    cout << "Press 1 to deposit and 2 to withdraw" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        bank.deposit();
        break;
    case 2:
        bank.withdraw();
        break;
    default:
        cout << "Choose a valid option.";
        break;
    }
    bank.displayinfo();
    return 0;
}