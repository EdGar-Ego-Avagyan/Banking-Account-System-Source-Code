#ifndef JOINTACCOUNT_H
#define JOINTACCOUNT_H

#include "Accaunt.h"
#include "TransactionManager.h"
#include <vector>
#include <string>

class JointAccount : public Account, public TransactionManager {
public:
    JointAccount() {}
    JointAccount(const JointAccount& other);
    JointAccount& operator=(const JointAccount& other);
    JointAccount(JointAccount&& other);
    JointAccount& operator=(JointAccount&& other);
    JointAccount(const std::vector<std::string>& owners) : jointOwners(owners) {}

    void logTransaction(const std::string& type, double amount) override;
    void showTransactionHistory() const override;

    void deposit(double amount) override;
    void withdraw(double amount) override;
    void transfer(Account& obj, double amount) override;
    void showBalance() const override;
    std::string getAccountType() const override;
    void addCustomer(const std::string& customerName);

private:
    std::vector<std::string> jointOwners;
};

#endif // JOINTACCOUNT_H
