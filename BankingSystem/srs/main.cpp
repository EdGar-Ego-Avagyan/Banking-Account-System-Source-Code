#include <string>
#include "../header/CheckingAccaunt.h"
#include "../header/JoinAccaunt.h"
#include "../header/SavingAccaunt.h"
int main() {
    CheckingAccount checking(500.0); 
    checking.deposit(1000.0); 
    checking.showBalance(); 
    checking.withdraw(200.0); 
    checking.showBalance(); 

    
    SavingsAccount savings(0.03); 
    savings.deposit(2000.0); 
    savings.showBalance(); 

    
    std::vector<std::string> owners;
    owners.push_back("Garegin");
    owners.push_back("Shahen");
    JointAccount joint(owners);
    joint.deposit(1500.0); 
    joint.showBalance(); 
    joint.addCustomer("Styopa"); 
    joint.showTransactionHistory(); 

    
    checking.transfer(savings, 500.0); 
    checking.showBalance(); 
    savings.showBalance(); 

    return 0;
}
