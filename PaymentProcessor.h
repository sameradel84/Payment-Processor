// PaymentProcessor.h
#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

#include <string>
#include <unordered_map>
#include <vector>
#include <mutex>
#include "Account.h"
#include "Transaction.h"

// Define PaymentProcessor class
class PaymentProcessor {
private:
    std::unordered_map<std::string, Account> accounts;
    std::vector<Transaction> transactions;
    std::mutex mtx;

public:
    void createAccount(const std::string& ownerName, double initialBalance);
    bool processTransaction(const std::string& fromAccountId, const std::string& toAccountId, double amount);
    double getAccountBalance(const std::string& accountId);
};

#endif // PAYMENTPROCESSOR_H
