#pragma once

#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
using namespace std;

class Animation
{
public:
	//phrase with borders
	static void frame_phrase(string, int, int count = 2);

	//draw borders
	static void draw_border(int, int, int count = 2);

	//exit 
	static int exit();

	//initializing 
	static void initializing();

	//colorized text
	static void colorize_text(string, int);

	//menu points
	static void points();
};

#endif

