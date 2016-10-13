// BankApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;



//start of Banking
class Banking
{
protected:
	double balance, interest, monInterest, checkCost, withdraw;
	int actNum;

public:
	Banking()
	{
		balance = 0;
	}
	virtual void display() = 0;
	virtual void get_info() = 0;
};
//end of Banking


//start of Saving
class Saving : public Banking
{
	double savingDep;

public:

	void display()
	{
		printf("\n Savings Account Number: %d\n Balance: %3.2f\n Withdrew: %3.2f\n Interest: %3.2f\n Monthly Interest: %3.2f\n", actNum, balance, interest, monInterest);
	}

	void get_info()
	{
		cout << "Enter Account Number" << endl;
		cin >> actNum;
		cout << "Enter amount of money you wish to deposit" << endl;
		cin >> balance;
		cout << "Withdraw amount: ";
		cin >> withdraw;
		if (balance > 9999)
			interest = .02 * balance;

		else
			interest = .01 * balance;

		monInterest = interest / 12;
		balance = balance + interest - withdraw;
		cin.clear();
		cin.ignore();
	}
};
//end of Saving

//start of Checking
class Checking : public Banking
{
	double checkCount;
public:

	void display()
	{
		printf("\n Checking Account Number: %d\n Balance: %3.2f\n Withdrew: %3.2f\n Interest: %3.2f\n Monthly Interest: %3.2f\n Check Cost %3.2f\n", actNum, balance, interest, monInterest, checkCost);
	}

	void get_info()
	{
		cout << "Enter Account Number" << endl;
		cin >> actNum;
		cout << "Enter amount of money you wish to deposit" << endl;
		cin >> balance;
		interest = 0;
		cout << "Number of checks ordered: ";
		cin >> checkCount;
		checkCost = checkCount * 15;
		cout << "Withdraw amount: ";
		cin >> withdraw;
		if (balance > 500)
			balance = balance - checkCost - withdraw;

		else
			balance = balance - 5 - checkCost - withdraw;

		monInterest = interest / 12;


		cin.clear();
		cin.ignore();
	}
};
// end of Checking

//start of CD
class CD : public Banking
{
public:
	double cdTerm;
	void display()
	{
		printf("\n Certificate of Deposit Account Number: %d\n Balance: %3.2f\n Withdrew: %3.2f\n CD Duration (In Years): %3.2f\n Interest: %3.2f\n Monthly Interest: %3.2f\n", actNum, balance, interest, cdTerm, monInterest);
	}

	void get_info()
	{
		cout << "Enter Account Number: ";
		cin >> actNum;
		cout << "Enter amount of money you wish to deposit: ";
		cin >> balance;
		cout << "Number of year term for your certificate of deposit: ";
		cin >> cdTerm;
		cout << "Withdraw amount: ";
		cin >> withdraw;
		if (withdraw > 0)
			balance = balance * 0.9 - withdraw;

		else
			balance = balance - withdraw;

		if (cdTerm < 5)
			interest = balance * .05 + balance;

		else
			interest = balance * .10 + balance;

		monInterest = interest / 12;



		cin.clear();
		cin.ignore();
	}
};
//end of CD

//start main
int main()
{
	Banking **bptr;
	int amount = 0;
	char answer[3];

	cout << " How many bank accounts would you like to modify?" << endl;
	cin >> amount;
	cin.clear();
	cin.ignore();

	bptr = new Banking *[amount];
	for (int i = 0; i < amount; i++)
	{
		cout << "Which account would you like to access?" << endl;
		cout << "Enter [S] for Savings" << endl;
		cout << "Enter [C] for Checking" << endl;
		cout << "Enter [D] for Certificate of Deposit" << endl;
		gets_s(answer);
		if (strcmp(answer, "S") == 0)
		{
			bptr[i] = new Saving();
			bptr[i]->get_info();
		}
		else if (strcmp(answer, "C") == 0)
		{
			bptr[i] = new Checking();
			bptr[i]->get_info();
		}
		else if (strcmp(answer, "D") == 0)
		{
			bptr[i] = new CD();
			bptr[i]->get_info();
		}
		else
		{
			cout << "Error, try again." << endl;
			--i;
		}
	}
	for (int i = 0; i < amount; i++)
	{
		bptr[i]->display();
	}

	return 0;
}
//end main
