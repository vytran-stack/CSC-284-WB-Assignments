#include "BankAccount.h"
#include <stdexcept>

int BankAccount::totalAccounts = 0;
int BankAccount::nextAccountNumber = 1001;

// Default constructor
BankAccount::BankAccount() {
    accountHolder = "Unknown";
    balance = 0.0;
    accountNumber = nextAccountNumber++;
    totalAccounts++;
}

// Parameterized constructor
BankAccount::BankAccount(string holder, double initialBalance) {
    accountHolder = holder;
    balance = initialBalance;
    accountNumber = nextAccountNumber++;
    totalAccounts++;
}

// Destructor
BankAccount::~BankAccount() {
    totalAccounts--;
    cout << "Destructor called for account " << accountNumber << endl;
}

// Getter functions
string BankAccount::getAccountHolder() const {
    return accountHolder;
}

int BankAccount::getAccountNumber() const {
    return accountNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

// Deposit function
void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount must be positive");
    }
    balance += amount;
}

// Withdraw function
void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount must be positive");
    }
    if (amount > balance) {
        throw invalid_argument("Insufficient funds");
    }
    balance -= amount;
}

// Transfer function
void BankAccount::transfer(BankAccount& toAccount, double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount must be positive");
    }
    if (amount > balance) {
        throw invalid_argument("Insufficient funds");
    }
    balance -= amount;
    toAccount.balance += amount;
    cout << "Transferred $" << amount << " from " << accountHolder << " to " << toAccount.accountHolder << endl;
}

// Static function to get total accounts
int BankAccount::getTotalAccounts() {
    return totalAccounts;
}

// Print account info
void BankAccount::printAccountInfo() const {
    cout << "Account Holder: " << accountHolder << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
}
