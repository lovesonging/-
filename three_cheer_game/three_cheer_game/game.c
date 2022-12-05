#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"game.h"
#include<time.h>
#include<stdlib.h>

void Initboard(char board[ROW][COL])
{
	int i, j;
	for(i=0;i<ROW;i++)
	{
		for (j=0;j<COL;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL])
{
	/* 
	     |     |    
	_____|_____|_____
		 |     |
	_____|_____|_____
	   	 |     |
	     |     |     
	*/
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				if (j < COL - 1)
					printf("  %c  |", board[i][j]);//board[0][0]
				else
					printf("  %c  ", board[i][j]);
			}
			printf("\n");
			for (j = 0; j < COL; j++)
			{
				if (j < COL - 1)
					printf("_____|");
				else
					printf("_____");
			}
		}
		else
		{
				for (j = 0; j < COL; j++)
				{
					if (j < COL - 1)
						printf("  %c  |", board[i][j]);//board[0][0]
					else
						printf("  %c  ", board[i][j]);
				}
				printf("\n");
				for (j = 0; j < COL; j++)
				{
					if (j < COL - 1)
						printf("     |");
					else
						printf("     ");
				}
		}
		printf("\n");
	}
}

void Peoplego(char board[ROW][COL])
{
	int x, y;
	again:
		printf("玩家请输入要下的棋子坐标:>\n(比如>\t1,1)\n");
		scanf("%d,%d", &x, &y);
	if((x-1)>=0&&(x-1)<ROW&& (y - 1) >= 0 && (y - 1) < COL&& board[x - 1][y - 1] == ' ')
	board[x - 1][y - 1] = '*';
	else
	{
		printf("坐标错误\n");
		goto again;
	}
}

void Comptergo(char board[ROW][COL])
{
	printf("电脑下棋:>\n");
	int x, y;
	do
	{
		x = rand() % ROW;
		y = rand() % COL;
	} 
	while (board[x][y] == '*'|| board[x][y] == '#');
	board[x][y] = '#';
}

int Is_No(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == '*')
		{
			return 2;
			break;
		}
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == '#')
		{
			return 3;
			break;
		}
	}
	for (j = 0; j < COL; j++)
	{
		if (board[0][j] == board[1][j] && board[2][j] == board[1][j] && board[2][j] == '*')
		{
			return 2;
		}
		if (board[0][j] == board[1][j] && board[2][j] == board[1][j] && board[2][j] == '#')
		{
			return 3;
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == '*')
	{
		return 2;
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == '#')
	{
		return 3;
	}
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] == '*')
	{
		return 2;
	}
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] == '#')
	{
		return 3;
	}
	else if (isfull(board) == 1)
		return 4;
	else
		return 1;
}

int isfull(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
