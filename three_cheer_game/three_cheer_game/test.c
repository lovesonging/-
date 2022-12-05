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
	Initboard(board);//�������ݳ�ʼ��
	DisplayBoard(board);//��������
	/*
	1->����
	2->���Ӯ
	3->����Ӯ
	4->ƽ��
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
		printf("��ϲ��һ�ʤ������\n");
	if (is_no == 3)
		printf("���Ի�ʤ\n");
	if (is_no == 4)
		printf("ƽ��\n");
}


int main()
{
	int choice;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("��Ϸ��ʼ������\n\n");
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (1);
	return 0;
}