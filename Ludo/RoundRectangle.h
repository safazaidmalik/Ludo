/*
 * RoundRectangle.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */
#ifndef ROUNDRECTANGLE_H_
#define ROUNDRECTANGLE_H_
#include"util.h"
#include"Shape.h"
#include<iostream>
using namespace std;
class RoundRectangle : public Shape
{
protected:
    float width;
    float height;
    float radius;
public:
    RoundRectangle(float X, float Y, float w, float h, float r, float* Color);
    void setWidth(float w);
    void setHeight(float h);
    float getWidth();
    float getHeight();
    void ShowRoundRectangle();
	virtual ~RoundRectangle();
};

#endif /* ROUNDRECTANGLE_H_ */
