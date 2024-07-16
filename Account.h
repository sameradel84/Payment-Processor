// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// Define Account class
class Account {
private:
    std::string accountId;
    std::string ownerName;
    double balance;

public:
    Account(const std::string& id, const std::string& name, double initialBalance);
    const std::string& getAccountId() const;
    const std::string& getOwnerName() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
};

#endif // ACCOUNT_H
