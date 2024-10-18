#pragma once
#include <string>
#include <iostream>

class Account {
public:
	Account(int accountNumber,
		std::string owner,
		double balance)
	{
		this->accountNumber = accountNumber;
		this->owner = owner;
		this->balance = balance;
	}

	virtual void deposit(double amount)
	{
		if (amount > 0) {
			this->balance += amount;
			std::cout << "Successfully deposited " << amount << ". New balance: " << balance << std::endl;
		}
		else {
			std::cout << "Invalid deposit amount!" << std::endl;
		}
	}

	virtual void withdraw(double amount)
	{
		if (this->balance >= amount)
		{
			this->balance -= amount;
			std::cout << "You have successfully withdrew " << amount << "lv. ";
		}
		else {
			std::cout << "Insufficient funds.";
		}
	}

	void displayAccountInfo() const {
		std::cout << "Account Number: " << accountNumber << std::endl;
		std::cout << "Owner Name: " << owner << std::endl;
		std::cout << "Balance: " << balance << std::endl;
	}

	double getBalance() const {
		return balance;
	}

	void setBalance(double newBalance) {
		balance = newBalance;
	}

	int getAccountNumber() const {
		return accountNumber;
	}
private:
	int accountNumber;
	std::string owner;
	double balance;


};
