/*
 * Players.h
 *
 *  Created on: Jun 13, 2021
 *      Author: sillpill
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_
#include"util.h"
#include"Board.h"
#include"Coordinates.h"
#include"cmath"


/*struct Coordinates
{
int xcoor;
int ycoor;
int width;
int height;
float * colour;
int typeOfBox;
Coordinates()
{
xcoor=0;
ycoor=0;
width=0;
height=0;
colour=colors[LIGHT_CORAL];
typeOfBox=0;// type=5 shows a goti
}
void setCoordinates(int x, int y , int h,int w, float *c)
{
	xcoor=x;
	ycoor=y;
	height=h;
	width=w;
	colour=c;
	typeOfBox=5;
}
};
*/
struct Dice
{
int D[3];//4 times for each player where each player can have 3 wins
};
struct AllDices
{
Dice Dices[4];
};
struct Token
{
	Coordinates t_pos;
	bool reached_home;
	bool killed;
	bool selected;
	bool repositioned;
	Token()
	{
		reached_home =false;
		killed = false;
	    selected = false;
	    repositioned = false;
	}
};


struct Players
{
int PlayerID;//pthread id of the player
int hitrate;//how many hits the player made
bool PlayerWindow;//for when the player 1 has to move
int size;
int turns;
int NoTokens;
Token p_tokens[4];
int DiceTime;

//bool movementDone;
Dice Roll;
Players()
{
	for(int i=0 ; i<4 ; i++)
		p_tokens[i].t_pos.setCoordinates(0,0, colors[BLACK], 10, 10, 0);
	Dice DiceRolling[3];
	turns=0;
	PlayerID=0;
	hitrate=0;
	PlayerWindow=false;
    DiceTime=0;
    bool DiceRolled=false;
    size=30;
    NoTokens=4;

    DiceRolled=false;
 //   movementDone=false;
}
void displayPlayerDice(int X, int Y, int PlayerNum)
{
//	DrawRectangle()
	int tempx = X, tempy = Y;
//	void DrawRectangle(int sx, int sy, int width, int height, float *color);
/*	void DrawString(int x, int y, int width, int height, const string& str,
			float * color = NULL);*/

//	DrawRectangle(tempx, tempy, 150, 80, colors[BISQUE]);

	string player_label = "Player "+to_string(PlayerNum);

	DrawRectangle(tempx, tempy, 150, 80, colors[LIGHT_PINK]);
//	DrawString(tempx+25, tempy+20, 30, 30, "Player 1", colors[BLACK]);
	tempx+=20;
	tempy+=10;
	DrawString(tempx+20, tempy+40, player_label, colors[BLACK]);

	for(int i=0; i<3; i++)
	{
		//cout<<endl<<"Player Dice Number = "<<this->Roll.D[i]<<endl<<endl;
//		void DrawRoundRect(float x, float y, float width, float height,
//		float* color = 0, float radius = 0.0);
		DrawRoundRect((float)tempx, (float)tempy, 30, 30, colors[WHITE], 3);
		if(this->Roll.D[i] == 1)
		{
//			void DrawCircle(float sx, float sy, float radius, float*color);
			DrawCircle(tempx+15, tempy+15, 2, colors[BLACK]);
		}
		else if(this->Roll.D[i] == 2)
		{
			DrawCircle(tempx+10, tempy+15, 2, colors[BLACK]);
			DrawCircle(tempx+20, tempy+15, 2, colors[BLACK]);
		}
		else if(this->Roll.D[i] == 3)
		{
			DrawCircle(tempx+7, tempy+15, 2, colors[BLACK]);
			DrawCircle(tempx+14, tempy+15, 2, colors[BLACK]);
			DrawCircle(tempx+21, tempy+15, 2, colors[BLACK]);
		}
		else if(this->Roll.D[i] == 4)
		{
			DrawCircle(tempx+10, tempy+10, 2, colors[BLACK]);
			DrawCircle(tempx+20, tempy+10, 2, colors[BLACK]);
			DrawCircle(tempx+10, tempy+20, 2, colors[BLACK]);
			DrawCircle(tempx+20, tempy+20, 2, colors[BLACK]);
		}
		else if(this->Roll.D[i] == 5)
		{
			DrawCircle(tempx+10, tempy+10, 2, colors[BLACK]);
			DrawCircle(tempx+20, tempy+10, 2, colors[BLACK]);
			DrawCircle(tempx+15, tempy+15, 2, colors[BLACK]);
			DrawCircle(tempx+10, tempy+20, 2, colors[BLACK]);
			DrawCircle(tempx+20, tempy+20, 2, colors[BLACK]);
		}
		else if(this->Roll.D[i] == 6)
		{
			DrawCircle(tempx+7, tempy+10, 2, colors[BLACK]);
			DrawCircle(tempx+14, tempy+10, 2, colors[BLACK]);
			DrawCircle(tempx+21, tempy+10, 2, colors[BLACK]);
			DrawCircle(tempx+7, tempy+20, 2, colors[BLACK]);
			DrawCircle(tempx+14, tempy+20, 2, colors[BLACK]);
			DrawCircle(tempx+21, tempy+20, 2, colors[BLACK]);
		}


		tempx+=40;
	}

}





};



struct PlayersPathways
{
//size of each player's pathway is 58, start from index 1,  if hit rate ==0, move from 57th to 0tjh index and wrap agin the path.
	Coordinates* blue_player_path;
	Coordinates* yellow_player_path;
	Coordinates* green_player_path;
	Coordinates* red_player_path;
//intialize using board section members
	PlayersPathways()
	{
		blue_player_path = new Coordinates[58];
		yellow_player_path = new Coordinates[58];
		green_player_path = new Coordinates[58];
		red_player_path = new Coordinates[58];
	}
	void setPathwayCoordinates(BoardSections& bs)
	{
		//blue's path
		int i=0, j =0;
		for(i=0; i<6; i++)
		{
			blue_player_path[i].copyCoordinates(bs.bluepath[i]);
		}
		j=17;
		for(i=6; i<12; i++)
		{
			blue_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j--;
		}
		blue_player_path[12].copyCoordinates(bs.yellowpath[6]);
		j=0;
		for(i=13; i<19; i++)
		{
			blue_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j++;
		}
		j=17;
		for(i=19; i<25; i++)
		{
			blue_player_path[i].copyCoordinates(bs.greenpath[j]);
			j--;
		}
		blue_player_path[25].copyCoordinates(bs.greenpath[6]);
		j=0;
		for(i=26; i<32; i++)
		{
			blue_player_path[i].copyCoordinates(bs.greenpath[j]);
			j++;
		}
		j=17;
		for(i=32;i<38; i++)
		{
			blue_player_path[i].copyCoordinates(bs.redpath[j]);
			j--;
		}
		blue_player_path[38].copyCoordinates(bs.redpath[6]);
		j=0;
		for(i=39; i<45;i++)
		{
			blue_player_path[i].copyCoordinates(bs.redpath[j]);
			j++;
		}
		j=17;
		for(i=45; i<51; i++)
		{
			blue_player_path[i].copyCoordinates(bs.bluepath[j]);
			j--;
		}
		//Blue going home!!
		j=6;
		for(i=51; i<57; i++)
		{
			blue_player_path[i].copyCoordinates(bs.bluepath[j]);
			j++;
		}
		blue_player_path[57].copyCoordinates(bs.bluehome);







		//set Yellow Player's Pathway
		i=0, j =0;
		for(i=0; i<6; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.yellowpath[i]);
		}
		j=17;
		for(i=6; i<12; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.greenpath[j]);
			j--;
		}
		yellow_player_path[12].copyCoordinates(bs.greenpath[6]);
		j=0;
		for(i=13; i<19; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.greenpath[j]);
			j++;
		}
		j=17;
		for(i=19; i<25; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.redpath[j]);
			j--;
		}
		yellow_player_path[25].copyCoordinates(bs.redpath[6]);
		j=0;
		for(i=26; i<32; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.redpath[j]);
			j++;
		}
		j=17;
		for(i=32;i<38; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.bluepath[j]);
			j--;
		}
		yellow_player_path[38].copyCoordinates(bs.bluepath[6]);
		j=0;
		for(i=39; i<45;i++)
		{
			yellow_player_path[i].copyCoordinates(bs.bluepath[j]);
			j++;
		}
		j=17;
		for(i=45; i<51; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j--;
		}
		//going towards home!!
		j=6;
		for(i=51; i<57; i++)
		{
			yellow_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j++;
		}
		yellow_player_path[57].copyCoordinates(bs.yellowhome);





		//set Green Player's Pathway
		i=0, j =0;
		for(i=0; i<6; i++)
		{
			green_player_path[i].copyCoordinates(bs.greenpath[i]);
		}
		j=17;
		for(i=6; i<12; i++)
		{
			green_player_path[i].copyCoordinates(bs.redpath[j]);
			j--;
		}
		green_player_path[12].copyCoordinates(bs.redpath[6]);
		j=0;
		for(i=13; i<19; i++)
		{
			green_player_path[i].copyCoordinates(bs.redpath[j]);
			j++;
		}
		j=17;
		for(i=19; i<25; i++)
		{
			green_player_path[i].copyCoordinates(bs.bluepath[j]);
			j--;
		}
		green_player_path[25].copyCoordinates(bs.bluepath[6]);
		j=0;
		for(i=26; i<32; i++)
		{
			green_player_path[i].copyCoordinates(bs.bluepath[j]);
			j++;
		}
		j=17;
		for(i=32;i<38; i++)
		{
			green_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j--;
		}
		green_player_path[38].copyCoordinates(bs.yellowpath[6]);
		j=0;
		for(i=39; i<45;i++)
		{
			green_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j++;
		}
		j=17;
		for(i=45; i<51; i++)
		{
			green_player_path[i].copyCoordinates(bs.greenpath[j]);
			j--;
		}
		//going towards home!!
		j=6;
		for(i=51; i<57; i++)
		{
			green_player_path[i].copyCoordinates(bs.greenpath[j]);
			j++;
		}
		green_player_path[57].copyCoordinates(bs.greenhome);





		//set Red Player's Pathway
		i=0, j =0;
		for(i=0; i<6; i++)
		{
			red_player_path[i].copyCoordinates(bs.redpath[i]);
		}
		j=17;
		for(i=6; i<12; i++)
		{
			red_player_path[i].copyCoordinates(bs.bluepath[j]);
			j--;
		}
		red_player_path[12].copyCoordinates(bs.bluepath[6]);
		j=0;
		for(i=13; i<19; i++)
		{
			red_player_path[i].copyCoordinates(bs.bluepath[j]);
			j++;
		}
		j=17;
		for(i=19; i<25; i++)
		{
			red_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j--;
		}
		red_player_path[25].copyCoordinates(bs.yellowpath[6]);
		j=0;
		for(i=26; i<32; i++)
		{
			red_player_path[i].copyCoordinates(bs.yellowpath[j]);
			j++;
		}
		j=17;
		for(i=32;i<38; i++)
		{
			red_player_path[i].copyCoordinates(bs.greenpath[j]);
			j--;
		}
		red_player_path[38].copyCoordinates(bs.greenpath[6]);
		j=0;
		for(i=39; i<45;i++)
		{
			red_player_path[i].copyCoordinates(bs.greenpath[j]);
			j++;
		}
		j=17;
		for(i=45; i<51; i++)
		{
			red_player_path[i].copyCoordinates(bs.redpath[j]);
			j--;
		}
		//going towards home!!
		j=6;
		for(i=51; i<57; i++)
		{
			red_player_path[i].copyCoordinates(bs.redpath[j]);
			j++;
		}
		red_player_path[57].copyCoordinates(bs.redhome);


	}

	void show_Player_Pathways()
	{

		cout<<"Showing blue Player's Pathway:- "<<endl;
		cout<<" { ";
		for(int i=0; i<58; i++)
		{
			cout<<'('<<blue_player_path[i].xcoor<<", "<<blue_player_path[i].ycoor<<')';
		}
		cout<<"}"<<endl<<endl;

		cout<<"Showing yellow Player's Pathway:- "<<endl;
		cout<<" { ";
		for(int i=0; i<58; i++)
		{
			cout<<'('<<yellow_player_path[i].xcoor<<", "<<yellow_player_path[i].ycoor<<')';
		}
		cout<<"}"<<endl<<endl;
		cout<<"Showing green Player's Pathway:- "<<endl;
		cout<<" { ";
		for(int i=0; i<58; i++)
		{
			cout<<'('<<green_player_path[i].xcoor<<", "<<green_player_path[i].ycoor<<')';
		}
		cout<<"}"<<endl<<endl;
		cout<<"Showing red Player's Pathway:- "<<endl;
		cout<<" { ";
		for(int i=0; i<58; i++)
		{
			cout<<'('<<red_player_path[i].xcoor<<", "<<red_player_path[i].ycoor<<')';
		}
		cout<<"}"<<endl<<endl;

	}
};
struct Game
{
Players players[4];
bool DiceRewind;
//Dice roll[4];
//Board b;
//PlayersPathways playerspaths;
//int NoOfTokens;
Game()
{
DiceRewind=true;
}
void  DrawGotiYellow(int x, int y);
void  DrawGotiBlue(int x, int y);
void  DrawGotiGreen(int x, int y);
void  DrawGotiRed(int x, int y);
void  SelectionGoti(int x, int y);
void SetInitialGotis(Board& b);
void MoveGoti(int x,int y,int state,Board& b,PlayersPathways &pp);
void setGotiPosition();
void CheckConditionsP1(int x,int y,int state,Board& b,PlayersPathways &pp);
void CheckConditionsP2(int x,int y,int state,Board& b,PlayersPathways &pp);
void CheckConditionsP3(int x,int y,int state,Board& b,PlayersPathways &pp);
void CheckConditionsP4(int x,int y,int state,Board& b,PlayersPathways &pp);
};




#endif /* PLAYERS_H_ */
