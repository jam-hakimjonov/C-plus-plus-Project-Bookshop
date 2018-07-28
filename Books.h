#pragma once

#ifndef BOOKS_H
#define BOOKS_H

#include "Bookshop.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <string>
#include <Windows.h>

using namespace std;

class Book : public Bookshop
{
protected:
	//variables for all books types
	string title; 
	float price;
	int id;
	string release_date;
	string janres;
	string language;
	string edition;
	string writer;
	float rating;
public:
	//functions set/get for all books types
	string get_title();
	void set_title();
	void set_id(int);
	int get_id();
	int get_id_no_update();
	void set_price();
	float get_price();
	void set_janres();
	string get_janres();
	void set_release_date();
	void set_language();
	void set_edition();
	void set_writer();
	void set_rating();
	float get_rating();
	string get_release_date();
	string get_language();
	string get_edition();
	string get_writer();
};


class Paper_book : public Book
	//Paper_book is publicly derived class of Book class
{
protected:
	string publisher;
	int pages;
public:
	//this funct shows that this class is not abstract class
	virtual void abstract() {};
	void set_publisher();
	void set_pages();
	string get_publisher();
	virtual void add_book();
	int get_pages();
};

class Audio_cd : public Book
	//Audio_cd_book is publicly derived class of Book class
{
protected:
	string listening_length;
	string voice;
public:
	//this funct shows that this class is not abstract class
	virtual void abstract() {};
	virtual void add_book();
	void set_voice();
	void set_listening_length();
	string get_listening_length();
	string get_voice();
};

class Digital_book : public Book
	//Digital_book is publicly derived class of Book class
{ 
	public:
	virtual void add_book();
	virtual void abstract() {};

};

#endif