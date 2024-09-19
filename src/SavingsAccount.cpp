#include "../header/SavingsAccount.h"

SavingsAccount::SavingsAccount() : interestRate(5){
	accountType = "Savings-Account"; 
}

void SavingsAccount::deposit(double amount){
	if(amount > 0){
		balance += amount;
		std::cout << "You take " << amount << "$ deposit from Bank successfully" << std::endl;
	}
}

void SavingsAccount::withdrow(double amount){
	if(amount <= balance){
		balance -= amount;
		std::cout << "You withdraw from balance successfully" << std::endl;
	}else{
		std::cout << "You can't withdraw, the amount is too much" << std::endl;
	}
}

void SavingsAccount::transfer(Account& destination, double amount){
	if(amount > 0 && amount <= balance){
		destination.setBalance(destination.getBalance() + amount);
		balance -= amount;
	}
}

void SavingsAccount::showBalance() const{
	std::cout << "Balance -> " << balance << std::endl;
}

std::string SavingsAccount::getAccountType() const{
	return accountType;
}

void SavingsAccount::setInterestRate(double value){
	if(value > 0){
		interestRate = value;
		m_balance += (m_balance/100) * interestRate;
	}
}