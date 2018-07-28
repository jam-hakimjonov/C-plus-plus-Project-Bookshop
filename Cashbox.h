#pragma once

#ifndef CASHBOX_H
#define CASHBOX_H

using namespace std;

#include "Bookshop.h"
#include <Windows.h>

#include <fstream>
#include <string>
#include <iostream>

class Cashbox : public Bookshop
	//Cashbox is publicly derived class of Bookshop class
{
private:
	//variable from cash 
	float cash;
public:

	//this makes class as non-abstract class
	virtual void abstract(){};

	//default constructor
	Cashbox();

	//parameterized constructor
	Cashbox(float money);

	//func to get the value of cash in cashbox
	float get_cash();

	//operator overloading in order to show the amount of money in cashbox from object inself
	friend void operator<<(ostream &out, Cashbox cash)
	{
		ifstream money;
		money.open("cashbox.dat", ios::out | ios::binary);
		money.read((char*)&cash, sizeof(cash));
		cout << cash.get_cash();
		money.close();
	}

	//operator overloading in oder to add the price of book into cashbox.dat
	friend void operator>>(istream &in, float price_of_book)
	{
		Cashbox cash;
		fstream money;
		money.open("cashbox.dat", ios::in | ios::in | ios::binary);
		money.read((char*)&cash, sizeof(cash));
		float update = cash.get_cash() + price_of_book;
		Cashbox new_cash(update);
		money.write((char*)&new_cash, sizeof(new_cash));
		money.close();
		cout << new_cash.get_cash();
	}

	//reads and displays the value of cash from cashbox.dat
	static void check_cashbox();

	//takes the price of book as argument and increases the cash amount - inside the file cashbox.dat
	static void update_cashbox(float);
};

#endif