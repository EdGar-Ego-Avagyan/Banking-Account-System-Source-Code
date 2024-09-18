#include "../header/CheckingAccaunt.h"
#include <iostream>

CheckingAccount::CheckingAccount(const CheckingAccount& obj)
    : Account(obj), overdraftLimit(obj.overdraftLimit) {}

CheckingAccount& CheckingAccount::operator=(const CheckingAccount& other) {
    if (this != &other) { 
        
        overdraftLimit = other.overdraftLimit;
    }
    return *this;
}

CheckingAccount::CheckingAccount(CheckingAccount&& other) 
    : Account(std::move(other)), overdraftLimit(other.overdraftLimit)
{
    other.overdraftLimit = 0;
}

CheckingAccount& CheckingAccount::operator=(CheckingAccount&& other)  {
    if (this != &other) {
        Account::operator=(std::move(other)); 
        overdraftLimit = other.overdraftLimit;
        other.overdraftLimit = 0; 
    }
    return *this;
}

void CheckingAccount::logTransaction(const std::string& type, double amount) {
    std::cout << "Transaction Type: " << type << ", Amount: $" << amount << std::endl;
}

void CheckingAccount::showTransactionHistory() const {
    std::cout << "Showing transaction history for Checking Account." << std::endl;
}

void CheckingAccount::deposit(double amount) {
    balance += amount;
    logTransaction("Deposit", amount);
}

void CheckingAccount::withdraw(double amount) {
    if (balance + overdraftLimit >= amount) {
        balance -= amount;
        logTransaction("Withdraw", amount);
    } else {
        std::cout << "Insufficient funds. Withdrawal failed." << std::endl;
    }
}

void CheckingAccount::transfer(Account& obj, double amount) {
    if (balance + overdraftLimit >= amount) {
        balance -= amount;
        obj.deposit(amount); 
        logTransaction("Transfer", amount);
    } else {
        std::cout << "Insufficient funds. Transfer failed." << std::endl;
    }
}

void CheckingAccount::showBalance() const {
    std::cout << "Checking Account Balance: $" << balance << std::endl;
}

std::string CheckingAccount::getAccountType() const {
    return "Checking Account";
}
