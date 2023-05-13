/*
 * Rectangle.h
 *
 *  Created on: Jun 2, 2020
 *      Author: szm
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include"Shape.h"
#include<iostream>
using namespace std;

class Rectangle : public Shape
{
protected:
	 int width;
	 int height;

public:
    Rectangle(int X, int Y, int Width, int Height, float *Color);
    void setWidth(int w);
    void setHeight(int h);
    int getWidth();
    int getHeight();
    void ShowRectangle();
	virtual ~Rectangle();
};

#endif /* RECTANGLE_H_ */


