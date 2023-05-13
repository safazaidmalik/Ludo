/*
 * main.cpp
 *
 *  Created on: Jun 10, 2021
 *      Author: szm
 */



#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include"CImg.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
#include"RoundRectangle.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include"RoundRectangle.h"
#include"Line.h"
#include"Board.h"
#include"Player.h"
#include"Thread.h"
Game Ludo;
Threads Ludothreads;
Board b(80,80,colors[SKY_BLUE]);
PlayersPathways pp;
int xcoor;
int ycoor;
void drawAxes()
{
	for(int X=0; X<800; X++)
	{
		if(X%40 == 0)
		{
			DrawLine(X,0, X, 5, 3, colors[BLACK]);
			DrawString(X, 6,to_string(X), colors[BLACK]);
			DrawLine(0,X, 5, X, 3, colors[BLACK]);
			DrawString(6, X,to_string(X), colors[BLACK]);
		}
	}
}

bool TokenCheck=false;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Main Canvas drawing function.
 * */



//void GameDisplay()
//{
//	// set the background color using function glClearColor.
//	// to change the background play with the red, green and blue values below.
//	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
//
////Setting canvas color
//	glClearColor(0.501960784313726, 0, 0.501960784313726 ,1);/*Alpha component*/ // Red==Green==Blue==1 --> White Colour
//	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
//
//	/*if(TokenCheck==false)
//	{
//		int x;
//		cout<<"enter the number of tokens you want"<<endl;
//	    cin>>x;
//	    Ludo.NoOfTokens=x;
//	    TokenCheck=true;
//	}
//*/
//	Board b(80, 80, colors[SKY_BLUE]);	//for blue home
//	b.drawBoard();
//	cout<<"Drawn borad"<<endl;
//    //Ludo.SetInitialGotis();
//	//add axes on screen
//	drawAxes();
//	cout<<"Drawn axes"<<endl;
//	//sem_init(&Ludothreads.Dicemutex, 0, 4);
//
//
//
//	//DrawRoundRect(40, 40, 40, 40, colors[RED],3);
//
//	glutSwapBuffers(); // do not modify this line..
//}
bool initializer=false;
int selection_box_coor[2];
int release_box_coor[2];
int status ;
//int inc=5;
void GameDisplay()
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

//Setting canvas color
	glClearColor(0.690196078431373, 0.768627450980392, 0.870588235294118, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//Screen is black at default
	glClearColor(1, 1,1, 1 ); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

 b.drawBoard();

	//cout<<"Ludooooooo: "<<Ludo.players[0].Roll.D[0]<<endl;
	Ludo.players[0].displayPlayerDice(740, 500, 1);
	Ludo.players[1].displayPlayerDice(740, 400, 2);
	Ludo.players[2].displayPlayerDice(740, 300, 3);
	Ludo.players[3].displayPlayerDice(740, 200, 4);

	if(initializer==false)
	{
    Ludo.SetInitialGotis(b);
    Ludo.players[0].PlayerWindow=true;
//    Ludo.players[0].hitrate=1;
    Ludo.players[1].PlayerWindow=true;
//    Ludo.players[1].hitrate=1;
    Ludo.players[2].PlayerWindow=true;
//    Ludo.players[2].hitrate=1;
    Ludo.players[3].PlayerWindow=true;
//    Ludo.players[3].hitrate=1;
    pp.setPathwayCoordinates(b.bs);
    //Ludo.players[3].p_tokens[0].t_pos.xcoor=pp.red_player_path[48].xcoor;
    //Ludo.players[3].p_tokens[0].t_pos.ycoor=pp.red_player_path[48].ycoor;
    //Ludo.players[3].hitrate=1;
    initializer=true;
	}
/*
	if(Ludo.DiceRewind==true)
	{


	     int x2=0,x3=0;
	     for(int i=0 ; i<4 ; i++)
	     {
	    	 x2=0;x3=0;
	     		int x=rand()%6+1;

	     		//cout<<"count: "<<count_time<<endl;

	     		if(x==6)
	     			x2=rand()%6+1;
	     	if(x2==6)
	     		{
	     			x3=rand()%6+1;

	     		}
	     		if(x==0 && x2==0 && x3==0)
	     		{
	     			x=0;
	     			x2=0;
	     			x3=0;
	     		}
	     		cout<<"x1: "<<x<<endl;
	     		cout<<"x2: "<<x2<<endl;
	     		cout<<"x3: "<<x3<<endl;
	     		 Ludo.players[i].Roll.D[0]=x;
	     			        Ludo.players[i].Roll.D[1]=x2;
	     			        Ludo.players[i].Roll.D[2]=x3;

	     }
	     Ludo.DiceRewind=false;
	     Ludo.players[0].PlayerWindow=true;

	}
*/
	int xdis=760;
	int ydis=600;

	if(Ludo.players[0].PlayerWindow==true)
	{
		string player_label="It's Player 1's Turn";
		DrawString(xdis, ydis, player_label, colors[BLACK]);
	}
	else if(Ludo.players[1].PlayerWindow==true)
	{

		string player_label="It's Player 2's Turn";
		DrawString(xdis, ydis, player_label, colors[BLACK]);

	}
	else if(Ludo.players[2].PlayerWindow==true)
	{

		string player_label="It's Player 3's Turn";
		DrawString(xdis, ydis, player_label, colors[BLACK]);

	}else if(Ludo.players[3].PlayerWindow==true)
	{

		string player_label="It's Player 4's Turn";
		DrawString(xdis, ydis, player_label, colors[BLACK]);

	}
//cout<<"Ludo.players[0].PlayerWindow: "<<Ludo.players[0].PlayerWindow<<endl;
//cout<<"WHta is happening: "<<endl;
	Ludo.setGotiPosition();
	Ludo.SelectionGoti(xcoor-15, ycoor-15);

	Ludo.MoveGoti(xcoor, ycoor,status,b,pp);
	//cout<<"resumed: "<<endl;
   // pp.show_Player_Pathways();

	drawAxes();

	glutSwapBuffers(); // do not modify this line..
}



void Timer(int m) {

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
	glutPostRedisplay();
}
void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed..


	}
	else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		//da+=10;
	}
	else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if(key=='s')
	{
    cout<<"key s has been pressedsdklanfdslfbsdkfkdsfbkdsfbkdsfkdsfksdfbsdkfbkdsfbkds"<<endl;
	}
	else if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

		glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */

//static bool thispressed=false;

void MousePressedAndMoved(int x, int y) {

	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {
//	cout << x << " " <<700- y << endl;

}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */

void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
     // cout<<"state: "<<state<<endl;
     // cout<<"x: "<<x<<endl;
      //cout<<"y: "<<700-y<<endl;
      xcoor=x;
      ycoor=700-y;
      status=state;


	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}


		glutPostRedisplay();

}





int playerID=1;

int movementID=1;
int count_time=0;
int move_time=0;
bool allnotdone=true;
void * ThreadCreation(void *obj)
{

	//cout<<"Parent Thread: "<<pthread_self( )<<endl;

	while(1)
	{
		//sleep(5);

		sem_wait(&Ludothreads.s1);
		cout<<"Parent Thread: "<<pthread_self( )<<endl;

		int x2=0,x3=0;
		int x=rand()%6+1;

		cout<<"count: "<<count_time<<endl;

		if(x==6)
			x2=rand()%6+1;
		/*else */if(x2==6)
		{
			x3=rand()%6+1;

		}
		if(x==0 && x2==0 && x3==0)
		{
			x=0;
			x2=0;
			x3=0;
		}
		cout<<"x1: "<<x<<endl;
		cout<<"x2: "<<x2<<endl;
		cout<<"x3: "<<x3<<endl;
//	    Ludothreads.dicecount++;
        count_time++;

        if(count_time==4)
        	{
        	count_time=0;
        	}
        if(Ludothreads.playerThreads[0]==pthread_self() && Ludo.players[0].PlayerWindow==false)
           {
        	Ludo.players[0].Roll.D[0]=x;
        	Ludo.players[0].Roll.D[1]=x2;
        	Ludo.players[0].Roll.D[2]=x3;

           }
        else if(Ludothreads.playerThreads[1]==pthread_self() && Ludo.players[1].PlayerWindow==false)
        {
        	Ludo.players[1].Roll.D[0]=x;
        	Ludo.players[1].Roll.D[1]=x2;
            Ludo.players[1].Roll.D[2]=x3;

        }
        else if(Ludothreads.playerThreads[2]==pthread_self() && Ludo.players[2].PlayerWindow==false)
                {
                	Ludo.players[2].Roll.D[0]=x;
                	Ludo.players[2].Roll.D[1]=x2;
                    Ludo.players[2].Roll.D[2]=x3;

                }
        else if(Ludothreads.playerThreads[3]==pthread_self() && Ludo.players[3].PlayerWindow==false)
                {
                	Ludo.players[3].Roll.D[0]=x;
                	Ludo.players[3].Roll.D[1]=x2;
                    Ludo.players[3].Roll.D[2]=x3;

                }


     sem_post(&Ludothreads.s1);



 	sem_wait(&Ludothreads.s2);
 	cout<<"player 0: "<<Ludo.players[0].PlayerWindow<<"lol"<<endl;
	cout<<"player 1: "<<Ludo.players[1].PlayerWindow<<"lol"<<endl;
	cout<<"player 2: "<<Ludo.players[2].PlayerWindow<<"lol"<<endl;
	cout<<"player 3: "<<Ludo.players[3].PlayerWindow<<"lol"<<endl;
 	// int playerno=Ludothreads.turns[move_time].val;
   int whichplayer=-1;
   cout<<"the thread itself: "<<pthread_self()<<endl;
 	if(Ludothreads.playerThreads[0]==pthread_self())
    {
    	Ludo.players[0].PlayerWindow=true;
    	whichplayer=0;

    }

    else if(Ludothreads.playerThreads[1]==pthread_self())
    {
    	Ludo.players[1].PlayerWindow=true;
    	whichplayer=1;

    }
    else if(Ludothreads.playerThreads[2]==pthread_self())
       {
    	Ludo.players[2].PlayerWindow=true;
    	whichplayer=2;
       }
    else if(Ludothreads.playerThreads[3]==pthread_self())
       {
    	Ludo.players[3].PlayerWindow=true;
    	whichplayer=3;
       }

 	cout<<"which player: "<<whichplayer<<endl;
    /*for(int i=0 ; i<4 ; i++)
    {
    	if(Ludo.players[i].PlayerWindow==true)
    	{
    		Ludothreads.turns[move_time].val=i;//saving which thread id did the first movement
    		Ludothreads.turns[move_time].turnvalue=true;//the movment has been done
    	}
    }*/
 while(Ludo.players[whichplayer].PlayerWindow==true)
 {
	 //busy wait
 }

       cout<<"the movetime: "<<move_time<<endl;
       move_time++;
       if(move_time==4)
       {  	move_time=0;
       Ludo.players[0].PlayerWindow=false;
       Ludo.players[1].PlayerWindow=false;
       Ludo.players[2].PlayerWindow=false;
       Ludo.players[3].PlayerWindow=false;
       //udo.DiceRewind=true;
       }
 	 sem_post(&Ludothreads.s2);
 	 sleep(5);
 	 //sleep(1);
		//Ludo.DiceRewind=true;
 	// while(Ludo.DiceRewind==false)
 	 //{
       // cout<<"ludo dice cant be started again"<<endl;
 	 //}
 	//	 while(allnotdone){};
 	//	allnotdone=true;


//   sleep(1);

	}
}

int main(int argc, char*argv[]) {

	int width = 1000, height = 700; // i have set my window size to be 600 x 600
	 srand(0);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OS Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    /*int x;
	cout<<"Enter the number of tokens you want"<<endl;
        cin>>x;
        while(x<0)
        {

        	cout<<"Enter the number of tokens you want"<<endl;
                cin>>x;

        }
        */
        //Ludo.NoOfTokens=4;
        Ludo.players->NoTokens=4;


	    glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.



    	pthread_create(&Ludothreads.playerThreads[0],NULL,ThreadCreation,(void*)&Ludo);
		pthread_create(&Ludothreads.playerThreads[1],NULL,ThreadCreation,(void*)&Ludo);
	    pthread_create(&Ludothreads.playerThreads[2],NULL,ThreadCreation,(void*)&Ludo);
	     pthread_create(&Ludothreads.playerThreads[3],NULL,ThreadCreation,(void*)&Ludo);
	    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
		glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
		// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
		glutTimerFunc(1000.0, Timer, 0);

		glutMouseFunc(MouseClicked);
		glutPassiveMotionFunc(MouseMoved); // Mouse
		glutMotionFunc(MousePressedAndMoved); // Mouse

		// now handle the control to library and it will call our registered functions when
		// it deems necessary...
		glutMainLoop();
}
#endif /* AsteroidS_CPP_ */
