#ifndef CheckingAccount_H
#define CheckingAccount_H
#include "Account.h"
#include "TransactionManager.h"
#include <iostream>

class CheckingAccount : public Account, public TransactionManager
{
	public:
		CheckingAccount();
		CheckingAccount(int accNum, int balance, const std::string& accType);
		void deposit(double amount) override;
		void withdrow(double amount) override;
		void transfer(Account& destionation, double amount) override;
		void showBalance() const override;
		std::string getAccountType() const override;
		void logTransaction(const std::string& type, double amount, Account* toAccount) override;
		void showTransactionHistory() const override;
		
		void setOverdraftLimit(double limit);
		~CheckingAccount() = default;
	private:
		double overdraftLimit;
	
};

#endif
