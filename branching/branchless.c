#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int r,c;
char nextVal(char **board, int x, int y) {
	char i = (board[x][y]=='.')?'1':board[x][y]+1;
	int j = 0;
	int k = 0;
	int arr[10];
	memset(arr, 0, sizeof(int)*10);
	for (j = 0; j < r; j++) {
		if (board[j][y] == '.')
			continue;
		arr[board[j][y]-'0'] += 2;
		arr[board[j][y]-'0'] >>= 1;
	}
	for (j = 0; j < c; j++) {
		if (board[x][j] == '.')
			continue;
		arr[board[x][j]-'0'] += 2;
		arr[board[x][j]-'0'] >>= 1;
	}
	for (j = x/3*3; j < (x/3+1)*3; j++) {
		for (k = y/3*3; k < (y/3+1)*3; k++) {
			if (j == x && k == y)
				continue;
			if (j >= r || k >= c)
				continue;
			if ('.' != board[j][k]) {
				arr[board[j][k]-'0'] += 2;
				arr[board[j][k]-'0'] >>= 1;
			}
		}
	}
	for (; i <= '9'; i++) {
		if (arr[i-'0'])
			continue;
		else return i;
	}
	return '.';
}

int nextPos(char **board, int x, int y, int *m, int *n) {
	while (board[x][y] != '.') {
		if (y+1 < c) {
			y++;
		}
		else if (x+1 < r) {
			y = 0;
			x++;
		} else return 1;
	}
	*m = x;
	*n = y;
	return 0;
}

int tryFill(char **board, int x, int y) {
	int ret = 0;
	int m, n;
	while (1) {
		board[x][y] = nextVal(board, x, y);
		if ('.' == board[x][y])
			return 1;
		if (nextPos(board, x, y, &m, &n)) {
			break;
		}
		else {
			if (tryFill(board, m, n)) {
				board[m][n] = '.';
				continue;
			} else {
				return 0;
			}
		}
	}
	return 0;
}

void solveSudoku(char **board, int boardRowSize, int boardColSize) {
	int m, n;
	int ret = 1;

	r = boardRowSize;
	c = boardColSize;
	if (!nextPos(board, 0, 0, &m, &n))
		ret = tryFill(board, m, n);
	return;
}

int main()
{
	char **c = malloc(9*sizeof(char*));
	int i = 0;
	for (; i < 9; i++) {
		c[i] = malloc(9*sizeof(char));
	}
	strcpy(c[0],"53..7....");
	strcpy(c[1],"6..195...");
	strcpy(c[2],".98....6.");
	strcpy(c[3],"8...6...3");
	strcpy(c[4],"4..8.3..1");
	strcpy(c[5],"7...2...6");
	strcpy(c[6],".6....28.");
	strcpy(c[7],"...419..5");
	strcpy(c[8],"....8..79");
	solveSudoku((char **)c,9,9);
	return 0;
}
