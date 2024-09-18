#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include "Accaunt.h"

class Transaction {
public:
    Transaction(Account* from, Account* to, double amount, const std::string& type,int timestamp)
        : fromAccount(from), toAccount(to), amount(amount), transactionType(type), 
          timestamp(timestamp) {}

    void log() {
        std::cout << "Transaction Type: " << transactionType
                  << "\nFrom Account: " << fromAccount->getAccountType()
                  << "\nTo Account: " << (toAccount ? toAccount->getAccountType() : "N/A")
                  << "\nAmount: $" << amount
                  << "\nTimestamp: " << timestamp
                  << std::endl;
    }

private:
    Account* fromAccount;
    Account* toAccount;
    double amount;
    std::string transactionType;
    int timestamp;
};

#endif // TRANSACTION_H
