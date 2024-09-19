#ifndef Account_H
#define Account_H
#include <iostream>
#include <vector>
//#include "Transaction.h"

class Account
{	
	public:
		Account();
		//Account(double amount);
		Account(const Account&) = delete;

		virtual void deposit(double amount) = 0;
		virtual void withdrow(double amount) = 0;
		virtual void transfer(Account& destionation, double amount) = 0;
		virtual void showBalance() const = 0;
		virtual std::string getAccountType() const = 0;
		virtual ~Account();
	protected:
		int accountNumber;
		double balance;
		std::string accountType;
		std::vector<Transaction*> accountTransaction;
		//Customer* accountOwner;
};

#endif
