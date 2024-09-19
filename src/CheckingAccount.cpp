#include "../header/CheckingAccount.h"
#include "../header/Transaction.h"

CheckingAccount::CheckingAccount() : overdraftLimit(500){
	m_accountType = "Checking-Account";
}

void CheckingAccount::deposit(double amount){
	if(amount > 0 && amount < overdraftLimit){
		Transaction* ptr = new Transaction(nullptr, this, amount, "Deposite");
		m_accountTransaction.push_back(ptr);
		
		m_balance += amount;
		overdraftLimit -= amount;
		std::cout << "You take " << amount << "$ deposit from Bank successfully" << std::endl;
	}else{
		std::cout << "Invalid amount, the transation was failed" << std::endl;
		return;
	}	
}

void CheckingAccount::withdrow(double amount){
	if(amount > 0 && amount <= m_balance + overdraftLimit){
		Transaction* ptr = new Transaction(this, nullptr, amount, "Deposite");
		m_accountTransaction.push_back(ptr);
		
		if(amount <= m_balance){
			m_balance -= amount;
			std::cout << "You withdraw from balance successfully" << std::endl;
		}else{
			int overdraft = amount - m_balance;
			m_balance = 0;
			overdraftLimit -= overdraft;
			std::cout << "You withdraw from balance, but with overdrafting from bank " << overdraft << " $" << std::endl;
		}	
	}else{
		std::cout << "Invalid amount, the transation was failed" << std::endl;
		return;
	}
}

void CheckingAccount::transfer(Account& destination, double amount){
	if(amount > 0 && amount <= m_balance + overdraftLimit){
		Transaction* ptr = new Transaction(this, &destination, amount, "Deposite");
		m_accountTransaction.push_back(ptr);
		
		if(amount <= m_balance){
			m_balance -= amount;
			std::cout << "You withdraw from balance successfully" << std::endl;
		}else{
			int overdraft = amount - m_balance;
			m_balance = 0;
			overdraftLimit -= overdraft;
			std::cout << "You withdraw from balance, but with overdrafting from bank " << overdraft << " $" << std::endl;
		}
		destination.setBalance(destination.getBalance() + amount);
	}else{
		std::cout << "Invalid amount, the transation was failed" << std::endl;
		return;
	}
}

void CheckingAccount::showBalance() const{
	std::cout << "Balance -> " << m_balance << std::endl;
}

std::string CheckingAccount::getAccountType() const{
	return m_accountType;
}
	
void CheckingAccount::setOverdraftLimit(double limit){
	if(limit > 0){
		overdraftLimit = limit;
	}	
}

void CheckingAccount::showTransactionHistory() const{
	for(int i = 0; i < m_accountTransaction.size(); i++){
		m_accountTransaction[i]->log();
	}
}

void CheckingAccount::logTransaction(const std::string& type, double amount){
	for(int i = 0; i < m_accountTransaction.size(); i++){
		if(m_accountTransaction[i]->getType() == type && m_accountTransaction[i]->getAmount() == amount){
			m_accountTransaction[i]->log();
		}
	}
	std::cout << " ";
	return;
}