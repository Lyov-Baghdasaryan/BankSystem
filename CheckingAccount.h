#ifndef CheckingAccount_H
#define CheckingAccount_H
#include "account.h"
//#include "TransactionManager.cpp"
#include <iostream>

class CheckingAccount : public Account //, public TransactionManager
{
	public:
		CheckingAccount();
		//CheckingAccount(int accNum, int balane, );
		void deposit(double amount) override;
		void withdraw(double amount) override;
		void transfer(Account& destionation, double amount) override;
		void showBalance() const override;
		std::string getAccountType() const override;
		
		void setOverdraftLimit(double limit);
		~CheckingAccount() = default;
	private:
		double overdraftLimit;
	
};

#endif
