#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"game.h"
#include<time.h>
#include<stdlib.h>

void menu()
{
	printf("**********************\n");
	printf("******* 1.play *******\n");
	printf("******* 2.exit *******\n");
	printf("**********************\n");
}

void game()
{
	srand((unsigned int)time(NULL));
	int is_no;
	char board[ROW][COL] = { 0 };
	Initboard(board);//棋盘数据初始化
	DisplayBoard(board);//陈列棋盘
	/*
	1->继续
	2->玩家赢
	3->电脑赢
	4->平局
	*/
	do
	{
		Peoplego(board);
		DisplayBoard(board);
		is_no = Is_No(board);
		if (is_no != 1)
		{
			break;
		}
		Comptergo(board);
		DisplayBoard(board);
	} while (is_no == 1);
	if (is_no == 2)
		printf("恭喜玩家获胜！！！\n");
	if (is_no == 3)
		printf("电脑获胜\n");
	if (is_no == 4)
		printf("平局\n");
}


int main()
{
	int choice;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("游戏开始！！！\n\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (1);
	return 0;
}