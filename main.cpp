// main.cpp
#include "PaymentProcessor.h"
#include <iostream>

int main() {
    PaymentProcessor processor;

    // Create two accounts
    processor.createAccount("samer", 50000.0);
    processor.createAccount("adel", 20000.0);

    // Process a transaction
    processor.processTransaction("account1", "account2", 3000.0);

    // Display current balances
    std::cout << "the balance of samer is: " << processor.getAccountBalance("account1") << std::endl;
    std::cout << "the balance of adel is : " << processor.getAccountBalance("account2") << std::endl;

    return 0;
}
