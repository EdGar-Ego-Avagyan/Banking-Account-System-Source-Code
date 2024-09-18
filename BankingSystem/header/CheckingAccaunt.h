#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Accaunt.h"
#include "TransactionManager.h"

class CheckingAccount : public Account, public TransactionManager {
public:
    CheckingAccount() : overdraftLimit(0.0) {}
    CheckingAccount(double overLimit) : overdraftLimit(overLimit) {}
    CheckingAccount(const CheckingAccount& obj);
    CheckingAccount& operator=(const CheckingAccount& other);
    CheckingAccount(CheckingAccount&& other) ;
    CheckingAccount& operator=(CheckingAccount&& other);

    void logTransaction(const std::string& type, double amount) override;
    void showTransactionHistory() const override;

    void deposit(double amount) override;
    void withdraw(double amount) override;
    void transfer(Account& obj, double amount) override;
    void showBalance() const override;
    std::string getAccountType() const override;

private:
    double overdraftLimit;
};

#endif // CHECKINGACCOUNT_H
