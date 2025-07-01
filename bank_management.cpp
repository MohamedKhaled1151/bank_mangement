#include <iostream>
#include <cstdlib> 
using namespace std;

class Bank {
    char name[100], address[100], accountType;
    int balance;

public:
    void openAccount();
    void depositMoney();
    void withdrawMoney();
    void displayAccount();
};

void Bank::openAccount() {
    cout << "Enter your full name: ";
    cin.ignore();
    cin.getline(name, 100);

    cout << "Enter your address: ";
    cin.getline(address, 100);

    cout << "What type of account do you want to open? (Savings (s) / Current (c)): ";
    cin >> accountType;

    cout << "Enter amount for deposit: ";
    cin >> balance;

    if (balance < 0) {
        cout << "Invalid deposit amount. Setting balance to 0.\n";
        balance = 0;
    }

    cout << "Your account has been created successfully.\n";
}

void Bank::depositMoney() {
    int amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful! Your new balance is: " << balance << " units.\n";
    }
    else {
        cout << "Invalid deposit amount. Please enter a positive value.\n";
    }
}

void Bank::withdrawMoney() {
    int amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive value.\n";
    }
    else if (amount > balance) {
        cout << "Insufficient balance! Your current balance is: " << balance << " units.\n";
    }
    else {
        balance -= amount;
        cout << "Withdrawal successful! Your remaining balance is: " << balance << " units.\n";
    }
}

void Bank::displayAccount() {
    cout << "\n--- Account Details ---\n";
    cout << "Full Name: " << name << "\n";
    cout << "Address: " << address << "\n";
    cout << "Account Type: " << (accountType == 's' ? "Savings" : "Current") << "\n";
    cout << "Balance: " << balance << " units\n";
    cout << "-------------------------\n";
}

int main() {
    Bank obj;
    int choice;
    char x;

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1) Open Account\n";
        cout << "2) Deposit Money\n";
        cout << "3) Withdraw Money\n";
        cout << "4) Display Account\n";
        cout << "5) Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.openAccount();
            break;
        case 2:
            obj.depositMoney();
            break;
        case 3:
            obj.withdrawMoney();
            break;
        case 4:
            obj.displayAccount();
            break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            exit(0); 
        default:
            cout << "Invalid choice! Please select a valid option.\n";
        }
            
        cout << "\nDo you want to select another option? (y/n): ";
        cin >> x;

    } while (x == 'y' || x == 'Y');

    return 0; 

}

