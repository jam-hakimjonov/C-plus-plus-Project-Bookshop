#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
using namespace std;

class Controller
{
protected:

public:
	//main menu of project
	static void main_menu();

	//add book menu (book type)
	static void add_book();

	//Log out func for admin
	static void log_out_admin();

	//admin panel
	static void admin_panel();

	//log-in menu
	static void log_in();

	//about project
	static void about();

	//sell book from database
	static void sell_book();

	//find book from database
	static void find_book();

	//Info about us and our proffesor/course
	static void why_and_who();
};


#endif
