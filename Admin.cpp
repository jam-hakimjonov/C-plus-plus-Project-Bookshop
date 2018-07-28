#include "Admin.h"

//default constructor
Admin::Admin() 
{

};

//parameterized constructor
Admin::Admin(string log, string pass) 
{ 
	login = log; 
	pswd = pass; 
}

//get_log function to ckeck login part
string Admin::get_login()
{
	return login;
}

//get_pswd function to ckeck password part
string Admin::get_pswd() 
{
	return pswd; 
}

//it makes Admin class as no-abstract class
void Admin::abstract()
{

};
