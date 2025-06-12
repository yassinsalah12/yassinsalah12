#include <iostream>
#include <string>
using namespace std;

int initialBalance = 0;
int count1;  // عدد المستخدمين
string database[10][4];  // نفترض ماكس 10

void newuser() {
    cout << "How many users do you want to create? ";
    cin >> count1;

    for (int i = 0; i < count1; i++) {
        cout << "\nCreating account #" << i + 1 << endl;

        cout << "Enter your First Name: ";
        cin >> database[i][0];
        cout << "Enter your Last Name: ";
        cin >> database[i][1];

        int pin1, pinconfirm;
        do {
            cout << "Enter your Pin: ";
            cin >> pin1;
            cout << "Confirm your Pin: ";
            cin >> pinconfirm;
            if (pin1 != pinconfirm) {
                cout << "Pins do not match. Please try again." << endl;
            }
        } while (pin1 != pinconfirm);

        database[i][2] = to_string(pin1);
        database[i][3] = to_string(initialBalance);
    }
}

int WithdrawMoney(int balance) {
    int amount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount % 50 == 0) {
        if (amount <= 2000 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl;
            cout << "Remaining balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount or exceeds limit. Please try again." << endl;
        }
    }
    else {
        cout << "Amount must be a multiple of 50. Please try again." << endl;
    }
    return balance;
}

void depositMoney(int index) {
    int amount;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    if (amount % 50 == 0) {
        int currentBalance = stoi(database[index][3]);
        currentBalance += amount;
        database[index][3] = to_string(currentBalance);
        cout << "Deposit of $" << amount << " successful." << endl;
        cout << "Your new balance is: $" << database[index][3] << endl;
    }
    else {
        cout << "Amount must be a multiple of 50. Please try again." << endl;
    }
}

int login(int count) {
    int pin;
    cout << "\nEnter Your Pin to Login: ";
    cin >> pin;

    for (int i = 0; i < count; i++) {
        if (pin == stoi(database[i][2])) {
            cout << "Welcome Mr/s " << database[i][0] << " " << database[i][1] << endl;
            return i;
        }
    }

    cout << "Invalid Pin" << endl;
    return -1;
}

void menu() {
    cout << "\n===== ATM MENU =====" << endl;
    cout << "1- Check Your Balance\n";
    cout << "2- Withdraw Money\n";
    cout << "3- Deposit Money\n";
    cout << "4- Exit\n";
}

int checkBalance(int i) {
    cout << "Your Balance is: $" << database[i][3] << endl;
    return 0;
}

int main() {
    int menu_choice;

    cout << "Welcome To 'Money Saver' Bank ATM..." << endl;
    cout << "From The River To The Sea, Palestine Will Be Free ❤️" << endl;
    cout << "\nLet's Create Your Accounts (Max 10)" << endl;

    newuser();
    int userIndex = login(count1);

    if (userIndex == -1) return 0;

    do {
        menu();
        cin >> menu_choice;
        switch (menu_choice) {
        case 1:
            checkBalance(userIndex);
            break;
        case 2: {
            int updatedBalance = WithdrawMoney(stoi(database[userIndex][3]));
            database[userIndex][3] = to_string(updatedBalance);
            break;
        }
        case 3:
            depositMoney(userIndex);
            break;
        case 4:
            cout << "Thank you for using Money Saver ATM. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (menu_choice != 4);
}
