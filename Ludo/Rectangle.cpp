/*
 * Rectangle.cpp
 *
 *  Created on: Jun 2, 2020
 *      Author: szm
 */
#include"Rectangle.h"

Rectangle::Rectangle(int X, int Y, int Width, int Height, float *Color) : Shape(X,Y,Color)
{
    width = Width;
    height = Height;
}

void Rectangle::setWidth(int w)
{
    width = w;
}

void Rectangle::setHeight(int h)
{
    height = h;
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getHeight()
{
    return height;
}
void Rectangle::ShowRectangle()
{
    DrawRectangle(x, y, width, height, color);
}

Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

