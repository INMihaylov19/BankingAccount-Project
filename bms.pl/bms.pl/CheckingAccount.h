#pragma once
#include "Account.h"

class CheckingAccount : public Account{
public:
	CheckingAccount(int accountNumber,
		std::string owner,
		double balance) : Account(accountNumber, owner, balance)
	{
		this->bankingOperationsCount = 0;
	}

	void deposit(double amount) override
	{
		if (amount > 0)
		{
			this->bankingOperationsCount++;
			this->setBalance(this->getBalance() + amount);
			std::cout << "Deposit: " << amount << ". New balance: " << this->getBalance() << std::endl;
			std::cout << "Operations this month: " << this->bankingOperationsCount << std::endl;
		}
		else {
			std::cout << "Invalid deposit amount!" << std::endl;
		}
	}

	void withdraw(double amount) override
	{
		if (amount <= this->getBalance())
		{
			this->bankingOperationsCount++;
			this->setBalance(this->getBalance() - amount);
			std::cout << "Withdraw: " << amount << ". New balance: " << this->getBalance() << std::endl;
			std::cout << "Operations this month: " << this->bankingOperationsCount << std::endl;
		}
		else {
			std::cout << "Insufficient funds!" << std::endl;
		}
	}

private:
	int bankingOperationsCount;
};