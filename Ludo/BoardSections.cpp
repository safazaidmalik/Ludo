/*
 * BoardSections.cpp
 *
 *  Created on: Jun 12, 2021
 *      Author: szm
 */

#include "BoardSections.h"


BoardSections::BoardSections()
{
	Coordinates empty(0,0,colors[BLACK],0,0,0);
	bluehome = empty;
	yellowhome = empty;
	greenhome = empty;
	redhome = empty;

	blueyard = new Coordinates[4];
	yellowyard = new Coordinates[4];
	greenyard = new Coordinates[4];
	redyard = new Coordinates[4];
	for(int i=0; i<4; i++)
	{
		blueyard[i] =  empty;
		yellowyard[i] =  empty;
		greenyard[i] =  empty;
		redyard[i] =  empty;
	}

	bluepath = new Coordinates[18];
	yellowpath = new Coordinates[18];
	greenpath = new Coordinates[18];
	redpath = new Coordinates[18];
	for(int i=0; i<18; i++)
	{
		bluepath[i] =  empty;
		yellowpath[i] =  empty;
		greenpath[i] =  empty;
		redpath[i] =  empty;

	}
}


//
BoardSections::~BoardSections() {
}
