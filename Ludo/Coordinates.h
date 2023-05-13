/*
 * Coordinates.h
 *
 *  Created on: Jun 12, 2021
 *      Author: szm
 */

#ifndef COORDINATES_H_
#define COORDINATES_H_
#include"Line.h"

#include"Rectangle.h"
#include"RoundRectangle.h"
#include"Triangle.h"
#include<iostream>
using namespace std;


struct Coordinates
{
	int xcoor;
	int ycoor;
	float* color;
	float width;
	float height;
	int typeOfBox;

	Coordinates();
	void setColor(float* Color);
	void setColor(string Color);

	void setType(int Type);
	void setType_setColor(int Type, float* Color);
	void copyCoordinates(Coordinates& coords);
	Coordinates(int X, int Y, float* Color, float Width, float Height, int TypeOfBox);
	void setCoordinates(int X, int Y, float* Color, float Width, float Height, int TypeOfBox);
	void setCoordinates(int X, int Y, string Color, float Width, float Height, int Type);


	void showCoordinates();
};



#endif /* COORDINATES_H_ */
