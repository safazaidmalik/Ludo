/*
 * Board.cpp
 *
 *  Created on: Jun 11, 2021
 *      Author: szm
 */

#include "Board.h"
#include <cstdlib>
#include<ctime>


Board::Board(int X, int Y, float* Color)
{
	x= X;
	y= Y;
	color = Color;
}


void Board::setX(int X)
{
	x= X;
}
int Board::getX()
{
	return x;
}
void Board::setY(int Y)
{
	y = Y;
}
int Board::getY()
{
	return y;
}
void Board::setColor(float* Color)
{
	color = Color;
}
float* Board::getColor()
{
	return color;
}

void Board::draw_Blue_Path(int x, int y, int box_width)
{
	int X = x-box_width*6, Y = y;	//to store starting X and Y for this path; the top left white box of blue path
	for(int row=0; row<3; row++)
	{
		for(int col = 0; col<6; col++)
		{
			bs.bluepath[col+(row)*6].setCoordinates(X+col*box_width, Y-row*box_width, colors[WHITE], box_width, box_width, 1);	//initialize all squares in blue path as normal white boxes, and store their coordinates
			if(col>0 && col<6 && row == 1)
				bs.bluepath[col+(row)*6].setType_setColor(31, colors[LIGHT_BLUE]);	//update type and color
			else if((col == 1 && row == 0))
				bs.bluepath[col+(row)*6].setType_setColor(71, colors[LIGHT_BLUE]);	//update type and color
			else if(col==2 && row == 2)
				bs.bluepath[col+(row)*6].setType_setColor(4, colors[DIM_GRAY]);	//update type and color
		}
	}

	/////////////////////////////               \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	//for seeing (almost) exact center of blue triangle
//	cout<<"Blue Triangle's center = ("<<bs.bluepath[11].xcoor+1.25*box_width<<", "<<bs.bluepath[11].ycoor+0.5*box_width<<")"<<endl;
//	DrawRectangle(bs.bluepath[11].xcoor+1.5*box_width, bs.bluepath[11].ycoor+0.5*box_width, 5, 5, colors[RED]);

	/////////////////////////////               \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	Rectangle** recs;
	recs = (Rectangle**)malloc (5*sizeof(Rectangle*));		//to fill the 5 squares of the blue path.
	int i=0;
	for( i=0; i<5; i++)
	{
		//add and subtract +1 from x, y, width and height tto be able to see the outlines of each box in the grid.
		recs[i] = new Rectangle(x-(i+1)*box_width+1, y-box_width+1, box_width-1, box_width-1, colors[LIGHT_BLUE]);
	}
	for(int i=0; i<5; i++)
	{
		recs[i]->ShowRectangle();
		if(i==3)
		{
			Rectangle* rec6 = new Rectangle(x-(i+1)*box_width+1, y-2*box_width+1, box_width-1, box_width-1, colors[	DIM_GRAY]);
			rec6->ShowRectangle();
		}
		else if(i==4)
		{
			Rectangle* rec7 = new Rectangle(x-(i+1)*box_width+1, y+1, box_width-1, box_width-1, colors[LIGHT_BLUE]);
			rec7->ShowRectangle();
		}
	}
}

void Board::draw_Yellow_Path(int x, int y, int box_width)
{
	int X = x+box_width, Y = y+box_width*5;	//to store starting X and Y for this path; the top left white box of blue path
	//cout<<"X = "<<X<<", Y = "<<Y<<endl;

	for(int row=0; row<3; row++)
	{
		for(int col = 0; col<6; col++)
		{
			bs.yellowpath[col+(row)*6].setCoordinates(X-row*box_width, Y-col*box_width, colors[WHITE], box_width, box_width, 1);	//initialize all squares in blue path as normal white boxes, and store their coordinates
			if(col>0 && col<6 && row == 1)
				bs.yellowpath[col+(row)*6].setType_setColor(32, colors[ORANGE]);	//update type and color
			else if((col == 1 && row == 0))
				bs.yellowpath[col+(row)*6].setType_setColor(72, colors[ORANGE]);	//update type and color
			else if(col==2 && row == 2)
				bs.yellowpath[col+(row)*6].setType_setColor(4, colors[DIM_GRAY]);	//update type and color
//			bs.yellowpath[col+row*6].showCoordinates();
		}
	}
	Rectangle** recs;
	recs = (Rectangle**)malloc (5*sizeof(Rectangle*));		//to fill the 5 squares of the blue path.
	int i=0;
	for( i=0; i<5; i++)
	{
		recs[i] = new Rectangle(x+1, y+i*box_width+1, box_width-1, box_width-1, colors[ORANGE]);
	}
	for(int i=0; i<5; i++)
	{
		recs[i]->ShowRectangle();
		if(i==3)
		{
			Rectangle* rec6 = new Rectangle(x-box_width+1, y+i*box_width+1, box_width-1, box_width-1, colors[	DIM_GRAY]);
			rec6->ShowRectangle();
		}
		else if(i==4)
		{
			Rectangle* rec7 = new Rectangle(x+box_width+1, y+i*box_width+1, box_width-1, box_width-1, colors[ORANGE]);
			rec7->ShowRectangle();
		}
	}
}

void Board::draw_Green_Path(int x, int y, int box_width)
{
	int X = x+5*box_width, Y = y-2*box_width;	//to store starting X and Y for this path; the top left white box of blue path
	//cout<<"X = "<<X<<", Y = "<<Y<<endl;

	for(int row=0; row<3; row++)
	{
		for(int col = 0; col<6; col++)
		{
			bs.greenpath[col+(row)*6].setCoordinates(X-col*box_width, Y+row*box_width, colors[WHITE], box_width, box_width, 1);	//initialize all squares in blue path as normal white boxes, and store their coordinates
			if(col>0 && col<6 && row == 1)
				bs.greenpath[col+(row)*6].setType_setColor(33, colors[GREEN]);	//update type and color
			else if((col == 1 && row == 0))
				bs.greenpath[col+(row)*6].setType_setColor(73, colors[GREEN]);	//update type and color
			else if(col==2 && row == 2)
				bs.greenpath[col+(row)*6].setType_setColor(4, colors[DIM_GRAY]);	//update type and color
		}
	}
	Rectangle** recs;
	recs = (Rectangle**)malloc (5*sizeof(Rectangle*));		//to fill the 5 squares of the blue path.
	int i=0;
	for( i=0; i<5; i++)
	{
		//add and subtract +1 from x, y, width and height tto be able to see the outlines of each box in the grid.
		recs[i] = new Rectangle(x+i*box_width+1, y-box_width+1, box_width-1, box_width-1, colors[GREEN]);
	}
	for(int i=0; i<5; i++)
	{
		recs[i]->ShowRectangle();
		if(i==3)
		{
			Rectangle* rec6 = new Rectangle(x+i*box_width+1, y+1, box_width-1, box_width-1, colors[DIM_GRAY]);
			rec6->ShowRectangle();
		}
		else if(i==4)
		{
			Rectangle* rec7 = new Rectangle(x+i*box_width+1, y-2*box_width+1, box_width-1, box_width-1, colors[GREEN]);
			rec7->ShowRectangle();
		}
	}
}
void Board::draw_Red_Path(int x, int y, int box_width)
{
	int X = x-1*box_width, Y = y-6*box_width;	//to store starting X and Y for this path; the top left white box of blue path
	//cout<<"X = "<<X<<", Y = "<<Y<<endl;

	for(int row=0; row<3; row++)
	{
		for(int col = 0; col<6; col++)
		{
		//	bs.redpath[col+(row)*6].setCoordinates(X+col*box_width, Y-row*box_width, "WHITE", box_width, box_width, 1);	//initialize all squares in blue path as normal white boxes, and store their coordinates
			bs.redpath[col+(row)*6].setCoordinates(X+row*box_width, Y+col*box_width, colors[WHITE], box_width, box_width, 1);	//initialize all squares in blue path as normal white boxes, and store their coordinates
			if(col>0 && col<6 && row == 1)
				bs.redpath[col+(row)*6].setType_setColor(34, colors[RED]);	//update type and color
			else if((col == 1 && row == 0))
				bs.redpath[col+(row)*6].setType_setColor(74, colors[RED]);	//update type and color
			else if(col==2 && row == 2)
				bs.redpath[col+(row)*6].setType_setColor(4, colors[DIM_GRAY]);	//update type and color
		}
	}
	Rectangle** recs;
	recs = (Rectangle**)malloc (5*sizeof(Rectangle*));		//to fill the 5 squares of the blue path.
	int i=0;
	for( i=0; i<5; i++)
	{
		recs[i] = new Rectangle(x+1, y-(i+1)*box_width+1, box_width-1, box_width-1, colors[RED]);
	}
	for(int i=0; i<5; i++)
	{
		recs[i]->ShowRectangle();
		if(i==3)
		{
			Rectangle* rec6 = new Rectangle(x+box_width+1, y-(i+1)*box_width+1, box_width-1, box_width-1, colors[DIM_GRAY]);
			rec6->ShowRectangle();
		}
		else if(i==4)
		{
			Rectangle* rec7 = new Rectangle(x-box_width+1, y-(i+1)*box_width+1, box_width-1, box_width-1, colors[RED]);
			rec7->ShowRectangle();
		}
	}
}



void Board::draw_Tokens_Base(float* Color, int x, int y, int w, int num_lines, string Type)
{
	//cout<<"Drawing Tokens"<<endl;

	int X =0,Y=0;	//about to save bs->blue yard coordinates
	RoundRectangle yardPos1(x+0.5*w, y+0.5*w, w, w, 7, Color);	//make the blue spots in home, one for each token
	yardPos1.ShowRoundRectangle();
	RoundRectangle yardPos2(x+2.5*w, y+0.5*w, w, w, 7, Color);	//make the blue spots in home, one for each token
	yardPos2.ShowRoundRectangle();

	RoundRectangle yardPos3(x+0.5*w, y+2.5*w, w, w, 7, Color);	//make the blue spots in home, one for each token
	yardPos3.ShowRoundRectangle();

	RoundRectangle yardPos4(x+2.5*w, y+2.5*w, w, w, 7, Color);	//make the blue spots in home, one for each token
	yardPos4.ShowRoundRectangle();

	if(Type == "LIGHT_BLUE")
	{
		bs.blueyard[0].setCoordinates(x+0.5*w, y+0.5*w, colors[LIGHT_BLUE], w, w, 21);
		bs.blueyard[1].setCoordinates(x+2.5*w, y+0.5*w, Color, w, w, 21);
		bs.blueyard[2].setCoordinates(x+0.5*w, y+2.5*w, Color, w, w, 21);
		bs.blueyard[3].setCoordinates(x+2.5*w, y+2.5*w, Color, w, w, 21);
	}
	else if(Type == "ORANGE")
	{
		bs.yellowyard[0].setCoordinates(x+0.5*w, y+0.5*w, Color, w, w, 22);
		bs.yellowyard[1].setCoordinates(x+2.5*w, y+0.5*w, Color, w, w, 22);
		bs.yellowyard[2].setCoordinates(x+0.5*w, y+2.5*w, Color, w, w, 22);
		bs.yellowyard[3].setCoordinates(x+2.5*w, y+2.5*w, Color, w, w, 22);
	}
	else if(Type == "GREEN")
	{
		bs.greenyard[0].setCoordinates(x+0.5*w, y+0.5*w, Color, w, w, 23);
		bs.greenyard[1].setCoordinates(x+2.5*w, y+0.5*w, Color, w, w, 23);
		bs.greenyard[2].setCoordinates(x+0.5*w, y+2.5*w, Color, w, w, 23);
		bs.greenyard[3].setCoordinates(x+2.5*w, y+2.5*w, Color, w, w, 23);
	}
	else if(Type == "RED")
	{
		bs.redyard[0].setCoordinates(x+0.5*w, y+0.5*w, Color, w, w, 24);
		bs.redyard[1].setCoordinates(x+2.5*w, y+0.5*w, Color, w, w, 24);
		bs.redyard[2].setCoordinates(x+0.5*w, y+2.5*w, Color, w, w, 24);
		bs.redyard[3].setCoordinates(x+2.5*w, y+2.5*w, Color, w, w, 24);
	}
	else
	{
		cout<<"No such yard"<<endl;
	}

}

void Board::drawBoard()
{
	int num_lines = 16;
	int box_width = 40;
	for(int i=0; i<num_lines; i++)
	{
		//vertical lines
		DrawLine(x+i*box_width, y, x+i*box_width, y+box_width*(num_lines-1), 2, colors[BLACK]);
		//horizontal lines
		DrawLine(x, y+i*box_width, x+box_width*(num_lines-1), y+i*box_width, 2, colors[BLACK]);
	}
// for reference
//	Rectangle::Rectangle(int X, int Y, int Width, int Height, float *Color) : Shape(X,Y,Color)
//	RoundRectangle::RoundRectangle(float X, float Y, float w, float h,  float r,float* Color): Shape(X, Y, Color)


	//cout<<"x = "<<x<<"\t y = "<<y<<endl;

	//Draw Rectangles and inner RoundRectangles here
	Rectangle rec1(x, y+box_width*(num_lines-7), 6*box_width, 6*box_width, colors[LIGHT_BLUE]);
	rec1.ShowRectangle();	//Here the home base colors and the size of the home can be set

	//cout<<"Shown blue yard"<<endl;
	RoundRectangle rrec1(x+1*box_width, y+box_width*(num_lines-7)+1*box_width, 4*box_width, 4*box_width, 7, colors[WHITE]);
	rrec1.ShowRoundRectangle();
	draw_Tokens_Base(colors[LIGHT_BLUE], x+1*box_width, y+box_width*(num_lines-7)+1*box_width, box_width, num_lines, "LIGHT_BLUE");
	//cout<<"Returned from tokens"<<endl;

	//the five coordinates required for drawing home triangles
	int X1 = x+box_width*(num_lines-10), Y1 = y+box_width*(num_lines-7);	//top left corner
	int X2 = x+box_width*(num_lines-10), Y2 = y+box_width*(num_lines-10);	//bottom left corner
	int X3 = x+box_width*(num_lines-7),  Y3 = y+box_width*(num_lines-7);	//top right corner
	int X4 = x+box_width*(num_lines-7), Y4 = y+box_width*(num_lines-10);	//bottom right corner
	int X5 = x+box_width*(num_lines-8.5), Y5 =y+box_width*(num_lines-8.5);	//center coordinate

	Rectangle rec2(x+box_width*(num_lines-7), y+box_width*(num_lines-7), 6*box_width, 6*box_width, colors[ORANGE]);
	rec2.ShowRectangle();	//Here the home base colors and the size of the home can be set
	RoundRectangle rrec2((x+1*box_width)+box_width*(num_lines-7), y+box_width*(num_lines-7)+1*box_width, 4*box_width, 4*box_width, 7, colors[WHITE]);
	rrec2.ShowRoundRectangle();
	draw_Tokens_Base(colors[ORANGE], (x+1*box_width)+box_width*(num_lines-7), y+box_width*(num_lines-7)+1*box_width, box_width, num_lines, "ORANGE");

	Rectangle rec3(x+box_width*(num_lines-7), y, 6*box_width, 6*box_width, colors[GREEN]);
	rec3.ShowRectangle();	//Here the home base colors and the size of the home can be set
	RoundRectangle rrec3((x+1*box_width)+box_width*(num_lines-7), y+1*box_width, 4*box_width, 4*box_width, 7, colors[WHITE]);
	rrec3.ShowRoundRectangle();
	draw_Tokens_Base(colors[GREEN], (x+1*box_width)+box_width*(num_lines-7), y+1*box_width, box_width, num_lines, "GREEN");

	Rectangle rec4(x, y, 6*box_width, 6*box_width, colors[RED]);
	rec4.ShowRectangle();	//Here the home base colors and the size of the home can be set
	RoundRectangle rrec4((x+1*box_width), (y+1*box_width), 4*box_width, 4*box_width, 7, colors[WHITE]);
	rrec4.ShowRoundRectangle();
	draw_Tokens_Base(colors[RED], (x+1*box_width), (y+1*box_width), box_width, num_lines, "RED");

	DrawTriangle(X1, Y1, X2, Y2, X5, Y5, colors[LIGHT_BLUE]);
	bs.bluehome.setCoordinates(X1, Y1-2*box_width, colors[LIGHT_BLUE], box_width, box_width, 61);	// Exact center shown in draw_Blue_Path ftn.
//	DrawRectangle(X1, Y1-2*box_width, 5, 5, colors[BLACK]);


	DrawTriangle(X1, Y1, X3, Y3, X5, Y5, colors[ORANGE]);
	bs.yellowhome.setCoordinates(X1+box_width, Y1-box_width, colors[ORANGE], box_width, box_width, 62);
//	DrawRectangle(X1+box_width, Y1-box_width, 5, 5, colors[BLACK]);

	DrawTriangle(X3, Y3, X4, Y4, X5, Y5, colors[GREEN]);
	bs.greenhome.setCoordinates(X3-box_width, Y1-2*box_width, colors[GREEN], box_width, box_width, 63);
//	DrawRectangle(X3-box_width, Y1-2*box_width, 5, 5, colors[BLACK]);

	DrawTriangle(X2, Y2, X4, Y4, X5, Y5, colors[RED]);
	bs.redhome.setCoordinates(X2+box_width, Y2, colors[RED], box_width, box_width, 64);
//	DrawRectangle(X2+box_width, Y2, 5, 5, colors[BLACK]);

	draw_Blue_Path(X1, Y1-box_width, box_width);	//color 5 boxes to the left + 1 box above the leftmost.
	draw_Yellow_Path(X1+box_width, Y1, box_width);	//color 5 boxes to the left + 1 box above the leftmost.
	draw_Green_Path(X3, Y3-box_width, box_width);	//color 5 boxes to the left + 1 box above the leftmost.
	draw_Red_Path(X4-2*box_width, Y4, box_width);	//color 5 boxes to the left + 1 box above the leftmost.


}


Board::~Board()
{

}
