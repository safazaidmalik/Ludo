/*
 * Board.h
 *
 *  Created on: Jun 11, 2021
 *      Author: szm
 */

#ifndef BOARD_H_
#define BOARD_H_
#include<string>
#include<iostream>
using namespace std;
#include"Line.h"

#include"Rectangle.h"
#include"RoundRectangle.h"
#include"Triangle.h"
#include"Coordinates.h"
#include"BoardSections.h"

struct Board
{
	int x;
	int y;
	float* color;
	BoardSections bs;

	Board(int X, int Y, float* Color);
	void setX(int X);
	int getX();
	void setY(int Y);
	int getY();
	void setColor(float* Color);
	float* getColor();
	void drawBoard();		//draws board as well as saves for each square in the grid its color, type, and coordinates.
	void draw_Tokens_Base(float* Color, int x, int y, int w, int num_lines, string Type);
	void draw_Blue_Path(int x, int y, int box_width);
	void draw_Yellow_Path(int x, int y, int box_width);
	void draw_Green_Path(int x, int y, int box_width);
	void draw_Red_Path(int x, int y, int box_width);


	virtual ~Board();
};

#endif /* BOARD_H_ */
