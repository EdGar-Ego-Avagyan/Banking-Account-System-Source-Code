#include "../header/SavingAccaunt.h"
#include <iostream>

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other) {
    if (this != &other) {
        Account::operator=(other);
        interestRate = other.interestRate;
    }
    return *this;
}

SavingsAccount::SavingsAccount(SavingsAccount&& other) 
    : Account(std::move(other)), interestRate(other.interestRate) {
    other.interestRate = 0.0;
}

SavingsAccount& SavingsAccount::operator=(SavingsAccount&& other)  {
    if (this != &other) {
        Account::operator=(std::move(other));
        interestRate = other.interestRate;
        other.interestRate = 0.0;
    }
    return *this;
}

void SavingsAccount::logTransaction(const std::string& type, double amount) {
    std::cout << "Transaction Type: " << type << ", Amount: $" << amount << std::endl;
}

void SavingsAccount::showTransactionHistory() const {
    std::cout << "Showing transaction history for Savings Account." << std::endl;
}

void SavingsAccount::deposit(double amount) {
    balance += amount;
    logTransaction("Deposit", amount);
}

void SavingsAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        logTransaction("Withdraw", amount);
    } else {
        std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
    }
}

void SavingsAccount::transfer(Account& obj, double amount) {
    if (balance >= amount) {
        balance -= amount;
        obj.deposit(amount);
        logTransaction("Transfer", amount);
    } else {
        std::cout << "Insufficient funds. Transfer failed." << std::endl;
    }
}

void SavingsAccount::showBalance() const {
    std::cout << "Savings Account Balance: $" << balance << std::endl;
}

std::string SavingsAccount::getAccountType() const {
    return "Savings Account";
}
