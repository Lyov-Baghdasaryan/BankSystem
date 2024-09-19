#ifndef Account_H
#define Account_H
#include <iostream>
#include <vector>
#include "Transaction.h"

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
		void setBalance(double value);
		double getBalance() const;
		virtual ~Account();
		
	protected:
		int m_accountNumber;
		double m_balance;
		std::string m_accountType;
		std::vector<Transaction*> m_accountTransaction;
		//Customer* accountOwner;
};

#endif
