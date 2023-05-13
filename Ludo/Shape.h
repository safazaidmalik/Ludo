/*
 * Shape.h
 *
 *  Created on: Jun 1, 2020
 *      Author: szm
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include"util.h"
#include<iostream>
using namespace std;

class Shape
{
protected:
    int x;
    int y;
    float* color;
public:
    Shape(int X,int Y, float* Color);
    void setX(int X);
    void setY(int Y);
    int getX();
    int getY();
    void setColor(float* Color);
    float* getColor();
	virtual ~Shape();
};

   #endif /* SHAPE_H_ */
