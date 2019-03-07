#include<graphics.h>
#include<string.h>
#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<time.h>
#include<dos.h>
#define printxy outtextxy
#define text settextstyle
#define fill setfillstyle
#define cd cleardevice()
union REGS i,o;
int x=0,y=0,b=0,flag=45;
class graphics
{
public:
	void graph()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"c:\\tc\\bgi");
	}
	void initmouse(int b,int x,int y)
	{
		i.x.ax=0;
		int86 (0x33,&i,&o);
		showmouseptr();
		movemouseptr(&x,&y);
		getmousepos(&b,&x,&y);
	}
	void showmouseptr()
	{
		i.x.ax=1;
		int86(0x33,&i,&o);
	}
	void hidemouseptr()
	{
		 i.x.ax=2;
		 int86(0x33,&i,&o);
	}
	void getmousepos(int *button,int *x,int *y)
	{
		i.x.ax=3;
		int86(0x33,&i,&o);
		*button=o.x.bx;
		*x=o.x.cx;
		*y=o.x.dx;
	}
	/* Move mouse ptr to x,y */
	void movemouseptr(int *x,int *y)
	{
		i.x.ax=4;
		int86(0x33,&i,&o);
		o.x.cx=*x;
		o.x.dx=*y;
	}
	void restrictmouseptr(int x1,int y1,int x2,int y2)
	{
		i.x.ax=7;
		i.x.cx=x1;
		i.x.dx=x2;
		int86(0x33,&i,&o);
		i.x.ax=8;
		i.x.cx=y1;
		i.x.dx=y2;
		int86(0x33,&i,&o);
	}
	void button(int a,int b,int c,int d,int e)
	{
		setcolor(e);
		bar(a,b,c,d);
		rectangle(a+1,b+1,c-1,d-1);
	}
	void print(char *s,int color,int font,int size,int x,int y)
	{
		text(font,0,size);
		setcolor(color);
		printxy(x,y,s);
	}
};
graphics g;
class school
{
public:
	void form()
	{
	closegraph();
	char name[100],a,pass[12],cq[12],id[10],add[100];

	clrscr();
	cout<<"Choose your School ID : ";
	for(int i=0;i<10;i++)
	{
		x:
		a=getch();
		if(isalnum(a)!=0)
		{
			id[i]=a;
			putch(a);
		}else if(a==8 && i!=0)
		{
			putch(a);
			cout<<" ";
			putch(a);
			i--;
			goto x;
		}else
		{
		goto x;
		}
	}
	id[i]='\0';
	cout<<"\n"<<id;
	c:
	cout<<"\n\nChoose your School password : ";
	for(i=0;i<12;i++)
	{
		xx:
		a=getch();
		if(isalnum(a)!=0)
		{
			pass[i]=a;
			putch('x');
		}else if(a==8 && i!=0)
		{
			putch(a);
			cout<<" ";
			putch(a);
			i--;
			goto xx;
		}else
		{
		goto xx;
		}
	}
	pass[12]='\0';
	cout<<"\n"<<pass;
	cout<<"\n\nConfirm Password : ";
	for(i=0;i<12;i++)
	{
		xxx:
		a=getch();
		if(isalnum(a)!=0)
		{
			cq[i]=a;
			putch('x');
		}else if(a==8 && i!=0)
		{
			putch(a);
			cout<<" ";
			putch(a);
			i--;
			goto xxx;
		}else
		{
		goto xxx;
		}
	}
	cout<<"\n"<<cq;
	if(strncmp(pass,cq,12)!=0)
	{
	cout<<"\nPassword Does'nt match..... Please try again..";
	sleep(2);
	gotoxy(20,2);
	cout<<"																																																																																	";
	gotoxy(1,2);
	goto c;
	}
	cout<<"\n\nEnter your School name : ";
	for(i=0;i<100;i++)
	{
		xxxx:
		a=getch();
		if(isalnum(a)!=0 || a==32)
		{
			name[i]=a;
			putch(a);
		}else if(a==13 && i>10)
		{
			break;
		}
		else if(a==8 && i!=0)
		{
			putch(a);
			cout<<" ";
			putch(a);
			i--;
			goto xxxx;
		}else
		{
		goto xxxx;
		}
	}
	name[i]='\0';
	cout<<"\n"<<name;
	cout<<"\n\nEnter your School Address : ";
	for(i=0;i<100;i++)
	{
		xxxxx:
		a=getch();
		if(isalnum(a)!=0 || a==32)
		{
			add[i]=a;
			putch(a);
		}else if(a==13 && i>10)
		{
			break;
		}
		else if(a==8 && i!=0)
		{
			putch(a);
			cout<<" ";
			putch(a);
			i--;
			goto xxxxx;
		}else
		{
		goto xxxxx;
		}
	}
	add[i]='\0';
		cout<<"\n"<<add;
		clrscr();
	cout<<"Please Confirm Details : \n"<<"\nSchool id : "<<id<<"\n\nSchool Password : "<<pass<<"\n\nSchool Name : "<<name<<"\n\nSchool Address : "<<add;
	cout<<"\n\n\n\n\n\n\n\t\tConfirm"<<"\t\t\tApply changes";
	gotoxy(18,12);
	printf("Use TAB key to navigate the cursor");
	_setcursortype(_NOCURSOR);
	int f=0;
	while(getch()!=13)
	{
		if(f==0)
		{
			gotoxy(14,16);
			printf("\xDB\xB2");
			gotoxy(38,16);
			printf("  ");
			f=1;
		}else if(f==1)
		{
			gotoxy(14,16);
			printf("  ");
			gotoxy(38,16);
			printf("\xDB\xB2");
			f=0;
		}
	}
	}
	void newschool()
	{
		cd;
		fixpage();
		setbkcolor(LIGHTBLUE);
		g.initmouse(b,x,y);
		cd;
		fixpage();
		setcolor(BLUE);
		fill(SOLID_FILL,LIGHTGRAY);
		g.button(20,60,619,340,MAGENTA);
		g.button(20,370,160,420,MAGENTA);
		g.button(479,370,619,420,MAGENTA);
		setcolor(RED);
		text(SMALL_FONT,0,8);
		printxy(35,65,"Rules & Regulations ");
		printxy(35,66,"Rules & Regulations ");
		printxy(52,380,"AGREE");
		printxy(495,380,"DISAGREE");
		line(35,98,305,98);
		line(35,100,305,100);
		text(SMALL_FONT,0,6);
		setcolor(BLUE);
		printxy(35,120,"-> School id should made in exactly 10 different alphabetic ");
		printxy(63,140,"letters or numerics.");
		printxy(63,160,"Ex. :- Vrushank12");
		printxy(35,190,"-> School password should created in exactly 12 different");
		printxy(63,210,"alphanumerics.");
		text(SMALL_FONT,0,8);
		setcolor(RED);
		int sa=0;
		while(!kbhit() || kbhit())
		{
			sa++;

			if(x>=20 && x<=160 && y>=370 && y<=420)
			{
				setcolor(sa);
				printxy(52,380,"AGREE");
			}else if(x>=479 && x<=619 && y>=370 && y<=420)
			{
				setcolor(sa);
				printxy(495,380,"DISAGREE");
			}
			else
			{
				setcolor(RED);
				printxy(52,380,"AGREE");
				printxy(495,380,"DISAGREE");
			}
			g.getmousepos(&b,&x,&y);
			/////////////////////////////
			if(b==1)
			{
				if(x>=20 && x<=160 && y>=370 && y<=420) //click on agree
				{
					goto y;
				}else if(x>=479 && x<=619 && y>=370 && y<=420)
				{
					goto x;
				}
			}
		}
		x:
		g.hidemouseptr();
		start();
		y:
		form();
		getch();
	}
	void search()
	{
		g.graph();
		cd;
		setbkcolor(LIGHTGRAY);
		text(BOLD_FONT,0,7);
		setcolor(BLUE);
		int o=20;
		printxy(100+o,100,"S");
		setcolor(RED);
		printxy(160+o,100,"t");
		setcolor(BROWN);
		printxy(200+o,100,"u");
		setcolor(BLUE);
		printxy(250+o,100,"d");
		setcolor(GREEN);
		printxy(305+o,100,"e");
		setcolor(RED);
		printxy(358+o,100,"n");
		setcolor(BROWN);
		printxy(410+o,100,"t");
		text(SMALL_FONT,0,8);
		setcolor(RED);
		printxy(325,134,"S");
		setcolor(BROWN);
		printxy(340,134,"e");
		setcolor(BLUE);
		printxy(355,134,"a");
		setcolor(CYAN);
		printxy(370,134,"r");
		setcolor(BLUE);
		printxy(380,134,"c");
		setcolor(GREEN);
		printxy(395,134,"h");
		fill(5,RED);
		floodfill(193,154,RED);
		fill(8,BLUE);
		floodfill(137,148,BLUE);
		fill(8,BROWN);
		floodfill(254,177,BROWN);
		fill(10,BLUE);
		floodfill(310,167,BLUE);
		fill(6,GREEN);
		floodfill(358,168,GREEN);
		fill(8,RED);
		floodfill(382,170,RED);
		fill(11,BROWN);
		floodfill(443,161,BROWN);
	}
	void fixpage()
	{
		fill(SOLID_FILL,15);
		bar(1,1,638,30);
		bar(1,450,638,480);
		setcolor(RED);
		text(SMALL_FONT,0,8);
		printxy(200,1,"School Organizer");
		printxy(201,1,"School Organizer");
		printxy(125,450,"Program By : Vrushank Patel");
		printxy(126,450,"Program By : Vrushank Patel");
	}
	void startpage()
	{
		g.graph();
		fixpage();
		setbkcolor(LIGHTBLUE);
		fill(SOLID_FILL,8);
		bar(265,132,360,194);
		bar(265,260,360,320);
		setcolor(RED);
		rectangle(267,134,358,192);
		rectangle(267,264,358,318);
		line(362,160,370,160);
		line(264,160,256,160);
		line(362,290,370,290);
		line(264,290,256,290);
		line(256,160,256,290);
		line(370,160,370,290);
		rectangle(244,121,382,331);
		text(GOTHIC_FONT,0,4);
		g.initmouse(b,x,y);
		while(!kbhit() || kbhit())
		{
			x:
			if(x>=265 && x<=360 && y>=132 && y<=194)
			{
				setcolor(LIGHTGRAY);
				printxy(282,141,"Start");
			}else if(x>=265 && x<=360 && y>=260 && y<=320)
			{
				setcolor(LIGHTGRAY);
				printxy(284,267,"Exit");
			}
			else
			{
				setcolor(YELLOW);
				printxy(282,141,"Start");
				printxy(284,267,"Exit");
			}
			g.getmousepos(&b,&x,&y);
			if(b==1)
			{
				if(x>=265 && x<=360 && y>=132 && y<=194)
				{
					g.hidemouseptr();
					setcolor(LIGHTBLUE);
					bar(1,1,639,479);
					goto y;
				}else if(x>=265 && x<=360 && y>=260 && y<=320)
				{
					exit(0);
				}
			}
		}
		y:
		start();
	}
	void start()
	{
		cd;
		fixpage();
		setbkcolor(LIGHTBLUE);
		setcolor(LIGHTBLUE);
		fill(SOLID_FILL,LIGHTBLUE);
		bar(479,370,619,420);
		setcolor(RED);
		fill(SOLID_FILL,DARKGRAY);
		line(319.5,119.75,319.5,359.25);
		g.button(79.875,179.625,239.625,299.375,RED);
		g.button(399.379,179.625,559.125,299.375,RED);
		g.button(8.5,405.135,78.5,440,RED);
		g.print(" Back",YELLOW,SIMPLEX_FONT,2,17,406);
		g.print("Create",YELLOW,TRIPLEX_FONT,4,108,195);
		g.print("New",YELLOW,TRIPLEX_FONT,4,125,240);
		g.print("Open",YELLOW,TRIPLEX_FONT,4,442,190);
		g.print("Existing",YELLOW,TRIPLEX_FONT,4,415,235);
		g.initmouse(b,x,y);
		while(!kbhit() || kbhit())
		{
			x:
			if(x>=8 && x<=78 && y>=405 && y<=440)
			{
				g.print(" Back",LIGHTGRAY,SIMPLEX_FONT,2,17,406);
			}else if(x>=399 && x<=559 && y>=179 && y<=299)
			{
				g.print("Open",LIGHTGRAY,TRIPLEX_FONT,4,442,190);
				g.print("Existing",LIGHTGRAY,TRIPLEX_FONT,4,415,235);
			}else if(x>=79 && x<=239 && y>=179 && y<=299)
			{
				g.print("Create",LIGHTGRAY,TRIPLEX_FONT,4,108,195);
				g.print("New",LIGHTGRAY,TRIPLEX_FONT,4,125,240);

			}else
			{
				g.print(" Back",YELLOW,SIMPLEX_FONT,2,17,406);
				g.print("Open",YELLOW,TRIPLEX_FONT,4,442,190);
				g.print("Existing",YELLOW,TRIPLEX_FONT,4,415,235);
				g.print("Create",YELLOW,TRIPLEX_FONT,4,108,195);
				g.print("New",YELLOW,TRIPLEX_FONT,4,125,240);
			}
			g.getmousepos(&b,&x,&y);
			if(b==1)
			{
				if(x>=8 && x<=78 && y>=405 && y<=440)
				{
					flag=1;
					goto y;
				}else if(x>=399 && x<=559 && y>=179 && y<=299)
				{
					flag=2;
					goto y;
				}else if(x>=79 && x<=239 && y>=179 && y<=299)
				{
					flag=3;
					goto y;
				}
			}
			goto x;
		}
		y:
		switch(flag)
		{
			case 1:
			cd;
			startpage();
			break;

			case 2:
			exit(0);

			case 3:
			cd;
			newschool();
			break;
		}

	}
};
/*
	For mouse pointer counter
	char *c;
	itoa(x,c,10);
	setcolor(WHITE);
	printxy(1,1,"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
	printxy(2,1,"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
	printxy(3,1,"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB ");
	setcolor(RED);
	printxy(1,1,c);
	itoa(y,c,10);
	printxy(80,1,c);
	delay(10);

*/
void main()
{
school a;
a.startpage();

//getch();
}
