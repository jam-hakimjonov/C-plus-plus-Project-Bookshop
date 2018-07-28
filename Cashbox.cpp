#include "Cashbox.h"
#include <iostream>
#include <Windows.h>
#include "Bookshop.h"
#include <string>
using namespace std;

//default constructor
Cashbox::Cashbox()
{

};

//parameterized constructor
Cashbox::Cashbox(float money) 
{ 
	cash = money; 
};

//func to get the value of cash in cashbox
float Cashbox::get_cash()
{ 
	return cash; 
};

//reads and displays the value of cash from cashbox.dat
void Cashbox::check_cashbox()
{
	Cashbox cash;
	ifstream money;
	money.open("cashbox.dat", ios::out | ios::binary);
	money.read((char*)&cash, sizeof(cash));
	cout << cash.get_cash();
	money.close();
}

//takes the price of book as argument and increases the cash amount - inside the file cashbox.dat
void Cashbox::update_cashbox(float price_of_book)
{
	Cashbox cash;

	ifstream ifile;
	ofstream ofile;

	ifile.open("cashbox.dat", ios::out | ios::binary);
	ifile.read((char*)&cash, sizeof(cash));
	float update = cash.get_cash() + price_of_book;
	ifile.close();

	ofile.open("cashbox.dat", ios::in | ios::binary);
	Cashbox new_cash(update);
	ofile.write((char*)&new_cash, sizeof(new_cash));
	ofile.close();

	new_cash.get_cash();
}