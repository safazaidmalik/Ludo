/*
 * Triangle.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include "Triangle.h"

#include"Triangle.h"

Triangle::Triangle(int X, int Y, int X2, int Y2, int X3, int Y3, float* Color) : Shape(X, Y, Color)
{
    x2 =X2;
    y2 = Y2;
    x3 =X3;
    y3 = Y3;
}

void Triangle::setX2(int X2){x2 = X2;}

void Triangle::setX3(int X3){x3 = X3;}
void Triangle::setY2(int Y2){y2 = Y2;}
void Triangle::setY3(int Y3){y3 = Y3;}
int Triangle::getX2(){return x2;}
int Triangle::getY2(){return y2;}
int Triangle::getX3(){return x3;}
int Triangle::getY3(){return y3;}

void Triangle::ShowTriangle()
{
    DrawTriangle(x, y, x2, y2, x3, y3, color);
}
Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

