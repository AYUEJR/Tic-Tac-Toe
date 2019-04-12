#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Menu() {
	printf("=====================\n");
	printf("1.start game\n");
	printf("0.leave\n");
	printf("=====================\n");
	printf("please input your chioce：  ");
	int chioce = 0;
	scanf("%d", &chioce);
	return chioce;
}

#define MAX_ROW 3
#define MAX_COL 3
char chess_board[MAX_ROW][MAX_COL];

void Init() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			chess_board[row][col] = ' ';
		}
	}
	srand((unsigned int)time(0));
}

void Print() {
	printf("|---|---|---|\n");
	for (int row = 0; row < MAX_ROW; ++row) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("|---|---|---|\n");
	}
}

void Playermove() {
	while (1) {
		printf("player move:\n");
		printf("please input location for row and col:");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//检查输入合法性
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("input error,please try again:");
			continue;
		}if (chess_board[row][col] != ' ') {
			printf("inputing be occupied!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("player finsh!\n");
}

void Computermove() {
	printf("computer move:\n");
	while (1) {
		int row = rand() % 3;
		int col = rand() % 3;
		if (chess_board[row][col] != ' ') {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("computer finish!\n");
}

int isFull() {
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			if (chess_board[row][col] = ' ')
				return 0;
		}
	}
	return 1;
}

char Checkwinner() {
	//检查行
	for (int row = 0; row < MAX_ROW; ++row) {
		if (chess_board[row][0]==chess_board[row][1]&&chess_board[row][0]==chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//检查列
	for (int col = 0; col < MAX_COL; ++col) {
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]) {
			return chess_board[0][col];
		}
	}
	//检查对角线
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2])
		return chess_board[0][0];
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0])
		return chess_board[0][2];
	if (isFull()) {
		return 'q';
	}
	return ' ';
}

void Game() {
	//1。初始化棋盘
	Init();
	char winner = ' ';
	while (1) {
		//2.打印棋盘
		Print();
		//3.player 
		Playermove();
		//4.检测胜负
		winner = Checkwinner();
		if (winner != ' ') {
			break;
		}
		//computer
		Computermove();
		//检测胜负
		winner = Checkwinner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'x') {
		printf("Your are winner!\n");
	}
	else if (winner == 'o') {
		printf("Computer is winner!\n");
	}
	else if (winner == 'q') {
		printf("draw!\n");
	}
	else {
		printf("bug!\n");
	}
}

int main(){
while (1) {
		int chioce = Menu();
		if (chioce == 1) {
			Game();
		}else if (chioce == 0) {
			printf("good bye!");
			break;
		}else {
			printf("input error,please try again:\n");
		}
	}
	system("pause");
	return 0;
}
