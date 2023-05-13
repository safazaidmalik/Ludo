/*
 * Line.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include"Line.h"

Line::Line(int X1,int Y1,int X2,int Y2,int Width,float* Color) : Shape(X1,Y1,Color)
{
    x = X1;
    y = Y1;
    x2 = X2;
    y2 = Y2;
    width = Width;
}

void Line::setX2(int X2)
{
    x2 = X2;
}
int Line::getX2()
{
    return x2;
}
void Line::setWidth(int Width)
{
    width = Width;
}
int Line::getWidth()
{
    return width;
}

void Line::ShowLine()
{
    DrawLine(x, y, x2, y2, width, color);
}
Line::~Line()
{

}

