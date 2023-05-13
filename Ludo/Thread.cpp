/*
 * Thread.cpp
 *
 *  Created on: Jun 14, 2021
 *      Author: sillpill
 */

#include "Thread.h"

Threads::Threads() {

	ParentThread=0;
		for(int i=0 ; i<4 ; i++)
			playerThreads[i]=0;
		waitForMovement=false;
		total_players=4;
		dicecount=0;
		playercount=0;
		sem_init(&s1,0,0);
		sem_init(&s2,0,0);
		sem_init(&s3,0,0);
		sem_init(&s4,0,0);// TODO Auto-generated constructor stub

}
