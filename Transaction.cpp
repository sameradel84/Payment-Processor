// Transaction.cpp
#include "Transaction.h"

// Constructor for Transaction
Transaction::Transaction(const std::string& id, const std::string& from, const std::string& to, double amt)
    : transactionId(id), fromAccountId(from), toAccountId(to), amount(amt) {
        timestamp = std::time(nullptr); // current time
    }

// Get transaction ID
const std::string& Transaction::getTransactionId() const {
    return transactionId;
}

// Get from account ID
const std::string& Transaction::getFromAccountId() const {
    return fromAccountId;
}

// Get to account ID
const std::string& Transaction::getToAccountId() const {
    return toAccountId;
}

// Get transaction amount
double Transaction::getAmount() const {
    return amount;
}

// Get transaction timestamp
std::time_t Transaction::getTimestamp() const {
    return timestamp;
}
