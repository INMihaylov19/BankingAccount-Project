#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Account.h"
#include "CheckingAccount.h"

class TestBank {
public:
    std::vector<Account*> accounts;
    void run()
    {
        try {

            for (int i = 0; i < 2; i++)
            {
                int accountNumber;
                std::string owner;
                double balance;

                std::cout << "\nEnter details for Account " << i + 1 << std::endl;

                std::cout << "Enter Account number: ";
                std::cin >> accountNumber;

                if (accountNumber <= 0 || accountNumber != static_cast<int>(accountNumber))
                {
                    throw std::invalid_argument("Enter a valid integer for account number!");
                }

                std::cout << "Enter Owner Name: ";
                std::cin.ignore();
                std::getline(std::cin, owner);

                std::cout << "Enter Balance: ";
                std::cin >> balance;
                if (balance < 0 || balance != static_cast<int>(balance))
                {
                    throw std::invalid_argument("Enter a valid balance amount!");
                }

                accounts.push_back(new Account(accountNumber, owner, balance));
            }

            for (int i = 0; i < 2; i++)
            {
                int accountNumber;
                std::string owner;
                double balance;

                std::cout << "\nEnter details for Checking Account " << i + 1 << std::endl;

                std::cout << "Enter Account number: ";
                std::cin >> accountNumber;

                if (accountNumber <= 0 || accountNumber != static_cast<int>(accountNumber))
                {
                    throw std::invalid_argument("Enter a valid integer for account number!");
                }

                std::cout << "Enter Owner Name: ";
                std::cin.ignore();
                std::getline(std::cin, owner);

                std::cout << "Enter Balance: ";
                std::cin >> balance;
                if (balance < 0 || balance != static_cast<int>(balance))
                {
                    throw std::invalid_argument("Enter a valid balance amount!");
                }

                accounts.push_back(new CheckingAccount(accountNumber, owner, balance));
            }

            std::cout << "Account details";

            for (auto account : accounts)
            {
                account->displayAccountInfo();
                std::cout << std::endl;
            }

            for (size_t i = 0; i < accounts.size(); i++) {
                if (CheckingAccount* cacc = dynamic_cast<CheckingAccount*>(accounts[i])) {
                    std::cout << "Withdraw 350 from CheckingAccount: " << cacc->getAccountNumber() << std::endl;
                    cacc->withdraw(350);
                }
            }

            for (size_t i = 0; i < 2; i++) {
                if (Account* acc = dynamic_cast<Account*>(accounts[i])) {
                    std::cout << "Deposit 350 to Account: " << acc->getAccountNumber() << std::endl;
                    acc->deposit(350);
                }
            }

            std::cout << "\nUpdated account details:" << std::endl;
            for (auto account : accounts) {
                account->displayAccountInfo();
                std::cout << std::endl;
            }

            for (auto account : accounts) {
                delete account;
            }

        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;

        }
    }
};
