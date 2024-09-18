#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "TransactionManager.h"

class Transaction;

class Account {
public:
    Account() : accountNumber(0), balance(0.0), accountType("Undefined") {}
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void transfer(Account& obj, double amount) = 0;
    virtual void showBalance() const = 0;
    virtual std::string getAccountType() const = 0;
    virtual ~Account() {}

protected:
    int accountNumber;
    double balance;
    std::string accountType;
};

#endif // ACCOUNT_H
