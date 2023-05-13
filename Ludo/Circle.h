/*
 * Circle.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include"Shape.h"

class Circle: public Shape
{
protected:
    float radius;
public:
    Circle(float X,float Y, float Radius, float* Color);
    void setRadius(float r);
    float getRadius();
    void ShowCircle();
	~Circle();
};
#endif /*CIRCLE_H_*/
