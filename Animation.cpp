#include "Animation.h"

#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

//one point of char
void Animation::points()
{
	string s;
	s = char(176);
	colorize_text(s, 17); colorize_text(s, 17);
}

//exit 
int Animation::exit()
{
		system("cls");
		cout << endl << endl;
		cout << "\r\tIt was our project. Thanks for coming!" << endl;
		cout << endl;
		cout << "\t|               |                 |" << endl;
		cout << "\t|               |                 |" << endl;
		cout << "\t|               O                 |" << endl;
		cout << "\t|              /|\\                |" << endl;
		cout << "\t|               |                 |" << endl;
		cout << "\t|              / \\                |" << endl;
		cout << "\t|         +----------+            |" << endl;
		cout << "\t|         |          |            |" << endl;
		cout << endl;
		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				default:
					system("pause");
					return 0;
				}
			}
		}
}

//initializing
void Animation::initializing()
{
	int color = 17;
	cout << endl;
	draw_border(30, color);
	frame_phrase("                          ", color);
	frame_phrase("        LOGGED IN         ", color);
	frame_phrase("      SUCCESSFULLY.       ", color);
	frame_phrase("                          ", color);
	draw_border(30, color);
	Sleep(300);
	system("cls");
	cout << endl;
	draw_border(30, color);
	frame_phrase("                          ", color);
	frame_phrase("        LOGGED IN         ", color);
	frame_phrase("      SUCCESSFULLY..      ", color);
	frame_phrase("                          ", color);
	draw_border(30, color);
	Sleep(300);
	system("cls");
	cout << endl;
	draw_border(30, color);
	frame_phrase("                          ", color);
	frame_phrase("        LOGGED IN         ", color);
	frame_phrase("      SUCCESSFULLY...     ", color);
	frame_phrase("                          ", color);
	draw_border(30, color);
	Sleep(300);
	system("cls");
}

//phrase in borders
void Animation::frame_phrase(string phrase, int color, int count)
{
	string ch;
	ch = char(176);
	for (int i = 0; i < count; i++)
	{
		cout << "\t";
	}
	colorize_text(ch, color);
	colorize_text(ch, color);
	cout << phrase;
	colorize_text(ch, color);
	colorize_text(ch, color);
	cout << endl;
}

//draw borders
void Animation::draw_border(int amount, int color, int count)
{
	string g;
	g = char(176);

	for (int i = 0; i < count; i++)
	{
		cout << "\t";
	}
	for (int i = 0; i < amount; i++)
	{
		colorize_text(g, color);
	}
	cout << endl;
}

//colorize text
void Animation::colorize_text(string text, int color)
{
	int color_white = 15;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	SetConsoleTextAttribute(hConsole, color_white);
}

