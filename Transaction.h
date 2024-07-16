// Transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

// Define Transaction class
class Transaction {
private:
    std::string transactionId;
    std::string fromAccountId;
    std::string toAccountId;
    double amount;
    std::time_t timestamp;

public:
    Transaction(const std::string& id, const std::string& from, const std::string& to, double amt);
    const std::string& getTransactionId() const;
    const std::string& getFromAccountId() const;
    const std::string& getToAccountId() const;
    double getAmount() const;
    std::time_t getTimestamp() const;
};

#endif // TRANSACTION_H
