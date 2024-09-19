#ifndef Transaction_H
#define Transaction_H
#include <iostream>
#include "Account.h"
//#include <chrono>

class Transaction
{
	public:
		Transaction(Account* fromAccount, Account* toAccount, double amount, const std::string& transactionType);
		std::string getType();
		double getAmount();
		void log();
	protected:
		Account* m_fromAccount;
		Account* m_toAccount;
		double m_amount;
		std::string m_transactionType;
		//std::chrono::time_point timestamp;
};

#endif
