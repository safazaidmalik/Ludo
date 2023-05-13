/*
 * Shape.cpp
 *
 *  Created on: Jun 1, 2020
 *      Author: szm
 */

#include "Shape.h"

Shape::Shape(int X, int Y, float Color[])
{
    x = X;
    y = Y;
    color = Color;
}

void Shape::setX(int X)
{
    x= X;
}
void Shape::setY(int Y)
{
    y= Y;
}

int Shape::getX(){return x;}
int Shape::getY(){return y;}

void Shape::setColor(float Color[])
{
    color = Color;
}

float* Shape::getColor(){return color;}


Shape::~Shape()
{
}

