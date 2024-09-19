#include <CheckingAccount.h>	
//#include "Trasaction.h"

CheckingAccount::CheckingAccount() : overdraftLimit(500){
	accountType = "Checking-Account";
}

void CheckingAccount::deposit(double amount){
	if(amount > 0 && amount < overdraftLimit){
		//Transaction* ptr = new Transaction(nullptr, this, amount, "Deposite");
		balance += amount;
		overdraftLimit -= amount;
		//accountTransaction.push_back(ptr);
		std::cout << "You take " << amount << "$ deposit from Bank successfully" << std::endl;
	}else{
		std::cout << "Invalid amount, the transation was failed" << std::endl;
		return;
	}	
}

void CheckingAccount::withdraw(double amount){
	//Transaction* ptr = new Transaction(this, nullptr, amount, "Deposite");
	//accountTransaction.push_back(ptr);
	if(amount > 0 && amount <= balance + overdraftLimit){
		if(amount <= balance){
			balance -= amount;
			std::cout << "You withdraw from balance successfully" << std::endl;
		}else{
			int overdraft = amount - balance;
			balance = 0;
			overdraftLimit -= overdraft;
			std::cout << "You withdraw from balance, but with overdrafting from bank " << overdraft << " $" << std::endl;
		}	
	}else{
		std::cout << "Invalid amount, the transation was failed" << std::endl;
		return;
	}
}

void CheckingAccount::transfer(Account& destionation, double amount){
	//Transaction* ptr = new Transaction(this, &destination, amount, "Deposite");
	//accountTransaction.push_back(ptr);
	if(amount > 0 && amount <= balance + overdraftLimit){
		if(amount <= balance){
			balance -= amount;
			std::cout << "You withdraw from balance successfully" << std::endl;
		}else{
			int overdraft = amount - balance;
			balance = 0;
			overdraftLimit -= overdraft;
			std::cout << "You withdraw from balance, but with overdrafting from bank " << overdraft << " $" << std::endl;
		}
		destination.balance += amount;
	}else{
		std::cout << "Invalid amount, the transation was failed" << std::endl;
		return;
	}
}

void CheckingAccount::showBalance() const{
	std::cout << "Balance -> " << balance << std::endl;
}

std::string CheckingAccount::getAccountType() const{
	return accountType;
}
	
void CheckingAccount::setOverdraftLimit(double limit){
	if(limit > 0){
		overDraftLimit = limit;
	}	
}

/*
void CheckingAccount::showTransactionType() const{
	for(int i = 0; i < accountTransaction.size(); i++){
		accountTransactionHistory[i]->log();
	}
}

void CheckAccount::logTransaction(const std::string& type, double amount){
	for(int i = 0; i < accountTransaction.size(); i++){
		if(accountTransactionHistory[i]->getType() == type && accountTransaction ...... ){
			accountTransaction[i]->log();
		}
	}
	std::cout << " ";
	return;
}
*/
