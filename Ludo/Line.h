/*
 * Line.h
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#ifndef LINE_H_
#define LINE_H_
#include"Shape.h"

class Line: public Shape
{
protected:
    int x2;
    int y2;
    int width;
public:
    Line(int X1, int Y1, int X2, int Y2, int Width, float* Color);
    void setX2(int X2);
    int getX2();
    void setWidth(int Width);
    int getWidth();
    void ShowLine();
	~Line();

};

#endif /* LINE_H_ */
