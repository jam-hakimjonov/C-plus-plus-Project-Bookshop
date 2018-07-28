#include "Books.h"
#include "fstream"
#include "Animation.h"
#include "Controller.h"

#include <string>
#include <fstream>

using namespace std;

	//books
	string Book::get_title() 
	{ 
		return title; 
	}

	void Book::set_id(int i)
	{
		id = i;
	}

	float Book::get_price() 
	{ 
		return price; 
	}

	//gives id whit incrementing 
	int Book::get_id() 
	{
		string file = "Update ID.txt";

		ifstream last_id;
		last_id.open(file);
		last_id >> id;
		last_id.close();

		ofstream update_id;
		update_id.open(file);
		update_id << (id + 1);
		update_id.close();

		return id;
	}

	//gives id whithout incrementing 
	int Book::get_id_no_update()
	{
		return id;
	}

	float Book::get_rating() 
	{ 
		return rating; 
	}

	string Book::get_release_date() 
	{
		return release_date;
	}

	string Book::get_language()
	{
		return language; 
	}

	string Book::get_edition() 
	{ 
		return edition; 
	}

	string Book::get_janres() 
	{ 
		return janres; 
	}

	string Book::get_writer() 
	{ 
		return writer;
	}

	//paper_book get func
	string Paper_book::get_publisher()
	{ 
		return  publisher;
	}

	int Paper_book::get_pages()
	{
		return pages; 
	}

	//audio_books get func
	string Audio_cd::get_listening_length() 
	{ 
		return  listening_length; 
	}

	string Audio_cd::get_voice()
	{ 
		return  voice;
	}


	void Paper_book::add_book()
	{
		system("cls");
		Paper_book pb;
		char c;
		int color_yellow = 14;
		int color_cyan = 17;
		cout << endl;

		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Fill the form to add book         \n", 07);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\n\t\t    Title: ", color_yellow);
		pb.set_title();
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		pb.set_release_date();
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		pb.set_writer();
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		pb.set_janres();
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		pb.set_edition();
		pb.set_language();
		pb.set_rating();
		pb.set_price();
		pb.set_publisher();
		pb.set_pages();
		Animation::colorize_text("\t\t    ID of this book in the system: ", 3);
		cout << pb.get_id();
		cout << endl;
		cout << endl;
		ofstream pb_write;
		pb_write.open("DataBase/Paper Books/book - " + to_string(pb.get_id_no_update()) + ".info");
		pb_write << pb.get_id_no_update() << endl;
		pb_write << pb.get_title() << endl;
		pb_write << pb.get_release_date() << endl;
		pb_write << pb.get_writer() << endl;
		pb_write << pb.get_janres() << endl;
		pb_write << pb.get_edition() << endl;
		pb_write << pb.get_language() << endl;
		pb_write << pb.get_rating() << endl;
		pb_write << pb.get_price() << endl;
		pb_write << pb.get_publisher() << endl;
		pb_write << pb.get_pages() << endl;
		pb_write.close();

		Animation::draw_border(61, color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase(" New paper book has been successfully added to database  ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase("             -> Press any key to go back <-              ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::draw_border(61, color_cyan); 
		cout << endl;
		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				default:
						system("cls");
						Controller c;
						c.admin_panel();
				}
			}
		}
	};

	void Audio_cd::add_book()
	{
		system("cls");
		Audio_cd pb;
		fstream books;
		books.open("Audio.dat", ios::binary | ios::in | ios::app);
		char c;
		int color_yellow = 14;
		int color_cyan = 17;
		cout << endl;
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Fill the form to add book         \n", 07);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		pb.set_title();
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		pb.set_release_date();
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		pb.set_writer();
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		pb.set_janres();
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		pb.set_edition();
		pb.set_language();
		pb.set_rating();
		pb.set_price();
		Animation::colorize_text("\t\t    Voice: ", color_yellow);
		pb.set_voice();
		Animation::colorize_text("\t\t    Listening length (hours): ", color_yellow);
		pb.set_listening_length();
		Animation::colorize_text("\t\t    ID of this book in the system: ", 3);
		cout << pb.get_id();
		cout << endl;
		cout << endl;
		Animation::draw_border(61, color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase(" New audio book has been successfully added to database  ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase("             -> Press any key to go back <-              ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::draw_border(61, color_cyan);
		cout << endl;

		ofstream pb_write;
		pb_write.open("DataBase/Audio CD/book - " + to_string(pb.get_id_no_update()) + ".info");
		pb_write << pb.get_id_no_update() << endl;
		pb_write << pb.get_title() << endl;
		pb_write << pb.get_release_date() << endl;
		pb_write << pb.get_writer() << endl;
		pb_write << pb.get_janres() << endl;
		pb_write << pb.get_edition() << endl;
		pb_write << pb.get_language() << endl;
		pb_write << pb.get_rating() << endl;
		pb_write << pb.get_price() << endl;
		pb_write << pb.get_voice() << endl;
		pb_write << pb.get_listening_length() << endl;
		pb_write.close();

		books.write((char*)&pb, sizeof(pb));
		books.close();
		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				default:
					system("cls");
					Controller c;
					c.admin_panel();
				}
			}
		}
	};

	void Digital_book::add_book()
	{
		system("cls");
		Digital_book pb;
		fstream books;
		books.open("Digital.dat", ios::binary | ios::in | ios::app);
		char c;
		int color_yellow = 14;
		int color_cyan = 17;
		cout << endl;
		Animation::draw_border(61, color_cyan);
		Animation::colorize_text("\t\t                  Fill the form to add book         \n", 07);
		Animation::draw_border(61, color_cyan);
		cout << endl;
		Animation::colorize_text("\t\t    Title: ", color_yellow);
		pb.set_title();
		Animation::colorize_text("\t\t    Release date: ", color_yellow);
		pb.set_release_date();
		Animation::colorize_text("\t\t    Author: ", color_yellow);
		pb.set_writer();
		Animation::colorize_text("\t\t    Janres: ", color_yellow);
		pb.set_janres();
		Animation::colorize_text("\t\t    Edition: ", color_yellow);
		pb.set_edition();
		pb.set_language();
		pb.set_rating();
		pb.set_price();
		Animation::colorize_text("\t\t    ID of this book in the system: ", 3);
		cout << pb.get_id();
		cout << endl;
		cout << endl;
		Animation::draw_border(61, color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase(" New digit-book has been successfully added to database  ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::frame_phrase("             -> Press any key to go back <-              ", color_cyan);
		Animation::frame_phrase("                                                         ", color_cyan);
		Animation::draw_border(61, color_cyan);
		cout << endl;

		ofstream pb_write;
		pb_write.open("DataBase/Digital Books/book - " + to_string(pb.get_id_no_update()) + ".info");
		pb_write << pb.get_id_no_update() << endl;
		pb_write << pb.get_title() << endl;
		pb_write << pb.get_release_date() << endl;
		pb_write << pb.get_writer() << endl;
		pb_write << pb.get_janres() << endl;
		pb_write << pb.get_edition() << endl;
		pb_write << pb.get_language() << endl;
		pb_write << pb.get_rating() << endl;
		pb_write << pb.get_price() << endl;
		pb_write.close();

		books.write((char*)&pb, sizeof(pb));
		books.close();
		while (true)
		{
			if (_kbhit())
			{
				char ch = _getch();
				switch (ch)
				{
				default:
					system("cls");
					Controller c;
					c.admin_panel();
				}
			}
		}
	};

	void Book::set_title() 
	{
		string t;
		getline(cin, t);
		title = t;
	}

	void Book::set_price()
	{
		float t = -1;
		while (t < 0 || !(cin.good()) || t > 10000000)
		{
				cin.clear();
				cin.ignore(100, '\n');
				Animation::colorize_text("\t\t    Price in sums: ", 14);
				cin >> t;
				price = t;
		}
	}

	void Book::set_release_date()
	{
		string t;
		getline(cin, t);
		release_date = t;
	}

	void Book::set_language()
	{
		string t;
		Animation::colorize_text("\t\t    Language: ", 14);
		cin >> t;
		language = t;
	}

	void Book::set_edition()
	{
		string t;
		getline(cin, t);
		edition = t;
	}

	void Book::set_writer()
	{
		string t;
		getline(cin, t);
		writer = t;
	}

	void Book::set_rating()
	{
		float t = - 1;
		while (t < 1 || t > 10 || !(cin.good()))
		{
			cin.clear();
			cin.ignore(100, '\n');
			Animation::colorize_text("\t\t    Rating (1 -> 10): ", 14);
			cin >> t;
			rating = t;
		}

	}

	void Paper_book::set_publisher()
	{
		Animation::colorize_text("\t\t    Publisher: ", 14);
		cin >> publisher;
	}

	void Paper_book::set_pages()
	{
		int t = -1;
		while (t < 0 || !(cin.good()))
		{
			cin.clear();
			cin.ignore(100, '\n');
			Animation::colorize_text("\t\t    Volume in pages: ", 14);
			cin >> t;
			pages = t;
		}
	}

	void Audio_cd::set_voice()
	{
		getline(cin, voice);
	}

	void Audio_cd::set_listening_length()
	{
		getline(cin, listening_length);
		getline(cin, listening_length);
	}

	void Book::set_janres() 
	{
		string t;
		getline(cin, t);
		janres = t;
	}
	
