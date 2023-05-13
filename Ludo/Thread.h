/*
 * Thread.h
 *
 *  Created on: Jun 14, 2021
 *      Author: sillpill
 */

#ifndef  THREAD_H_
#define THREAD_H_

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
struct eachTurn
{
int val;
bool turnvalue;
eachTurn()
{
	val=-1;
	turnvalue=false;
}
};
struct Threads
{
  pthread_t ParentThread;
  int type[4];
  bool initializeType;
  pthread_t playerThreads[4];
  eachTurn turns[4];
  bool MovementDone[4];
  int total_players;
  int dicecount;
  int playercount;
  bool waitForMovement;
  pthread_mutex_t Dicemutex;
  sem_t s1;
  sem_t s2;
  sem_t s3;
  sem_t s4;
  int players;
Threads()
  {
	initializeType=false;
	players=4;
	ParentThread=0;
	for(int i=0 ; i<4 ; i++)
		{
		playerThreads[i]=0;
         type[i]=0;
		}
	waitForMovement=false;
	total_players=4;
	dicecount=0;
	playercount=0;
	sem_init(&s1,0,1);
	sem_init(&s2,0,1);
	sem_init(&s3,0,1);
	sem_init(&s4,0,1);
  }
//void *DiceRoll(void *obj);
};
#endif /* PLAYERS_H_ */
