#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 3
#define MAX_COL 3
//ȫ�ֱ������������ʼ��Ҳ�ᱻ�Զ���ʼ����ȫΪ0
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
	printf("������ӣ�\n");
	while(1)
	{
	printf("������Ҫ����λ�õ����꣨�У��У���");
	int row = 0;
	int col = 0;
	scanf_s("%d %d", &row, &col);
	//�û������������û�п���shi9�Ƿ����ݣ�
	if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
		printf("���������������������룡\n");
		continue;
	if (chess_board[row][col] != ' ')
	{
		printf("��������λ���������ӣ�\n");
		continue;
	}
	//��Ľ�������
	chess_board[row][col] = 'x';
	break;
	}
	
}
void ComputerMove()
{
	printf("��������\n");
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
//����������ˣ�����1��û������0
int IsFull()
{
	//ѭ�������������̣�ֻҪ�ҵ�һ���ո񣬾�û����������û�ҵ��ո��ʾ����
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
//���ء�x����ʾ��һ�ʤ
//���ء�o����ʾ���Ի�ʤ
//���ء� ����ʾʤ��δ��
//���ء�q����ʾ����
char CheckWinner()
{
	//1.���������
	for (int row = 0; row < MAX_ROW; row++)
	{
		if (chess_board[row][0] != ' '&&chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2])
		{
			return chess_board[row][0];
		}
	}
	//2.���������
	for (int col = 0; col < MAX_COL; col++)
	{
		if (chess_board[0][col] != ' '&&chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col])
		{
			return chess_board[0][col];
		}
	}
	//3.�ټ��Խ���
	if (chess_board[0][2] != ' '&&chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2])
	{

	}
	if (chess_board[0][2] != ' '&&chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0])
	{
		return chess_board[0][2];
	}

	//4.�Ƿ����
	if (IsFull())
	{
		return 'q';
	}
	return ' ';
}
int main()
{
	//1.�������̣�����ʼ����ȫ�ǿո�
	Init();
	char winner = ' ';
	while (1)
	{
	//2.��ӡ����
	PrintChessBoard();
	//3.Ҫ��������ӣ��û���������
	playMove();
	//4.�ж���Ϸʤ��
	winner = CheckWinner();
	if (winner != ' ')
	{
		break;
	}
	//5.Ҫ��������ӣ��������
	ComputerMove();
	//6.�ж���Ϸʤ��
	char winner = CheckWinner();
	if (winner != ' ')
	{
		break;
	}
	if (winner == 'x')
	{
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
	else if (winner == 'o')
	{
		printf("��ˣ�Ӯ��������!\n");
	}
	else {
		printf("�㻹�ǲˣ��͵���һ��ˮƽ!\n");
	}
	system("pause");
	return 0;
	// 7.�ص�2ѭ��ִ��

	}
	

	system("pause");
	return 0;
}