#include "Controller.h"
#include "Cashbox.h"
#include "Books.h"
#include "Animation.h"
#include "Admin.h"

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

//main menu of project
void Controller::main_menu()
{
	Controller c;
	int color_cyan = 17;
	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("     Scribbulus shop      ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("    1 -> Authorization    ", color_cyan);
	Animation::frame_phrase("    2 -> About shop       ", color_cyan);
	Animation::frame_phrase("    3 -> Why? Who?        ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("    Any other -> Exit     ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				system("cls");
				c.log_in();
				break;
			case '2':
				system("cls");
				about();
				break;
			case '3':
				system("cls");
				why_and_who();
				break;
			default:
				system("cls");
				Animation::exit();
				cin.ignore();
				exit(1);
			}
		}
	}
}

//log-in menu
void Controller::log_in()
{
	char c;
	string psw;
	string lgn;
	int color_cyan = 17;

	cout << endl;
	Animation::draw_border(32, color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::frame_phrase("   Authorization as admin   ", color_cyan);
	Animation::frame_phrase("                            ", color_cyan);
	Animation::draw_border(32, color_cyan);
	cout << endl;

	Animation::colorize_text("\t\t    Login: ", 14);
	while ((c = _getch()) != '\r')
	{
		if (c == 27)
		{
			system("cls");
			log_in();
		}
		if (c == 8)
		{
			if (lgn.length() == 0)
				continue;
			cout << '\b' << " " << '\b';
			lgn = lgn.substr(0, lgn.length() - 1);
			continue;
		}
		if (c >= 48 && c <= 57 || c >= 65 && c <= 92 || c >= 97 && c <= 122)
		{
			lgn += c;
			cout << c << '\b' << c;
		}
	}
	cout << endl;

	//Hiding the password with '*'
	Animation::colorize_text("\r\t\t    Password: ", 14);
	while ((c = _getch()) != '\r')
	{
		if (c == 27)
		{
			system("cls");
			log_in();
		}
		if (c == 8)
		{
			if (psw.length() == 0)
				continue;
			cout << '\b' << " " << '\b';
			psw = psw.substr(0, psw.length() - 1);
			continue;
		}
		if (c >= 48 && c <= 57 || c >= 65 && c <= 92 || c >= 97 && c <= 122)
		{
			psw += c;
			cout << "*" << '\b' << "*";
		}
	}

	//login
	Admin admin("INHA", "OOP");
	ofstream Administation;
	Administation.open("Admin.dat", ios::in | ios::binary);
	Administation.write((char*)&admin, sizeof(admin));

	while (lgn != admin.get_login() || psw != admin.get_pswd())
	{
		system("cls");
		cout << endl;
		Animation::draw_border(32, color_cyan);
		Animation::frame_phrase("                            ", color_cyan);
		Animation::frame_phrase("  Wrong login or password!  ", color_cyan);
		Animation::frame_phrase("                            ", color_cyan);
		Animation::draw_border(32, color_cyan);
		Sleep(2000);
		system("cls");
		log_in();
	}


	//Go to next menu
	system("cls");
	Animation::initializing();
	admin_panel();
}

//about project
void Controller::about()
{
	int color_cyan = 17;
	cout << "\t\t"; Animation::draw_border(50, 17, 0);
	cout << "\t\t"; Animation::colorize_text("                 Scribbulus shop                  \n", 9);
	cout << "\t\t"; Animation::draw_border(50, 17, 0);
	cout << "\t\t"; Animation::colorize_text("                                                  \n", 3);
	cout << "\t\t"; Animation::colorize_text("   Scribbulus shop is located in Diagon Alley,    \n", 7);
	cout << "\t\t"; Animation::colorize_text("              it's imaginary place                \n", 7);
	cout << "\t\t"; Animation::colorize_text("         from Harry Potter novel series.          \n", 7);
	cout << "\t\t"; Animation::colorize_text("                                                  \n", 3);
	cout << "\t\t"; Animation::colorize_text("                   -> Owners <-                   \n", 5);
	cout << "\t\t"; Animation::colorize_text("                    Kirti Seth                    \n", 7);
	cout << "\t\t"; Animation::colorize_text("              Jamshidjon Khakimjonov              \n", 7);
	cout << "\t\t"; Animation::colorize_text("               Vladislav Podkovyrkin              \n", 7);
	cout << "\t\t"; Animation::colorize_text("                 Albus Dumbledore                 \n", 7);
	cout << "\t\t"; Animation::colorize_text("                                                  \n", 7);
	cout << "\t\t"; Animation::draw_border(50, 17, 0);
	cout << "\t\t"; Animation::colorize_text(" -> Buy online on website: http://scribbulus.com  \n", 5);
	cout << "\t\t"; Animation::colorize_text("             Tel: +998 71 191 90 12               \n", 5);
	cout << "\t\t"; Animation::colorize_text("                                                  \n", 3);
	cout << "\t\t"; Animation::colorize_text("         -> Any other key to go back <-           \n", 8);
	cout << "\t\t"; Animation::draw_border(50, 17, 0);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
				default:
				system("cls");
				main_menu();
				break;
			}
		}
	}
}

//admin panel
void Controller::admin_panel()
{
	Controller c;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string space;
	string space1;
	string mes, ord;
	string conv;
	string conv1;
	int color_cyan = 17;
	int color_yellow = 14;
	int color_white = 15;
	string g;
	g = char(176);

	system("cls");
	cout << endl;
	Animation::draw_border(39, color_cyan, 1);
	Animation::frame_phrase("                                   ", color_cyan, 1);
	Animation::frame_phrase("            ADMIN PANEL            ", color_cyan, 1);
	Animation::frame_phrase("                                   ", color_cyan, 1);
	Animation::draw_border(39, color_cyan, 1);
	Animation::frame_phrase("          BOOKSHOP CONTROL         ", color_cyan, 1);
	Animation::draw_border(39, color_cyan, 1);
	Animation::frame_phrase("                                   ", color_cyan, 1);
	cout << "        ";
	Animation::points();
	Animation::colorize_text("	    1.", color_yellow);
	Animation::colorize_text(" Add new book  ", color_white);
	cout << "        ";
	Animation::points();
	cout << endl;
	cout << "        ";
	Animation::points();
	Animation::colorize_text("	    2.", color_yellow);
	Animation::colorize_text(" Sell book     ", color_white);
	cout << "        ";
	Animation::points();
	cout << endl;
	cout << "        ";
	Animation::points();
	Animation::colorize_text("	    3.", color_yellow);
	Animation::colorize_text(" Search book   ", color_white);
	cout << "        ";
	Animation::points();
	cout << endl;
	cout << "        ";
	Animation::points();
	Animation::colorize_text("	    4.", color_yellow);
	Animation::colorize_text(" Ckeck cashbox ", color_white);
	cout << "        ";
	Animation::points();
	cout << "        ";
	cout << endl;
	cout << "        ";
	Animation::points();
	cout << "                                   ";
	Animation::points();
	cout << endl;
	cout << "        ";
	Animation::points();
	Animation::colorize_text("	    0.", color_yellow);
	Animation::colorize_text(" Log out       ", color_white);
	cout << "        ";
	Animation::points();
	cout << endl;
	cout << "        ";
	Animation::points();
	cout << "                                   ";
	Animation::points();
	cout << endl;
	Animation::draw_border(39, color_cyan, 1);

	Cashbox cash;

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				c.add_book();
				break;
			case '2':
				c.sell_book();
				break;
			case '3':
				find_book();
				break;
			case '4':
				system("cls");
				Animation::draw_border(40, color_cyan);                                            
				Animation::colorize_text("                    Cashbox in bookshop was checked            \n", 14);
				Animation::draw_border(40, color_cyan);
				cout << endl;
				cout << "\t\t\tSum of money: " << cash;
				cout << endl;
				cout << endl;
				Animation::draw_border(40, color_cyan);
				Animation::frame_phrase("                                    ", color_cyan);
				Animation::frame_phrase("         Any key to go back         ", color_cyan);
				Animation::frame_phrase("           to admin panel           ", color_cyan);
				Animation::frame_phrase("                                    ", color_cyan);
				Animation::draw_border(40, color_cyan);
				while (true)
				{
					if (_kbhit())
					{
						char ch = _getch();
						switch (ch)
						{
						default:
							system("cls");
							admin_panel();
							break;
						}
					}
				}

			case '0':
				log_out_admin();
				break;
			}
		}
	}
}

//Log out func for admin
void Controller::log_out_admin()
{
	//Asks user the permission to exit from account
	system("cls");
	int color_cyan = 17;

	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("       Are you sure?      ", color_cyan);
	Animation::frame_phrase("    Y -> Yes | N <- No    ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case 'Y':
			case 'y':
				system("cls");
				main_menu();
				break;
			case 'N':
			case 'n':
				system("cls");
				admin_panel();
				break;
			}
		}
	}
}

//add book menu (book type)
void Controller::add_book()
{
	system("cls");
	Controller c;
	int color_cyan = 17;
	cout << endl;
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("       TYPE OF BOOK       ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("    1 -> Paper book       ", color_cyan);
	Animation::frame_phrase("    2 -> Audio book       ", color_cyan);
	Animation::frame_phrase("    3 -> Digital book     ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::frame_phrase("   Any other -> GO BACK   ", color_cyan);
	Animation::frame_phrase("                          ", color_cyan);
	Animation::draw_border(30, color_cyan);
	Paper_book pb;
	Audio_cd ab;
	Digital_book db;
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			case '1':
				pb.add_book();
				break;
			case '2':
				ab.add_book();
				break;
			case '3':
				db.add_book();
				break;
			default:
				admin_panel();
				break;
			}
		}
	}
}

//sell book from database
void Controller::sell_book()
{
	system("cls");
	int color_cyan = 17;
	int color_yellow = 14;

	Animation::draw_border(62, color_cyan);
	Animation::colorize_text("\t\t             System needs ID of book to sell       \n", 14);
	Animation::draw_border(62, color_cyan);
	cout << endl;
	int id = -1 ;
	while (id < 0 || !(cin.good()))
	{
		Animation::colorize_text("\t\t    Sell by ID: ", 14);
		cin >> id;
		cin.clear();
		cin.ignore(100, '\n');
	}
	system("cls");

	Paper_book pb;
	Audio_cd ab;
	Digital_book db;
	string line;

	float price;

	string n1 = "DataBase/Paper Books/book - " + to_string(id) + ".info";
	string n2 = "DataBase/Audio CD/book - " + to_string(id) + ".info";
	string n3 = "DataBase/Digital Books/book - " + to_string(id) + ".info";

	ifstream f1;
	f1.open(n1, ios::_Nocreate);

	if (f1.is_open())
	{
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Info about book with this ID         \n", 3);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Type: ", color_yellow);
		Animation::colorize_text(" Paper Book ", 3);
		Animation::colorize_text("\t\t    ID: ", 3);
		getline(f1, line);
		cout << line;
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Language: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Rating (1 -> 10): ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Price in sums: ", color_yellow);
		getline(f1, line);
		price = strtof((line).c_str(), 0);
		cout << line << endl;
		Animation::colorize_text("\t\t    Publisher: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Volume in pages: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		cout << endl;
		cout << endl;


	}

	ifstream f2;
	f2.open(n2, ios::_Nocreate);

	if (f2.is_open())
	{
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Info about book with this ID         \n", 3);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Type: ", color_yellow);
		Animation::colorize_text(" Audio CD Book", 3);
		Animation::colorize_text("\t\t    ID: ", 03);
		getline(f2, line);
		cout << line;
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Language: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Rating (1 -> 10): ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Price in sums: ", color_yellow);
		getline(f2, line);
		price = strtof((line).c_str(), 0);
		cout << line << endl;
		Animation::colorize_text("\t\t    Voice: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Listening lenth: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		cout << endl;
		cout << endl;


	}

	ifstream f3;
	f3.open(n3, ios::_Nocreate);
	if (f3.is_open())
	{
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Info about book with this ID         \n", 3);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Type: ", color_yellow);
		Animation::colorize_text(" Digital Book ", 3);
		Animation::colorize_text("\t\t    ID: ", 03);
		getline(f3, line);
		cout << line;
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Language: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Rating (1 -> 10): ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Price in sums: ", color_yellow);
		getline(f3, line);
		price = strtof((line).c_str(), 0);
		cout << line << endl;
		cout << endl;
		cout << endl;

	}

	if (f3.is_open() | f1.is_open() | f2.is_open())
	{
		Animation::draw_border(61, color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase("        This action will delete book from database       ", color_cyan);
		Animation::frame_phrase("                 Are you sure about that?                ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase("                   Y <- Yes | NO -> N                    ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::draw_border(61, color_cyan);

		Controller c;

		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				case 'Y':
				case 'y':
					system("cls");
					if (f1.is_open())
					{
						f1.close();
						remove(n1.c_str());
					}
					if (f2.is_open())
					{
						f2.close();
						remove(n2.c_str());
					}
					if (f3.is_open())
					{
						f3.close();
						remove(n3.c_str());
					}

					Cashbox::update_cashbox(price);

					system("cls");
					Animation::draw_border(61, color_cyan);
					Animation::frame_phrase("                                                         ", color_cyan);
					Animation::frame_phrase("              Book was deleted from database             ", color_cyan);
					Animation::frame_phrase("                                                         ", color_cyan);
					Animation::draw_border(61, color_cyan);
					Sleep(1500);
					c.admin_panel();
					break;
				case 'N':
				case 'n':
					system("cls");
					c.admin_panel();
					break;
				default:
					system("cls");
					c.admin_panel();
				}//switch close
			}//fi close
		}//while close
	}//fi close
	else 
	{
		system("cls");
		Animation::draw_border(61, color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase("         WE could not found a book with this ID!         ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::draw_border(61, color_cyan);
		Sleep(2000);
		Controller c;
		c.admin_panel();
	}
}//function close

//find book from database
void Controller::find_book()
{
	system("cls");
	int color_cyan = 17;
	int color_yellow = 14;

	Animation::draw_border(62, color_cyan);
	Animation::colorize_text("\t\t             System needs ID to find a book       \n", 14);
	Animation::draw_border(62, color_cyan);
	cout << endl;
	int id = -1;
	while (id < 0 || !(cin.good()))
	{
		Animation::colorize_text("\t\t    Find by ID: ", 14);
		cin >> id;
		cin.clear();
		cin.ignore(100, '\n');
	}
	system("cls");

	Paper_book pb;
	Audio_cd ab;
	Digital_book db;
	string line;
	ifstream f1;

	string n1 = "DataBase/Paper Books/book - " + to_string(id) + ".info";
	string n2 = "DataBase/Audio CD/book - " + to_string(id) + ".info";
	string n3 = "DataBase/Digital Books/book - " + to_string(id) + ".info";

	f1.open(n1, ios::_Nocreate);

	if (f1.is_open())
	{
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Info about book with this ID         \n", 3);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Type: ", color_yellow);
		Animation::colorize_text(" Paper Book ", 3);
		Animation::colorize_text("\t\t    ID: ", 03);
		getline(f1, line);
		cout << line;
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Language: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Rating (1 -> 10): ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Price in sums: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Publisher: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Volume in pages: ", color_yellow);
		getline(f1, line);
		cout << line << endl;
		cout << endl;
		cout << endl;

	}

	ifstream f2;
	f2.open(n2, ios::_Nocreate);

	if (f2.is_open())
	{
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Info about book with this ID         \n", 3);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Type: ", color_yellow);
		Animation::colorize_text(" Audio CD Book ", 3);
		Animation::colorize_text("\t\t    ID: ", 03);
		getline(f2, line);
		cout << line;
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Language: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Rating (1 -> 10): ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Price in sums: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Voice: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Listening lenth: ", color_yellow);
		getline(f2, line);
		cout << line << endl;
		cout << endl;
		cout << endl;

	}

	ifstream f3;
	f3.open(n3, ios::_Nocreate);
	if (f3.is_open())
	{
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Info about book with this ID         \n", 3);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Type: ", color_yellow);
		Animation::colorize_text(" Digital Book ", 3);
		Animation::colorize_text("\t\t    ID: ", 03);
		getline(f3, line);
		cout << line;
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Language: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Rating (1 -> 10): ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		Animation::colorize_text("\t\t    Price in sums: ", color_yellow);
		getline(f3, line);
		cout << line << endl;
		cout << endl;
		cout << endl;
	}//if close
	if (f3.is_open() | f1.is_open() | f2.is_open())
	{
	Animation::draw_border(61, color_cyan);
	Animation::frame_phrase("                                                         ", color_cyan);
	Animation::frame_phrase("                    Any key to go back                   ", color_cyan);
	Animation::frame_phrase("                      to admin panel                     ", color_cyan);
	Animation::frame_phrase("                                                         ", color_cyan);
	Animation::draw_border(61, color_cyan);
	f1.close();
	f2.close();
	f3.close();
	Controller c;
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			default:
				system("cls");
				c.admin_panel();
			}
		}
	}
	}//if close
	else
	{
		system("cls");
		Animation::draw_border(61, color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase("         WE could not found a book with this ID!         ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::draw_border(61, color_cyan);
		Sleep(2000);
		Controller c;
		c.admin_panel();
	}//else close


	
}

//Info about us and our proffesor/course
void Controller::why_and_who()
{
	int color_cyan = 17;

	Animation::draw_border(56, color_cyan);
	Animation::frame_phrase("                                                    ", color_cyan);
	Animation::frame_phrase("                    OOP-2 Project                   ", color_cyan);
	Animation::frame_phrase("                                                    ", color_cyan);
	Animation::draw_border(56, color_cyan);
	Animation::frame_phrase("                                                    ", color_cyan);
	Animation::frame_phrase("     Course Title: Object Oriented Programming 2    ", color_cyan);
	Animation::frame_phrase("                Professor: Kirti Seth               ", color_cyan);
	Animation::frame_phrase("                      Group: 008                    ", color_cyan);
	Animation::frame_phrase("                                                    ", color_cyan);
	Animation::frame_phrase("          Students who made this project:           ", color_cyan);
	Animation::frame_phrase("                                                    ", color_cyan);
	Animation::frame_phrase("          Jamshidjon Khakimjonov - U1710260         ", color_cyan);
	Animation::frame_phrase("           Vladislav Podkovyrkin - U1710275         ", color_cyan);
	Animation::frame_phrase("                                                    ", color_cyan);
	Animation::frame_phrase("                                                    ", color_cyan);
	Animation::draw_border(56, color_cyan);
	Controller c;

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			switch (ch)
			{
			default:
				system("cls");
				c.main_menu();
			}
		}
	}
}