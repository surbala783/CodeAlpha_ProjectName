#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction Class
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

// Account Class
class Account {
public:
    int accountNo;
    double balance;
    vector<Transaction> history;

    Account(int accNo) {
        accountNo = accNo;
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount <= balance) {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void showTransactions() {
        cout << "\nTransaction History:\n";
        for (int i = 0; i < history.size(); i++) {
            cout << history[i].type << " : Rs." << history[i].amount << endl;
        }
    }

    void showAccountInfo() {
        cout << "\nAccount Number : " << accountNo;
        cout << "\nCurrent Balance : Rs." << balance << endl;
    }
};

// Customer Class
class Customer {
public:
    int customerId;
    string name;
    Account account;

    Customer(int id, string n, int accNo)
        : account(accNo) {
        customerId = id;
        name = n;
    }

    void showCustomerInfo() {
        cout << "\nCustomer ID : " << customerId;
        cout << "\nCustomer Name : " << name << endl;
        account.showAccountInfo();
    }
};

int main() {
    Customer c1(101, "Rahul", 1001);
    Customer c2(102, "Priya", 1002);

    c1.account.deposit(5000);
    c1.account.withdraw(1000);
    c1.account.transfer(c2.account, 1500);

    cout << "\n===== Customer 1 Details =====";
    c1.showCustomerInfo();
    c1.account.showTransactions();

    cout << "\n\n===== Customer 2 Details =====";
    c2.showCustomerInfo();
    c2.account.showTransactions();

    return 0;
}
