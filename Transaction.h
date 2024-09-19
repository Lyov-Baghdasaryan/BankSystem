#ifndef Transaction_H
#define Transaction_H
#include "TransactionManager.h"
#include <iostream>
//#include <chrono>

class Transaction : public TransactionManager
{
	public:
		void logTransaction(const std::string& type, double amount) override;
		void showTransactionHistory() const override;
		void log();
	private:
		Account* fromAccount;
		Account* toAccount;
		double amount;
		std::string transactionType;
		//std::chrono::time_point timestamp;
};

#endif
