#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3

void Initboard(char board[ROW][COL]);
void DisplayBoard(char board[ROW][COL]);
void Peoplego(char board[ROW][COL]);
void Comptergo(char board[ROW][COL]);
int Is_No(char board[ROW][COL]);
int isfull(char board[ROW][COL]);