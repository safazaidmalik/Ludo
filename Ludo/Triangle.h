/*
 * Triangle.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include"Shape.h"
using namespace std;
class Triangle : public Shape
{
protected:
    int x2;
    int y2;
    int x3;
    int y3;
public:
    Triangle(int X, int Y, int X2, int Y2, int X3, int Y3, float* Color);
    void setX2(int X2);
    void setX3(int X3);
    void setY2(int Y2);
    void setY3(int Y3);
    int getX2();
    int getY2();
    int getX3();
    int getY3();
    void ShowTriangle();
	virtual ~Triangle();

};

#endif /* TRIANGLE_H_ */
