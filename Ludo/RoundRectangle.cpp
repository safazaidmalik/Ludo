/*
 * RoundRectangle.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include"RoundRectangle.h"

RoundRectangle::RoundRectangle(float X, float Y, float w, float h,  float r,float* Color): Shape(X, Y, Color)
{
    width = w;
    height = h;
    radius = r;
}

void RoundRectangle::setWidth(float w)
{
    width = w;
}

void RoundRectangle::setHeight(float h)
{
    height = h;
}

float RoundRectangle::getWidth()
{
    return width;
}

float RoundRectangle::getHeight()
{
    return height;
}
void RoundRectangle::ShowRoundRectangle()
{
    DrawRoundRect(x, y, width, height, color, radius);
}



RoundRectangle::~RoundRectangle()
{

}

