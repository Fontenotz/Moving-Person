#include<iostream.h>
#include<stdlib.h>
#include<time.h>

char board[5][5]=
{
	'*','*','*','*','*',
	'*','*','*','*','*',
	'*','*','P','*','*',
	'*','*','*','*','*',
	'*','*','*','*','*',
};

int x=2;
int y=2;
int z=0;

void move();
void showboard();
void wait();

int main()
{
	srand(time(0));

	system("cls");
	showboard();
	z++;
	cout<<"Number of moves "<<z<<endl;
	move();
	wait();
	main();

	return 0;
}

void showboard()
{
	for (int a=0;a<5;a++)
	{
		for (int b=0;b<5;b++)
		{
			cout<<board[a][b]<<"  ";
		}
		cout<<endl;
	}
}

void move()
{
	
	int direction;
	direction=rand()%4;
	if (direction==0)
	{
		if (x<4)
		{
			x=x+1;
			board[x-1][y]='*';
			board[x][y]='P';

		}
		else
		{
			move();
		}
	}
	else if (direction==1)
	{
		if (x>0)
		{
			x=x-1;
			board[x+1][y]='*';
			board[x][y]='P';

		}
		else
		{
			move();
		}
	}
	else if (direction==2)
	{
		if (y<4)
		{
			y=y+1;
			board[x][y-1]='*';
			board[x][y]='P';

		}
		else
		{
			move();
		}
	}
	else
	{
		if (y>0)
		{
			y=y-1;
			board[x][y+1]='*';
			board[x][y]='P';
			
		}
		else
		{
			move();
		}
	}
}

void wait()
{
	clock_t endwait;
	endwait=clock()+.25*CLK_TCK;
	while (clock()<endwait){}
}
