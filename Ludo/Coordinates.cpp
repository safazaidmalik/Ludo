/*
 * Coordinates.cpp
 *
 *  Created on: Jun 12, 2021
 *      Author: szm
 */

#include "Coordinates.h"

Coordinates::Coordinates() {
	//default constr. should not be called
	xcoor =0;
	ycoor=0;
	color = colors[BLACK];
	width = 0;
	height = 0;
	typeOfBox = 0;		//to be able to identify that the wrong constructor is being called, check if type is indeed 0.
}

Coordinates::Coordinates(int X, int Y, float* Color, float Width, float Height, int Type)
{
	xcoor =X;
	ycoor=Y;
	color = Color;
	width = Width;
	height = Height;
	typeOfBox = Type;

}

void Coordinates::setColor(float* Color)
{
	color = Color;
}

void Coordinates::setColor(string Color)
{
	if(Color=="Light_BLUE")
		color = colors[LIGHT_BLUE];
}

void Coordinates::setCoordinates(int X, int Y, float* Color, float Width, float Height, int Type)
{
	xcoor =X;
	ycoor=Y;
	color = Color;
	width = Width;
	height = Height;
	typeOfBox = Type;
}
void Coordinates::setCoordinates(int X, int Y, string Color, float Width, float Height, int Type)
{
	xcoor =X;
	ycoor=Y;
//	color = Color;
	this->setColor(Color);
	width = Width;
	height = Height;
	typeOfBox = Type;
}

void Coordinates::setType_setColor(int Type, float* Color)
{
	this->typeOfBox = Type;
	this->color = Color;
}
void Coordinates::setType(int Type)
{
	if((Type>=21 && Type<=24) || (Type>=31 && Type<=34) || (Type>=61 && Type<=64) || Type==1 ||Type==4 || Type==5)
		this->typeOfBox =Type;
	else
	{
		cout<<"No such type exists !!"<<endl;
	}

}


void Coordinates::showCoordinates()
{
	//cout<<"Entered showCoordinates()"<<endl;
	//cout<<"Coordinates = ("<<xcoor<<", "<<ycoor<<")"<<endl;

	//cout<<"Width = "<<width<<"\t Height = "<<height<<endl;
	//type = 1 -> normal
	//type = 21 -> blue's base/home yard
	//type = 22 -> yellow's base
	//type = 23 -> green's base
	//type = 24 -> red's base
	//type = 31 -> blue's home path
	//type = 32 -> yellow's home path
	//type = 33 -> green's home path
	//type = 34 -> red's home path
	//type = 4 -> safe zone
	//type = 5 -> Box holds a Goti
	//type = 61 -> Blue's home
	//type = 62 -> Yellow's home
	//type = 63 -> Green's home
	//type = 64 -> Red's home
	//type = 71 -> Blue's starting point + everyone's safe zone
	//type = 72 -> Yellow's starting point + everyone's safe zone
	//type = 73 -> Green's starting point + everyone's safe zone
	//type = 74 -> Red's starting point + everyone's safe zone
/*

	cout<<"Type = ";
	if(typeOfBox == 1)
		cout<<"Normal sqaure"<<endl;
	else if(typeOfBox == 21)
		cout<<"Blue's home yard"<<endl;
	else if(typeOfBox == 22)
		cout<<"Yellow's home yard"<<endl;
	else if(typeOfBox == 23)
		cout<<"Green's home yard"<<endl;
	else if(typeOfBox == 24)
		cout<<"Red's home yard"<<endl;
	else if(typeOfBox == 31)
		cout<<"Blue's home path"<<endl;
	else if(typeOfBox == 32)
		cout<<"Yellow's home path"<<endl;
	else if(typeOfBox == 33)
		cout<<"Green's home path"<<endl;
	else if(typeOfBox == 34)
		cout<<"Red's home path"<<endl;
	else if(typeOfBox == 4)
		cout<<"Safe zone"<<endl;
	else if(typeOfBox == 5)
	{
		cout<<"Goti present here"<<endl;
	}
	else if(typeOfBox == 61)
		cout<<"Blue's home"<<endl;
	else if(typeOfBox == 62)
		cout<<"Yellow's home"<<endl;
	else if(typeOfBox == 63)
		cout<<"Green's home"<<endl;
	else if(typeOfBox == 64)
		cout<<"Red's home"<<endl;
	else if(typeOfBox == 71)
		cout<<"Blue's starting point"<<endl;
	else if(typeOfBox == 72)
		cout<<"Yellow's starting point"<<endl;
	else if(typeOfBox == 73)
		cout<<"Green's starting point"<<endl;
	else if(typeOfBox == 74)
		cout<<"Red's starting point"<<endl;
	else
	{
		cout<<"No such type exists!!"<<endl;
	}
	cout<<endl;
*/
}

void Coordinates::copyCoordinates(Coordinates& coords)
{
	this->xcoor = coords.xcoor;
	this->ycoor = coords.ycoor;
	this->width = coords.width;
	this->height = coords.height;
	this->typeOfBox = coords.typeOfBox;

}

//Coordinates::~Coordinates() {
//	// TODO Auto-generated destructor stub
//}
