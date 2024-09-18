#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <string>

class TransactionManager {
public:
    virtual void logTransaction(const std::string& type, double amount) = 0;
    virtual void showTransactionHistory() const = 0;
    virtual ~TransactionManager() = default;
};

#endif // TRANSACTIONMANAGER_H
