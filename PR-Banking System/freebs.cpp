#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string accountType;
    float balance;

public:
    void setAccountDetails(string accNum, string accType, float initialBalance) {
        accountNumber = accNum;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    float getBalance() {
        return balance;
    }
};

class SavingsAccount : public Account {
public:
    void calculateInterest(float interestRate) {
        float interest = getBalance() * interestRate / 100;
        deposit(interest);
    }
};

class CurrentAccount : public Account {
private:
    float overdraftLimit;

public:
    void setOverdraftLimit(float limit) {
        overdraftLimit = limit;
    }

    void withdraw(float amount) {
        if (getBalance() + overdraftLimit >= amount) {
            Account::withdraw(amount);
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

class Bank {
private:
    Account* accounts[100]; // fixed-size array to store 100 accounts
    int numAccounts;

public:
    Bank() : numAccounts(0) {}

    void createAccount(string accNum, string accType, float initialBalance) {
        if (accType == "Savings") {
            SavingsAccount* savingsAcc = new SavingsAccount();
            savingsAcc->setAccountDetails(accNum, accType, initialBalance);
            accounts[numAccounts++] = savingsAcc;
        } else if (accType == "Current") {
            CurrentAccount* currentAcc = new CurrentAccount();
            currentAcc->setAccountDetails(accNum, accType, initialBalance);
            accounts[numAccounts++] = currentAcc;
        }
    }

    void deposit(string accNum, float amount) {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i]->getAccountNumber() == accNum) {
                accounts[i]->deposit(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void withdraw(string accNum, float amount) {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i]->getAccountNumber() == accNum) {
                accounts[i]->withdraw(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void displayAccountDetails(string accNum) {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i]->getAccountNumber() == accNum) {
                accounts[i]->displayAccountDetails();
                return;
            }
        }
        cout << "Account not found." << endl;
    }
};

int main() {
    Bank bank;

    bank.createAccount("SB-123", "Savings", 1000);
    bank.createAccount("CA-456", "Current", 500);

    bank.deposit("SB-123", 500);
    bank.withdraw("CA-456", 200);

    bank.displayAccountDetails("SB-123");
    bank.displayAccountDetails("CA-456");

    return 0;
}