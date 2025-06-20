#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string note;

    Transaction(string type, double amount, string note = "")
        : type(type), amount(amount), note(note) {}
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo) : accountNumber(accNo), balance(0.0) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions.push_back(Transaction("Deposit", amount));
            cout << "Deposit successful.\n";
        }
        else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount));
            cout << "Withdrawal successful.\n";
        }
        else {
            cout << "Invalid or insufficient funds.\n";
        }
    }

    bool transfer(Account& receiver, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            receiver.balance += amount;
            transactions.push_back(Transaction("Transfer Sent", amount, "To Account " + to_string(receiver.accountNumber)));
            receiver.transactions.push_back(Transaction("Transfer Received", amount, "From Account " + to_string(accountNumber)));
            return true;
        }
        return false;
    }

    void showTransactions() const {
        cout << "\nTransaction History for Account " << accountNumber << ":\n";
        for (const auto& t : transactions) {
            cout << t.type << " - Rs. " << t.amount;
            if (!t.note.empty()) cout << " (" << t.note << ")";
            cout << endl;
        }
    }

    void showAccountInfo() const {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

class Customer {
private:
    string name;
    Account account;

public:
    Customer(string name, int accountNumber)
        : name(name), account(accountNumber) {}

    string getName() const {
        return name;
    }

    Account& getAccount() { // for non-const use
        return account;
    }

    const Account& getAccount() const { // for const use
        return account;
    }

    void displayCustomerInfo() const {
        cout << "\nCustomer: " << name << endl;
        account.showAccountInfo();
    }
};

// Main menu
int main() {
    vector<Customer> customers;
    int choice;

    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Show Account Info\n";
        cout << "6. Show Transactions\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        int accNum, toAccNum;
        double amount;
        string name;

        switch (choice) {
        case 1:
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            accNum = customers.size() + 1001; // simple unique acc number
            customers.push_back(Customer(name, accNum));
            cout << "Account created with Account Number: " << accNum << endl;
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            for (auto& c : customers) {
                if (c.getAccount().getAccountNumber() == accNum) {
                    c.getAccount().deposit(amount);
                    break;
                }
            }
            break;

        case 3:
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            for (auto& c : customers) {
                if (c.getAccount().getAccountNumber() == accNum) {
                    c.getAccount().withdraw(amount);
                    break;
                }
            }
            break;

        case 4:
            cout << "Enter your account number: ";
            cin >> accNum;
            cout << "Enter receiver account number: ";
            cin >> toAccNum;
            cout << "Enter amount to transfer: ";
            cin >> amount;
            {
                Account* sender = nullptr;
                Account* receiver = nullptr;

                for (auto& c : customers) {
                    if (c.getAccount().getAccountNumber() == accNum) sender = &c.getAccount();
                    if (c.getAccount().getAccountNumber() == toAccNum) receiver = &c.getAccount();
                }

                if (sender && receiver) {
                    if (sender->transfer(*receiver, amount)) {
                        cout << "Transfer successful.\n";
                    }
                    else {
                        cout << "Transfer failed. Check balance.\n";
                    }
                }
                else {
                    cout << "Invalid account numbers.\n";
                }
            }
            break;

        case 5:
            cout << "Enter account number: ";
            cin >> accNum;
            for (const auto& c : customers) {
                if (c.getAccount().getAccountNumber() == accNum) {
                    c.displayCustomerInfo();
                    break;
                }
            }
            break;

        case 6:
            cout << "Enter account number: ";
            cin >> accNum;
            for (const auto& c : customers) {
                if (c.getAccount().getAccountNumber() == accNum) {
                    c.getAccount().showTransactions();
                    break;
                }
            }
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
