#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Accaunt.h"
#include "TransactionManager.h"
class SavingsAccount : public Account, public TransactionManager {
public:
    SavingsAccount() : interestRate(0.0) {}
    SavingsAccount(double interRate) : interestRate(interRate) {}
    SavingsAccount(const SavingsAccount& other) : interestRate(other.interestRate) {}
    SavingsAccount& operator=(const SavingsAccount& other);
    SavingsAccount(SavingsAccount&& other);
    SavingsAccount& operator=(SavingsAccount&& other);

    void logTransaction(const std::string& type, double amount) override;
    void showTransactionHistory() const override;

    void deposit(double amount) override;
    void withdraw(double amount) override;
    void transfer(Account& obj, double amount) override;
    void showBalance() const override;
    std::string getAccountType() const override;

private:
    double interestRate;
};

#endif // SAVINGSACCOUNT_H
