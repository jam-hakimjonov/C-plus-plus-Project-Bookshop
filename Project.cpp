//lib
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include <Windows.h>

//classes
#include "Animation.h"
#include "Controller.h"
#include "Bookshop.h"
#include "Cashbox.h"
#include "Admin.h"
#include "Books.h"

//U1710260 & U1710275

using namespace std;


	int main()
	{
		Controller menu;
		menu.main_menu();
		system("pause");
		return 0;
	}