#ifndef Customer_H
#define Customer_H
#include "Account.h"

class SavingsAccount : public Account
{
	public:
		void deposit(double amount) override;
		void withdrow(double amount) override;

	private:
		double interestRate;
};

#endif
