#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    static int totalAccounts;
    static int nextAccountNumber;

public:
    // Constructors
    BankAccount();
    BankAccount(string holder, double initialBalance);

    // Destructor
    ~BankAccount();

    // Getters
    string getAccountHolder() const;
    int getAccountNumber() const;
    double getBalance() const;

    // Member functions
    void deposit(double amount);
    void withdraw(double amount);
    void transfer(BankAccount& toAccount, double amount);
    void printAccountInfo() const;

    // Static function
    static int getTotalAccounts();
};

#endif // BANKACCOUNT_H
