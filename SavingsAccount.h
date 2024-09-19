#ifndef SavingsAccount_H
#define SavingsAccount_H
#include <iostream>

class SavingsAccount : public Account
{
	public:
		SavingsAccount();
		void deposit(double amount) override;
		void withdrow(double amount) override;
		void transfer(Account& destionation, double amount) override;
		void showBalance() const override;
		std::string getAccountType() const override;
		
		void setInterestRate(double value);
		~SavingsAccount() = default;
	private:
		double interestRate;
}

#endif
