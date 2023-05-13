/*
 * Circle.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include"Circle.h"

Circle::Circle(float X,float Y, float Radius, float Color[]) : Shape(X,Y,Color)
{
    radius = Radius;
}


void Circle::ShowCircle()
{
    DrawCircle(x, y, radius, color);
}
void Circle::setRadius(float Radius)
{
    radius = Radius;
}

float Circle::getRadius()
{
    return radius;
}
Circle::~Circle()
{

}

