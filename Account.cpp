// Account.cpp
#include "Account.h"

// Constructor for Account
Account::Account(const std::string& id, const std::string& name, double initialBalance)
    : accountId(id), ownerName(name), balance(initialBalance) {}

// Get account ID
const std::string& Account::getAccountId() const {
    return accountId;
}

// Get owner name
const std::string& Account::getOwnerName() const {
    return ownerName;
}

// Get account balance
double Account::getBalance() const {
    return balance;
}

// Deposit amount into account
void Account::deposit(double amount) {
    balance += amount;
}

// Withdraw amount from account
bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}
