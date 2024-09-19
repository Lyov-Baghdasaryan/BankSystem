#ifndef TransactionManager_H
#define TransactionManager_H
#include <iostream>

class  TransactionManager
{
	public:
		virtual void logTransaction(const std::string& type, double amount) = 0;
		virtual void showTransactionHistory() const = 0;
};

#endif
