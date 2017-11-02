#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

int score=0;
int nscore=0;

void gline()
{
  line(0,getmaxy()-100,getmaxx(),getmaxy()-100);  //groundline
}

void triangle(int x=0) //spikes
{
	line(20+x,getmaxy()-100,25+x,getmaxy()-120);
	line(25+x,getmaxy()-120,30+x,getmaxy()-100);
}

int main()
{

	int gd = DETECT, gm;
	int i, x, y, flag=0;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	//inital position of ball
	x = getmaxx()/2;
	y = 30;

	char ch;
	outtextxy(200,100,"Press any key to start the game");
	outtextxy(200,120,"Press 'A' for left and 'Z' for right");
	delay(100);
	while (1)
      {
		char buff[80];
		outtextxy(200,400,"Press 'Q' to quit the game");
		ch=getch();
		if (ch=='q') //game over screen
		{
			setcolor(RED);
			settextstyle(8,0,1);
			outtextxy(250,225,"GAMEOVER");
			memset(buff,0,80);
			sprintf(buff,"Your final score is : %d", score);
			outtextxy(205,250,buff);
			delay(2000);
			return 0;
		}
		if(y >= getmaxy()-115 || y <= 30) //rebound from ground and top screen ball invert flag
			flag = !flag;

		setcolor(RED);
		gline();

		triangle();
		triangle(80);
		triangle(160);
		triangle(240);
		triangle(320);
		triangle(400);
		triangle(480);

		setfillstyle(SOLID_FILL, RED);
		circle(x, y, 15);
		floodfill(x, y, RED);



		if(flag) //ball move downwards
		{
			y = y + 5;
			if (ch>110)
				x = x + 2;	//right dir
			else
				x = x - 2;	//left dir


		}
		else //ball moves upwards
	       {
			y = y - 5;
			if (ch>110)
				x = x + 2; //right dir
			else
				x = x - 2;	//left dir
		}

		delay(50);

 /* clears screen */
		cleardevice();

		if(y >= getmaxy()-115 && y <= getmaxy()) //ball between ground line and screen max
		{
			if(x>=20-15 && x<=30+15) //ball lies in region of traingle 20 & 30
			{
				nscore--;
				score-=2;
			}
			else if(x>=100-15 && x<=110+15) //ball lies in region of traingle 20 & 30

			{ 
				nscore--;
				score-=2;
			}
			else if(x>=180-15 && x<=190+15) //ball lies in region of traingle 180 & 190
			{ 
				nscore--;
				score-=2;
			}
			else if(x>=260-15 && x<=270+15)	//ball lies in region of traingle 260 & 270
			{ 
				nscore--;
				score-=2;
			}
			else if(x>=340-15 && x<=350+15)	//ball lies in region of traingle 340 & 350
			{
				nscore--; 
				score-=2;
			}
			else if(x>=420-15 && x<=430+15)	//ball lies in region of traingle 420 & 430
			{ 
				nscore--;
				score-=2;
			}
			else if(x>=500-15 && x<=510+15)	//ball lies in region of traingle 500 & 510
			{ 
				nscore--;
				score-=2;
			}
			score=score++;
		}
		gotoxy(60,20);
		cout<<"Score: "<<score<<endl;
		cout<<"NScore: "<<nscore;
	}

	getch();
	closegraph();
	return 0;
}