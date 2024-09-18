#include "../header/JoinAccaunt.h"
#include <iostream>

JointAccount::JointAccount(const JointAccount& other)
    : Account(other), jointOwners(other.jointOwners) {}

JointAccount& JointAccount::operator=(const JointAccount& other) {
    if (this != &other) { 
        Account::operator=(other); 
        jointOwners = other.jointOwners;
    }
    return *this;
}


JointAccount::JointAccount(JointAccount&& other)
    : Account(std::move(other)), jointOwners(std::move(other.jointOwners)) {}

JointAccount& JointAccount::operator=(JointAccount&& other) {
    if (this != &other) { 
        Account::operator=(std::move(other)); 
        jointOwners = std::move(other.jointOwners);
    }
    return *this;
}

void JointAccount::logTransaction(const std::string& type, double amount) {
    std::cout << "Transaction Type: " << type << ", Amount: $" << amount << std::endl;
}

void JointAccount::showTransactionHistory() const {
    
    std::cout << "Showing transaction history for Joint Account." << std::endl;
}

void JointAccount::deposit(double amount) {
    balance += amount;
    logTransaction("Deposit", amount);
}

void JointAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        logTransaction("Withdraw", amount);
    } else {
        std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
    }
}

void JointAccount::transfer(Account& obj, double amount) {
    if (balance >= amount) {
        balance -= amount;
        obj.deposit(amount);
        logTransaction("Transfer", amount);
    } else {
        std::cout << "Insufficient funds. Transfer failed." << std::endl;
    }
}

void JointAccount::showBalance() const {
    std::cout << "Joint Account Balance: $" << balance << std::endl;
}

std::string JointAccount::getAccountType() const {
    return "Joint Account";
}

void JointAccount::addCustomer(const std::string& customerName) {
    jointOwners.push_back(customerName);
    std::cout << "Added joint owner: " << customerName << std::endl;
}
