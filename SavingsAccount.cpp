#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : interestRate(5){
	accountType = "Savings-Account"; 
}

void SavingsAccount::deposit(double amount) override{
	if(amount > 0){
		balance += amount;
		std::cout << "You take " << amount << "$ deposit from Bank successfully" << std::endl;
	}
}

void SavingsAccount::withdraw(double amount) override{
	if(amount <= balance){
		balance -= amount;
		std::cout << "You withdraw from balance successfully" << std::endl;
	}else{
		std::cout << "You can't withdraw, the amount is too much" << std::endl;
	}
}

void SavingsAccount::transfer(Account& destionation, double amount){
	if(amount > 0 && amount <= balance){
		destination.balance += amount;
		balance -= amount;
	}
}

void SavingsAccount::showBalance() const override{
	std::cout << "Balance -> " << balance << std::endl;
}

std::string SavingsAccount::getAccountType() const override{
	return accountType;
}

void SavingsAccount::setInterestRate(double value){
	if(value > 0){
		interestRate = value;
	}
}
