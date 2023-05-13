/*
 * BoardSections.h
 *
 *  Created on: Jun 12, 2021
 *      Author: szm
 */

#ifndef BOARDSECTIONS_H_
#define BOARDSECTIONS_H_
#include"Coordinates.h"

struct BoardSections {
	Coordinates bluehome;
	Coordinates yellowhome;
	Coordinates greenhome;
	Coordinates redhome;

	Coordinates* blueyard;
	Coordinates* yellowyard;
	Coordinates* greenyard;
	Coordinates* redyard;

	Coordinates* bluepath;
	Coordinates* yellowpath;
	Coordinates* greenpath;
	Coordinates* redpath;


	BoardSections();
	virtual ~BoardSections();
};

#endif /* BOARDSECTIONS_H_ */
