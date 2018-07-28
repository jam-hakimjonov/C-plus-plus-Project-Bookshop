#pragma once

#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <iostream>

#include "Bookshop.h"
#include <Windows.h>

using namespace std;

class Admin : public Bookshop 
	//Admin is publicly derived class of Bookshop class
{
public:
	//default constructor
	Admin();

	//parameterized constructor
	Admin(string log, string pass);

	//get_log function to ckeck login part
	string get_login();

	//get_pswd function to ckeck password part
	string get_pswd();

	//it makes Admin class as no-abstract class (see in Adnib.cpp)
	virtual void abstract();

private:
	//login variable
	string login;
	//password variable
	string pswd;
};

#endif