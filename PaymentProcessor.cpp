// PaymentProcessor.cpp
#include "PaymentProcessor.h"
#include <iostream>

// Create a new account
#include <mutex>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Forward declaration of Transaction class
class Transaction {
public:
    Transaction(const std::string& transactionId, const std::string& fromAccountId, const std::string& toAccountId, double amount)
        : transactionId(transactionId), fromAccountId(fromAccountId), toAccountId(toAccountId), amount(amount) {}

    std::string getTransactionId() const { return transactionId; }
    std::string getFromAccountId() const { return fromAccountId; }
    std::string getToAccountId() const { return toAccountId; }
    double getAmount() const { return amount; }

private:
    std::string transactionId;
    std::string fromAccountId;
    std::string toAccountId;
    double amount;
};

class Account {
public:
    Account(const std::string& accountId, const std::string& ownerName, double initialBalance)
        : accountId(accountId), ownerName(ownerName), balance(initialBalance) {}

    std::string getAccountId() const { return accountId; }
    std::string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            std::cerr << "Insufficient funds for account " << accountId << std::endl;
            return false;
        }
    }

private:
    std::string accountId;
    std::string ownerName;
    double balance;
};

class PaymentProcessor {
public:
    void createAccount(const std::string& ownerName, double initialBalance) {
        std::string accountId = "Accountid" + std::to_string(accounts.size() + 1);
        Account newAccount(accountId, ownerName, initialBalance);
        mtx.lock();
        accounts.insert({accountId, newAccount});
        mtx.unlock();
        std::cout << "Created account: " << accountId << " for " << ownerName << std::endl;
    }

    bool processTransaction(const std::string& fromAccountId, const std::string& toAccountId, double amount) {
        mtx.lock();
        if (accounts.find(fromAccountId) == accounts.end() || accounts.find(toAccountId) == accounts.end()) {
            std::cerr << "Error: accounts not found." << std::endl;
            mtx.unlock();
            return false;
        }

        Account& fromAccount = accounts[fromAccountId];
        Account& toAccount = accounts[toAccountId];

        if (!fromAccount.withdraw(amount)) {
            std::cerr << "Error: not enough funds in account " << fromAccountId << std::endl;
            mtx.unlock();
            return false;
        }

        toAccount.deposit(amount);

        Transaction newTransaction("Transactions" + std::to_string(transactions.size() + 1), fromAccountId, toAccountId, amount);
        transactions.push_back(newTransaction);

        mtx.unlock();
        std::cout << "Transaction processed: " << newTransaction.getTransactionId()
                  << " from " << fromAccountId << " to " << toAccountId << " amount " << amount << std::endl;
        return true;
    }

    double getAccountBalance(const std::string& accountId) {
        mtx.lock();
        if (accounts.find(accountId) == accounts.end()) {
            std::cerr << "Error: Account " << accountId << " does not exist." << std::endl;
            mtx.unlock();
            return -1.0;
        }

        double balance = accounts[accountId].getBalance();
        mtx.unlock();
        return balance;
    }

private:
    std::mutex mtx;
    std::unordered_map<std::string, Account> accounts;
    std::vector<Transaction> transactions;
};
