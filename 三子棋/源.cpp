#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 3
#define MAX_COL 3
//全局变量，如果不初始化也会被自动初始化成全为0
char chess_board[MAX_ROW][MAX_COL];
void Init()
{
	for (int row = 0; row < MAX_ROW; row++)
	{ 
		for (int col = 0; col < MAX_COL; col++)
		{
			chess_board[row][col] = ' '; 
		}
	}
}
void PrintChessBoard() 
{
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++)
	{
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("+---+---+---+\n");
	
	}
	system("pause");
}
void playMove() {
	printf("玩家落子！\n");
	while(1)
	{
	printf("请输入要落子位置的坐标（行，列）：");
	int row = 0;
	int col = 0;
	scanf_s("%d %d", &row, &col);
	//用户输入的内容有没有可能shi9非法内容？
	if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
		printf("您的输入有误，请重新输入！\n");
		continue;
	if (chess_board[row][col] != ' ')
	{
		printf("您的输入位置已有棋子！\n");
		continue;
	}
	//真的进行落子
	chess_board[row][col] = 'x';
	break;
	}
	
}
void ComputerMove()
{
	printf("电脑落子\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' ')
		{
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	
}
//棋盘如果满了，返回1，没满返回0
int IsFull()
{
	//循环遍历整个棋盘，只要找到一个空格，就没满，遍历完没找到空格表示满了
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chess_board[row][col] == ' ')
				return 0;
		}
	}
	return 1;
}
//返回‘x’表示玩家获胜
//返回‘o’表示电脑获胜
//返回‘ ’表示胜负未分
//返回‘q’表示和棋
char CheckWinner()
{
	//1.检查所有行
	for (int row = 0; row < MAX_ROW; row++)
	{
		if (chess_board[row][0] != ' '&&chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2])
		{
			return chess_board[row][0];
		}
	}
	//2.检测所有列
	for (int col = 0; col < MAX_COL; col++)
	{
		if (chess_board[0][col] != ' '&&chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col])
		{
			return chess_board[0][col];
		}
	}
	//3.再检测对角线
	if (chess_board[0][2] != ' '&&chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2])
	{

	}
	if (chess_board[0][2] != ' '&&chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0])
	{
		return chess_board[0][2];
	}

	//4.是否和棋
	if (IsFull())
	{
		return 'q';
	}
	return ' ';
}
int main()
{
	//1.创建棋盘，并初始化，全是空格
	Init();
	char winner = ' ';
	while (1)
	{
	//2.打印棋盘
	PrintChessBoard();
	//3.要求玩家落子，用户输入坐标
	playMove();
	//4.判定游戏胜负
	winner = CheckWinner();
	if (winner != ' ')
	{
		break;
	}
	//5.要求电脑落子，随机落子
	ComputerMove();
	//6.判定游戏胜负
	char winner = CheckWinner();
	if (winner != ' ')
	{
		break;
	}
	if (winner == 'x')
	{
		printf("恭喜你，你赢了！\n");
	}
	else if (winner == 'o')
	{
		printf("真菜，赢不过电脑!\n");
	}
	else {
		printf("你还是菜，和电脑一个水平!\n");
	}
	system("pause");
	return 0;
	// 7.回到2循环执行

	}
	

	system("pause");
	return 0;
}