#include <iostream>
#include "BankAccount.h"

int main() {

    BankAccount account1("Alice", 1000);
    BankAccount account2("Bob", 500);

    account1.printAccountInfo();
    account2.printAccountInfo();

    account1.deposit(200);
    account2.withdraw(100);

    account1.printAccountInfo();
    account2.printAccountInfo();

    cout << "Total active accounts: " << BankAccount::getTotalAccounts() << endl;

    account1.transfer(account2, 250);

    account1.printAccountInfo();
    account2.printAccountInfo();

    return 0;
}