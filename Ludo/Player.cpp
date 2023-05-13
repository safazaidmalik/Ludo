/*
 * Player.cpp
 *
 *  Created on: Jun 3, 2020
 *      Author: szm
 */

#include "Player.h"
#include"Board.h"
#include"CImg.h"
//player[0]=blue;
//player[1]=yellow
//player[2]=green
//player[3]=red
int inc=5;
void Game::MoveGoti(int x,int y,int state,Board& b,PlayersPathways &pp)
{
cout<<"the state: "<<state<<endl;
cout<<"the player 1: "<<this->players[0].PlayerWindow<<endl;
cout<<"the player 2: "<<this->players[1].PlayerWindow<<endl;
cout<<"the player 3: "<<this->players[2].PlayerWindow<<endl;
cout<<"the player 4: "<<this->players[3].PlayerWindow<<endl;
 ////cout<<"this->players[1].PlayerWindow: "<<this->players[1].PlayerWindow<<endl;
if(this->players[0].PlayerWindow==true && state==0)//the mouse has been clicked
{
	CheckConditionsP1( x, y,state,b,pp);
	cout<<"this->players[0].PlayerWindow: "<<this->players[0].PlayerWindow<<endl;
    cout<<"his->players[0].Roll.D[0]==0: "<<this->players[0].Roll.D[0]<<endl;

   /* if(this->players[0].Roll.D[0]==0 &&  this->players[0].PlayerWindow==false)
    	{
    		    cout<<"wtttf"<<endl;
    		this->players[1].PlayerWindow=true;
    	}
    	*/

}	else if(this->players[1].PlayerWindow==true && state==0)
	{
		////cout<<"yyyaarr"<<endl;
		CheckConditionsP2( x, y,state,b,pp);
		/*if(this->players[1].Roll.D[0]==0 &&  this->players[1].PlayerWindow==false)
		{
			this->players[2].PlayerWindow=true;
		}
		*/

	}
	else if(this->players[2].PlayerWindow==true && state==0)
	{
		CheckConditionsP3( x, y,state,b,pp);
		/*if(this->players[2].Roll.D[0]==0 &&  this->players[2].PlayerWindow==false)
		{
			this->players[3].PlayerWindow=true;
		}
		*/

	}
	else if(this->players[3].PlayerWindow==true && state==0)
	{
		CheckConditionsP4( x, y,state,b,pp);
	}


}
void Game:: CheckConditionsP1(int x,int y,int state,Board& b,PlayersPathways &pp)
{
	int pl=0;
	int s=this->players[pl].size;
	bool tokenFound=false;
	int xc=0;
	int yc=0;
	bool dontAssign=false;
	int goti=0;//saving the index of the goti
	int DiceNumber=this->players[pl].DiceTime;//tracking which dice are we on
	int dicevalue=this->players[pl].Roll.D[DiceNumber];//finding the dicevalue at that turn of the dice
	int count=0;

		 for(int i=0 ; i<this->players[pl].NoTokens && tokenFound==false ; i++)
		 		     {
		 		    	 xc=this->players[pl].p_tokens[i].t_pos.xcoor;//the current coordinates of the gotis
		 		    	 yc=this->players[pl].p_tokens[i].t_pos.ycoor;//the current coordinates of the gotis

		 		    	if(x>xc && x<xc+s )
		 		    	{
		 		    		 if(y>yc && y<yc+s)
		 		    		 {
		 		    			 goti=i;
		 		    			tokenFound=true;

		 		    		 }
		 		    	}
		 		     }

		 	if(tokenFound)//incae the token is found then do other stuff , otherwise ignore
		 	{
		 		     cout<<"goti: "<<goti<<endl;
		 		      cout<<"token found"<<endl;
		 		      //checking if all tokens are in home yard

		 		     for(int j=0 ; j<this->players[pl].NoTokens ; j++)
		 		         {
		 		         if(this->players[pl].p_tokens[j].t_pos.xcoor==b.bs.blueyard[j].xcoor)
		 		          	if(this->players[pl].p_tokens[j].t_pos.ycoor==b.bs.blueyard[j].ycoor)
		 		          	{
		 		     	  count++;
		 		            cout<<"the count: "<<count<<endl;
		 		          	}

		 		     	}
		 		     	if(count==4 && dicevalue<6)//all gotis in the home yard
		 		     	{
		 		                cout<<"all in home yard"<<endl;
		 		     		   DiceNumber=3;
		 		     		   this->players[pl].DiceTime=0;
		 		     		   this->players[pl].Roll.D[0]=0;
		 		     		   this->players[pl].PlayerWindow=false;
		 		     		 //  this->DiceRewind=true;
		 		     		    dontAssign=true;
		 		     	 }
		 		     else//this else will have all assugnments
		 		     {


		 		//checking if the token is in the home yard;
		 		     bool TokenInHomeYard=false;
		 		   for(int i=0 ; i<this->players[pl].NoTokens ; i++)
		 		   {
		 			   if(xc==b.bs.blueyard[i].xcoor && yc==b.bs.blueyard[i].ycoor)
		 				   TokenInHomeYard=true;

		 		   }
		 		  if(TokenInHomeYard)
		 		  {
		                if(dicevalue==6)
		                {
		             	   cout<<"the dice value is 6"<<endl;
		             	   xc=pp.blue_player_path[1].xcoor;
		             	   yc=pp.blue_player_path[1].ycoor;
		             	   DiceNumber++;
		                }

		               cout<<"what is the issue"<<endl;
		 		  }
		 		  else//dice is not in the home yard
		 		  {

		              bool refound=false;
					  for(int i=0 ; i<58 && refound==false ; i++)
					  {
						  if(xc==pp.blue_player_path[i].xcoor && yc==pp.blue_player_path[i].ycoor)
						  {
							 if(i+dicevalue<57 && i+dicevalue>51)//stuck in the home path
							 {
//							  DiceNumber++;
								 if(this->players[pl].hitrate>0)
								 {
									 xc=pp.blue_player_path[i+dicevalue].xcoor;
									 yc=pp.blue_player_path[i+dicevalue].ycoor;
									 DiceNumber++;
									 refound=true;
								 }
								 else
								 {
									 int remain=i+dicevalue-51;
									 remain--;
									 xc=pp.blue_player_path[remain].xcoor;
								     yc=pp.blue_player_path[remain].ycoor;
									 DiceNumber++;
									 refound=true;

								 }
							 }
							 else if(i+dicevalue==57)
							 {
								 xc=-300;
								 yc=-300;
					             DiceNumber++;
								 refound=true;
								 this->players[pl].p_tokens[goti].reached_home=true;
							 }
							 else  if(i+dicevalue>57)
							 {
				                 DiceNumber++;
								 refound=true;
							 }
							 else
							 {
								 xc=pp.blue_player_path[i+dicevalue].xcoor;
								 yc=pp.blue_player_path[i+dicevalue].ycoor;
								 DiceNumber++;
								 refound=true;
							 }

						  }
					  }


		 		  }
		 			cout<<"THE DICENUMBER: "<<DiceNumber<<endl;
		 		  	  	  	  	  	if(!dontAssign)
									{

									cout<<"none in home yard"<<endl;
		  							this->players[pl].p_tokens[goti].t_pos.xcoor=xc;//the current coordinates of the gotis
		    						this->players[pl].p_tokens[goti].t_pos.ycoor=yc;//the current coordinates of the gotis
		    						int previousDice=DiceNumber;
		    						previousDice--;
		    						this->players[pl].Roll.D[previousDice]=0;
		    						this->players[pl].DiceTime=DiceNumber;

                                   }
		 	     }
		 		     	            if(this->players[pl].Roll.D[0]==0 && this->players[pl].Roll.D[1]==0 &&this->players[pl].Roll.D[2]==0)
		 		                   {
		 	                        this->players[pl].PlayerWindow=false;
		 		     			 	this->players[pl].DiceTime=0;
		 		     			 	//this->DiceRewind=true;
		 		     			 	}

            }



}
void Game::setGotiPosition()
{

	for(int j=0 ; j<this->players[0].NoTokens ; j++)
	{
		////cout<<"inside drawing: "<<this->players[0].p_tokens[j].t_pos.ycoor<<endl;
		////cout<<"inside drawing: "<<this->players[0].p_tokens[j].t_pos.xcoor<<endl;
		//this->DrawGotiBlue(this->players[0].Goti[j].xcoor+inc, this->players[0].Goti[j].ycoor+inc);
	this->DrawGotiBlue(this->players[0].p_tokens[j].t_pos.xcoor+inc, this->players[0].p_tokens[j].t_pos.ycoor+inc);


	}
	for(int j=0 ; j<this->players[0].NoTokens ; j++)
	this->DrawGotiYellow(this->players[1].p_tokens[j].t_pos.xcoor+inc, this->players[1].p_tokens[j].t_pos.ycoor+inc);

	for(int j=0 ; j<this->players[0].NoTokens ; j++)
	this->DrawGotiGreen(this->players[2].p_tokens[j].t_pos.xcoor+inc, this->players[2].p_tokens[j].t_pos.ycoor+inc);

	for(int j=0 ; j<this->players[0].NoTokens ; j++)
	this->DrawGotiRed(this->players[3].p_tokens[j].t_pos.xcoor+inc, this->players[3].p_tokens[j].t_pos.ycoor+inc);

}
void Game:: SetInitialGotis(Board& b)
{
for(int i=0; i<4; i++)
{
	this->players[0].p_tokens[i].t_pos.copyCoordinates(b.bs.blueyard[i]);
}
for(int i=0; i<4; i++)
{
	this->players[1].p_tokens[i].t_pos.copyCoordinates(b.bs.yellowyard[i]);
}
for(int i=0; i<4; i++)
{
	this->players[2].p_tokens[i].t_pos.copyCoordinates(b.bs.greenyard[i]);
}
for(int i=0; i<4; i++)
{
	this->players[3].p_tokens[i].t_pos.copyCoordinates(b.bs.redyard[i]);
}




for(int j=0 ; j<this->players[0].NoTokens ; j++)
//this->DrawGotiBlue(this->players[0].Goti[j].xcoor+inc, this->players[0].Goti[j].ycoor+inc);
this->DrawGotiBlue(this->players[0].p_tokens[j].t_pos.xcoor+inc, this->players[0].p_tokens[j].t_pos.ycoor+inc);

for(int j=0 ; j<this->players[0].NoTokens ; j++)
this->DrawGotiYellow(this->players[1].p_tokens[j].t_pos.xcoor+inc, this->players[1].p_tokens[j].t_pos.ycoor+inc);

for(int j=0 ; j<this->players[0].NoTokens ; j++)
this->DrawGotiGreen(this->players[2].p_tokens[j].t_pos.xcoor+inc, this->players[2].p_tokens[j].t_pos.ycoor+inc);

for(int j=0 ; j<this->players[0].NoTokens ; j++)
this->DrawGotiRed(this->players[3].p_tokens[j].t_pos.xcoor+inc, this->players[3].p_tokens[j].t_pos.ycoor+inc);


}


void Game:: DrawGotiYellow(int x, int y) {

	////cout<<"x: "<<x<<endl;
	////cout<<"y: "<<y<<endl;
		int size= this->players[0].size;
		static int ghostMouth=2;
		if(ghostMouth==600)
			{
			ghostMouth=2;
			}

		DrawRectangle(x , y , size, size, colors[ORANGE_RED]);
		DrawCircle(x + 15, y + 15,  8, colors[WHITE]);
		DrawRectangle(x + 5, y + 5, 20, 10,	colors[WHITE]); //height=30 and width=15


		//eyes
		DrawCircle(x + 10, y+15 , 2.0, colors[BLACK]);
		DrawCircle(x + 20, y +15, 2.0, colors[BLACK]);
		//smile
		if (ghostMouth%20==0)
		{
			DrawRoundRect(x + 5, y + 8 ,18, 2, colors[BLACK], 2.0);

		}
		else if(ghostMouth%2 == 0)
		{
			//DrawRoundRect(x + 5, y + 5 , 10, 2, colors[WHITE], 10.0);
			//DrawRoundRect(x + 5, y + 5 , 10, 2, colors[BLACK], 2.0);

		}
		ghostMouth+=2;
		////cout<<"ghost mouth: "<<ghostMouth<<endl;


	}
	void Game:: DrawGotiBlue(int x, int y) {
		int size= this->players[0].size;

		////cout<<"x: "<<x<<endl;
		////cout<<"y: "<<y<<endl;
		static int ghostMouth=2;
				if(ghostMouth==600)
					{
					ghostMouth=2;
					}
		DrawRectangle(x , y , size, size, colors[DEEP_PINK]);
		DrawRoundRect(x + 10 , y , 10, 10, colors[BLACK], 6.0); //BODY
		DrawRectangle(x + 5 , y + 5, 20, 20, colors[LIGHT_CYAN]); //rectangle HEAD

		//DrawRoundRect(x  +5, y + 5, 10, 10, colors[LIGHT_CYAN], 9.0); //ROUNDED LOWER FACE
		//EYES
		//DrawTriangle(x + 5, y + 15, x - 10, y + 15, x, y + 15, colors[BLACK]);
	//	DrawTriangle(x + 10, y + 15, x + 8 + 5, y + 15, x + 8 - 4, y + 15,colors[BLACK]);

	    DrawCircle(x + 10, y+15 , 2.0, colors[BLACK]);
	    		DrawCircle(x + 20, y +15, 2.0, colors[BLACK]);
		//TEETH
		if (ghostMouth%20==0) {
			//DrawRectangle(x - 10, y - 5, 20, 5, colors[BLACK]);
		//	DrawTriangle(x - 10 + 2, y - 15, x - 10, y - 5, x - 10 + 4, y - 5,
				//	colors[BLACK]);
			//DrawTriangle(x + 5 + 2, y - 15, x + 5, y - 5, x + 5 + 4, y - 5,
					//colors[BLACK]);

		}
		else if(ghostMouth%2 == 0)
		{
			//int x1 = x - 2;
			//DrawRectangle(x1 - 10, y - 5, 20, 5, colors[BLACK]);
			//DrawTriangle(x1 - 10 + 2, y - 15, x1 - 10, y - 5, x1 - 10 + 4, y - 5,
				//	colors[BLACK]);
			//DrawTriangle(x1 + 5 + 2, y - 15, x1 + 5, y - 5, x1 + 5 + 4, y - 5,
				//	colors[BLACK]);

		}
		ghostMouth+=2;
	}
	void Game:: DrawGotiGreen(int x, int y) {
		int size= this->players[0].size;

		static int ghostMouth=2;
				if(ghostMouth==600)
					{
					ghostMouth=2;
					}
		DrawRectangle(x , y , size, size, colors[LIGHT_CORAL]);
		DrawRectangle(x + 5, y + 5, 20, 20, colors[GREEN]);	    //rectangle HEAD
		DrawRectangle(x + 5, y + 20, 20, 5, colors[BLACK]);	          //hair
		//DrawCircle(x, y - 4, size / 4, colors[GREEN]);	            //lower FACE
		//DrawRectangle(x - 10, y - size / 2 + 3, 20, 15, colors[GREEN]);	      //NECK

		//EYEBAGS
		DrawCircle(x + 10, y + 15 , 3, colors[GRAY]);
		DrawCircle(x + 18, y + 15 , 3, colors[GRAY]);
		//EYES
		DrawCircle(x + 10, y + 16 , 3, colors[BLACK]);
		DrawCircle(x + 18, y + 16 , 3,colors[BLACK]);
		//MOUTH
		if (ghostMouth%20==0) {
			//DrawRectangle(x - 10, y - 10, 20, 8, colors[BLACK]);
			//DrawRectangle(x - 10, y - 10, 20, 2, colors[WHITE]);
			//DrawRectangle(x - 10, y - 10 + 6, 20, 2, colors[WHITE]);
		} else if(ghostMouth%2 == 0){
			//DrawCircle(x, y - 5, 5, colors[BLACK]);

		}
		ghostMouth+=2;

	}
	void Game:: DrawGotiRed(int x, int y) {
		int size= this->players[0].size;
		static int ghostMouth=2;
				if(ghostMouth==600)
					{
					ghostMouth=2;
					}
				x=x+size/2;
				y=y+size/2;
		DrawRectangle(x - size / 2, y - size / 2, size, size, colors[RED]);
		DrawCircle(x, y + size / 6, size / 4, colors[WHITE]);	            //head
		DrawRectangle(x - size / 4, y - size / 6, size / 2, size / 4,
				colors[WHITE]);	            //upper jaw
		DrawRectangle(x - size / 6, y - size / 3, size / 3, size / 3,
				colors[WHITE]);	            //lower jaw

		//teeth
		DrawRectangle(x - size / 4 + 4, y - size / 6, size / 12, size / 12,
				colors[BLACK]);
		DrawRectangle(x - size / 4 + 4 + 2 * 4, y - size / 6, size / 12, size / 12,
				colors[BLACK]);
		DrawRectangle(x - size / 4 + 4 + 4 * 4, y - size / 6, size / 12, size / 12,
				colors[BLACK]);

		DrawRectangle(x - size / 6 + 4, y - size / 3 + 5, size / 12, size / 12,
				colors[BLACK]);
		DrawRectangle(x - size / 6 + 4 + 2 * 4, y - size / 3 + 5, size / 12,
				size / 12, colors[BLACK]);
		//DrawRectangle(x-size/4+5, y-size/6 ,size/12, size/12, colors[BLACK]);
		//EYEs
		if (ghostMouth%30==0) {
			DrawCircle(x - size / 12, y + size / 4 - 4, 2, colors[BLACK]);
			DrawCircle(x + size / 12, y + size / 4 - 4, 2, colors[BLACK]);
		} else if(ghostMouth%2 == 0){
			DrawCircle(x - size / 3, y - size / 3, 2, colors[BLACK]);
			DrawCircle(x + size / 3, y - size / 3, 2, colors[BLACK]);

		}
		ghostMouth+=2;
		//NOSTRILS
		DrawCircle(x - 2, y + 2, 2, colors[BLACK]);
		DrawCircle(x + 2, y + 2, 2, colors[BLACK]);
		//LINE BETWEEN TEETH
		DrawRectangle(x - size / 6, y - 12, size / 3, 4, colors[BLACK]);

	}
	void Game:: SelectionGoti(int x, int y)
	{
		float * c=colors[BLACK];
		int size= this->players[0].size+10;
		DrawRectangle(x , y , size , 5, c);
		DrawRectangle(x , y , 5 , size, c);
		DrawRectangle(x , y + 35 , size , 5, c);
		DrawRectangle(x + 35 , y ,  5,size, c);
//		glutTimerFunc(700.0, Timer, 0);
//		Timer(5);
		for(int i=0; i<4;i++)
		{
			for(int j=0; j<4; j++)
			{
				if(this->players[i].p_tokens[j].selected == true)
				{
					this->players[i].p_tokens[j].selected = false;
				}
			}
		}

	}
void Game::CheckConditionsP2(int x,int y,int state,Board& b,PlayersPathways &pp)
{

	int pl=1;
	int s=this->players[pl].size;
	bool tokenFound=false;
	int xc=0;
	int yc=0;
	bool dontAssign=false;
	int goti=0;//saving the index of the goti
	int DiceNumber=this->players[pl].DiceTime;//tracking which dice are we on
	int dicevalue=this->players[pl].Roll.D[DiceNumber];//finding the dicevalue at that turn of the dice
	int count=0;

		 for(int i=0 ; i<this->players[pl].NoTokens && tokenFound==false ; i++)
		 		     {
		 		    	 xc=this->players[pl].p_tokens[i].t_pos.xcoor;//the current coordinates of the gotis
		 		    	 yc=this->players[pl].p_tokens[i].t_pos.ycoor;//the current coordinates of the gotis

		 		    	if(x>xc && x<xc+s )
		 		    	{
		 		    		 if(y>yc && y<yc+s)
		 		    		 {
		 		    			 goti=i;
		 		    			tokenFound=true;

		 		    		 }
		 		    	}
		 		     }

		 	if(tokenFound)//incae the token is found then do other stuff , otherwise ignore
		 	{
		 		     cout<<"goti: "<<goti<<endl;
		 		      cout<<"token found"<<endl;
		 		      //checking if all tokens are in home yard

		 		     for(int j=0 ; j<this->players[pl].NoTokens ; j++)
		 		         {
		 		         if(this->players[pl].p_tokens[j].t_pos.xcoor==b.bs.yellowyard[j].xcoor)
		 		          	if(this->players[pl].p_tokens[j].t_pos.ycoor==b.bs.yellowyard[j].ycoor)
		 		          	{
		 		     	  count++;
		 		            cout<<"the count: "<<count<<endl;
		 		          	}

		 		     	}
		 		     	if(count==4 && dicevalue<6)//all gotis in the home yard
		 		     	{
		 		                cout<<"all in home yard"<<endl;
		 		     		   DiceNumber=3;
		 		     		   this->players[pl].DiceTime=0;
		 		     		   this->players[pl].Roll.D[0]=0;
		 		     		   this->players[pl].PlayerWindow=false;
		 		     		  // this->DiceRewind=true;
		 		     		    dontAssign=true;
		 		     	 }
		 		     else//this else will have all assugnments
		 		     {


		 		//checking if the token is in the home yard;
		 		     bool TokenInHomeYard=false;
		 		   for(int i=0 ; i<this->players[pl].NoTokens ; i++)
		 		   {
		 			   if(xc==b.bs.yellowyard[i].xcoor && yc==b.bs.yellowyard[i].ycoor)
		 				   TokenInHomeYard=true;

		 		   }
		 		  if(TokenInHomeYard)
		 		  {
		                if(dicevalue==6)
		                {
		             	   cout<<"the dice value is 6"<<endl;
		             	   xc=pp.yellow_player_path[1].xcoor;
		             	   yc=pp.yellow_player_path[1].ycoor;
		             	   DiceNumber++;
		                }

		               cout<<"what is the issue"<<endl;
		 		  }
		 		  else//dice is not in the home yard
		 		  {

		              bool refound=false;
					  for(int i=0 ; i<58 && refound==false ; i++)
					  {
						  if(xc==pp.yellow_player_path[i].xcoor && yc==pp.yellow_player_path[i].ycoor)
						  {
							 if(i+dicevalue<57 && i+dicevalue>51)//stuck in the home path
							 {
								 if(this->players[pl].hitrate>0)
								 {
									 xc=pp.yellow_player_path[i+dicevalue].xcoor;
									 yc=pp.yellow_player_path[i+dicevalue].ycoor;
									 DiceNumber++;
									 refound=true;
								 }
								 else
								 {
									 int remain=i+dicevalue-51;
									 remain--;
									 xc=pp.yellow_player_path[remain].xcoor;
								     yc=pp.yellow_player_path[remain].ycoor;
									 DiceNumber++;
									 refound=true;

								 }
							 }
							 else if(i+dicevalue==57)
							 {
								 xc=-300;
								 yc=-300;
					             DiceNumber++;
								 refound=true;
								 this->players[pl].p_tokens[goti].reached_home=true;
							 }
							 else  if(i+dicevalue>57)
							 {
								 refound=true;
							 }
							 else
							 {
								 xc=pp.yellow_player_path[i+dicevalue].xcoor;
								 yc=pp.yellow_player_path[i+dicevalue].ycoor;
								 DiceNumber++;
								 refound=true;
							 }

						  }
					  }


		 		  }
		 			cout<<"THE DICENUMBER: "<<DiceNumber<<endl;
		 		  	  	  	  	  	if(!dontAssign)
									{

									cout<<"none in home yard"<<endl;
		  							this->players[pl].p_tokens[goti].t_pos.xcoor=xc;//the current coordinates of the gotis
		    						this->players[pl].p_tokens[goti].t_pos.ycoor=yc;//the current coordinates of the gotis
		    						int previousDice=DiceNumber;
		    						previousDice--;
		    						this->players[pl].Roll.D[previousDice]=0;
		    						this->players[pl].DiceTime=DiceNumber;

                                   }
		 	     }
		 		     	            if(this->players[pl].Roll.D[0]==0 && this->players[pl].Roll.D[1]==0 &&this->players[pl].Roll.D[2]==0)
		 		                   {
		 	                        this->players[pl].PlayerWindow=false;
		 		     			 	this->players[pl].DiceTime=0;
		 		     			 	//this->DiceRewind=true;
		 		     			 	}

            }


}
void Game:: CheckConditionsP3(int x,int y,int state,Board& b,PlayersPathways &pp)
{
	int pl=2;
		int s=this->players[pl].size;
		bool tokenFound=false;
		int xc=0;
		int yc=0;
		bool dontAssign=false;
		int goti=0;//saving the index of the goti
		int DiceNumber=this->players[pl].DiceTime;//tracking which dice are we on
		int dicevalue=this->players[pl].Roll.D[DiceNumber];//finding the dicevalue at that turn of the dice
		int count=0;

			 for(int i=0 ; i<this->players[pl].NoTokens && tokenFound==false ; i++)
			 		     {
			 		    	 xc=this->players[pl].p_tokens[i].t_pos.xcoor;//the current coordinates of the gotis
			 		    	 yc=this->players[pl].p_tokens[i].t_pos.ycoor;//the current coordinates of the gotis

			 		    	if(x>xc && x<xc+s )
			 		    	{
			 		    		 if(y>yc && y<yc+s)
			 		    		 {
			 		    			 goti=i;
			 		    			tokenFound=true;

			 		    		 }
			 		    	}
			 		     }

			 	if(tokenFound)//incae the token is found then do other stuff , otherwise ignore
			 	{
			 		     cout<<"goti: "<<goti<<endl;
			 		      cout<<"token found"<<endl;
			 		      //checking if all tokens are in home yard

			 		     for(int j=0 ; j<this->players[pl].NoTokens ; j++)
			 		         {
			 		         if(this->players[pl].p_tokens[j].t_pos.xcoor==b.bs.greenyard[j].xcoor)
			 		          	if(this->players[pl].p_tokens[j].t_pos.ycoor==b.bs.greenyard[j].ycoor)
			 		          	{
			 		     	  count++;
			 		            cout<<"the count: "<<count<<endl;
			 		          	}

			 		     	}
			 		     	if(count==4 && dicevalue<6)//all gotis in the home yard
			 		     	{
			 		                cout<<"all in home yard"<<endl;
			 		     		   DiceNumber=3;
			 		     		   this->players[pl].DiceTime=0;
			 		     		   this->players[pl].Roll.D[0]=0;
			 		     		  this->players[pl].PlayerWindow=false;
			 		     		  // this->DiceRewind=true;
			 		     		    dontAssign=true;
			 		     	 }
			 		     else//this else will have all assugnments
			 		     {


			 		//checking if the token is in the home yard;
			 		     bool TokenInHomeYard=false;
			 		   for(int i=0 ; i<this->players[pl].NoTokens ; i++)
			 		   {
			 			   if(xc==b.bs.greenyard[i].xcoor && yc==b.bs.greenyard[i].ycoor)
			 				   TokenInHomeYard=true;

			 		   }
			 		  if(TokenInHomeYard)
			 		  {
			                if(dicevalue==6)
			                {
			             	   cout<<"the dice value is 6"<<endl;
			             	   xc=pp.green_player_path[1].xcoor;
			             	   yc=pp.green_player_path[1].ycoor;
			             	   DiceNumber++;
			                }

			               cout<<"what is the issue"<<endl;
			 		  }
			 		  else//dice is not in the home yard
			 		  {

			              bool refound=false;
						  for(int i=0 ; i<58 && refound==false ; i++)
						  {
							  if(xc==pp.green_player_path[i].xcoor && yc==pp.green_player_path[i].ycoor)
							  {
								 if(i+dicevalue<57 && i+dicevalue>51)//stuck in the home path
								 {
									 if(this->players[pl].hitrate>0)
									 {
										 xc=pp.green_player_path[i+dicevalue].xcoor;
										 yc=pp.green_player_path[i+dicevalue].ycoor;
										 DiceNumber++;
										 refound=true;
									 }
									 else
									 {
										 int remain=i+dicevalue-51;
										 remain--;
										 xc=pp.green_player_path[remain].xcoor;
									     yc=pp.green_player_path[remain].ycoor;
										 DiceNumber++;
										 refound=true;

									 }
								 }
								 else if(i+dicevalue==57)
								 {
									 xc=-300;
									 yc=-300;
						             DiceNumber++;
									 refound=true;
									 this->players[pl].p_tokens[goti].reached_home=true;
								 }
								 else  if(i+dicevalue>57)
								 {
									 refound=true;

								 }
								 else
								 {
									 xc=pp.green_player_path[i+dicevalue].xcoor;
									 yc=pp.green_player_path[i+dicevalue].ycoor;
									 DiceNumber++;
									 refound=true;
								 }

							  }
						  }


			 		  }
			 			cout<<"THE DICENUMBER: "<<DiceNumber<<endl;
			 		  	  	  	  	  	if(!dontAssign)
										{

										cout<<"none in home yard"<<endl;
			  							this->players[pl].p_tokens[goti].t_pos.xcoor=xc;//the current coordinates of the gotis
			    						this->players[pl].p_tokens[goti].t_pos.ycoor=yc;//the current coordinates of the gotis
			    						int previousDice=DiceNumber;
			    						previousDice--;
			    						this->players[pl].Roll.D[previousDice]=0;
			    						this->players[pl].DiceTime=DiceNumber;

	                                   }
			 	     }
			 		     	            if(this->players[pl].Roll.D[0]==0 && this->players[pl].Roll.D[1]==0 &&this->players[pl].Roll.D[2]==0)
			 		                   {
			 	                        this->players[pl].PlayerWindow=false;
			 		     			 	this->players[pl].DiceTime=0;
			 		     			 	//this->DiceRewind=true;
			 		     			 	}

	            }

}
void Game:: CheckConditionsP4(int x,int y,int state,Board& b,PlayersPathways &pp)
{
	int pl=3;
		int s=this->players[pl].size;
		bool tokenFound=false;
		int xc=0;
		int yc=0;
		bool dontAssign=false;
		int goti=0;//saving the index of the goti
		int DiceNumber=this->players[pl].DiceTime;//tracking which dice are we on
		int dicevalue=this->players[pl].Roll.D[DiceNumber];//finding the dicevalue at that turn of the dice
		int count=0;

			 for(int i=0 ; i<this->players[pl].NoTokens && tokenFound==false ; i++)
			 		     {
			 		    	 xc=this->players[pl].p_tokens[i].t_pos.xcoor;//the current coordinates of the gotis
			 		    	 yc=this->players[pl].p_tokens[i].t_pos.ycoor;//the current coordinates of the gotis

			 		    	if(x>xc && x<xc+s )
			 		    	{
			 		    		 if(y>yc && y<yc+s)
			 		    		 {
			 		    			 goti=i;
			 		    			tokenFound=true;

			 		    		 }
			 		    	}
			 		     }

			 	if(tokenFound)//incae the token is found then do other stuff , otherwise ignore
			 	{
			 		     cout<<"goti: "<<goti<<endl;
			 		      cout<<"token found"<<endl;
			 		      //checking if all tokens are in home yard

			 		     for(int j=0 ; j<this->players[pl].NoTokens ; j++)
			 		         {
			 		         if(this->players[pl].p_tokens[j].t_pos.xcoor==b.bs.redyard[j].xcoor)
			 		          	if(this->players[pl].p_tokens[j].t_pos.ycoor==b.bs.redyard[j].ycoor)
			 		          	{
			 		     	  count++;
			 		            cout<<"the count: "<<count<<endl;
			 		          	}

			 		     	}
			 		     	if(count==4 && dicevalue<6)//all gotis in the home yard
			 		     	{
			 		                cout<<"all in home yard"<<endl;
			 		     		   DiceNumber=3;
			 		     		   this->players[pl].DiceTime=0;
			 		     		   this->players[pl].Roll.D[0]=0;
			 		     		  this->players[pl].PlayerWindow=false;
			 		     		   this->DiceRewind=true;
			 		     		    dontAssign=true;
			 		     	 }
			 		     else//this else will have all assugnments
			 		     {


			 		//checking if the token is in the home yard;
			 		     bool TokenInHomeYard=false;
			 		   for(int i=0 ; i<this->players[pl].NoTokens ; i++)
			 		   {
			 			   if(xc==b.bs.redyard[i].xcoor && yc==b.bs.redyard[i].ycoor)
			 				   TokenInHomeYard=true;

			 		   }
			 		  if(TokenInHomeYard)
			 		  {
			                if(dicevalue==6)
			                {
			             	   cout<<"the dice value is 6"<<endl;
			             	   xc=pp.red_player_path[1].xcoor;
			             	   yc=pp.red_player_path[1].ycoor;
			             	   DiceNumber++;
			                }

			               cout<<"what is the issue"<<endl;
			 		  }
			 		  else//dice is not in the home yard
			 		  {

			              bool refound=false;
						  for(int i=0 ; i<58 && refound==false ; i++)
						  {
							  if(xc==pp.red_player_path[i].xcoor && yc==pp.red_player_path[i].ycoor)
							  {
								 if(i+dicevalue<57 && i+dicevalue>51)//stuck in the home path
								 {
									 if(this->players[pl].hitrate>0)
									 {
										 xc=pp.red_player_path[i+dicevalue].xcoor;
										 yc=pp.red_player_path[i+dicevalue].ycoor;
										 DiceNumber++;
										 refound=true;
									 }
									 else
									 {
										 int remain=i+dicevalue-51;
										 remain--;
										 xc=pp.red_player_path[remain].xcoor;
									     yc=pp.red_player_path[remain].ycoor;
										 DiceNumber++;
										 refound=true;

									 }
								 }
								 else if(i+dicevalue==57)
								 {
									 xc=-300;
									 yc=-300;
						             DiceNumber++;
									 refound=true;
									 this->players[pl].p_tokens[goti].reached_home=true;
								 }
								 else  if(i+dicevalue>57)
								 {
									 refound=true;
								 }
								 else
								 {
									 xc=pp.red_player_path[i+dicevalue].xcoor;
									 yc=pp.red_player_path[i+dicevalue].ycoor;
									 DiceNumber++;
									 refound=true;
								 }

							  }
						  }


			 		  }
			 			cout<<"THE DICENUMBER: "<<DiceNumber<<endl;
			 		  	  	  	  	  	if(!dontAssign)
										{

										cout<<"none in home yard"<<endl;
			  							this->players[pl].p_tokens[goti].t_pos.xcoor=xc;//the current coordinates of the gotis
			    						this->players[pl].p_tokens[goti].t_pos.ycoor=yc;//the current coordinates of the gotis
			    						int previousDice=DiceNumber;
			    						previousDice--;
			    						this->players[pl].Roll.D[previousDice]=0;
			    						this->players[pl].DiceTime=DiceNumber;

	                                   }
			 	     }
			 		     	            if(this->players[pl].Roll.D[0]==0 && this->players[pl].Roll.D[1]==0 &&this->players[pl].Roll.D[2]==0)
			 		                   {
			 	                        this->players[pl].PlayerWindow=false;
			 		     			 	this->players[pl].DiceTime=0;
			 		     			 	this->DiceRewind=true;
			 		     			 	}

	            }

}
