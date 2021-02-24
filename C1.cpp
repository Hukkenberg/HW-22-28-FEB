#include <iostream>
#include <ctime>

using namespace std;

int setGame(int m, int n, int K, int a[m][n])
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;
	for (int i = 0; i < K; i++)
	{
		srand(time(0));
		int bomb_row = rand() / m + 1;
		int bomb_col = rand() / n + 1;
		a[bomb_row][bomb_col] = 1;
	}
}

bool lose_or_not(int a, int b, int set[][])
{
	if (set[a][b] == 1)
		return false;
	else
		return true;
}

int reveal(int m, int n, int set[m][n], int a, int b)
{
	int sum = 0;
	if (set[a + 1][b] == 1)
		sum++;
	if (set[a - 1][b] == 1)
		sum++;
	if (set[a][b + 1] == 1)
		sum++;
	if (set[a][b - 1] == 1)
		sum++;
	if (set[a - 1][b - 1] == 1)
		sum++;
	if (set[a - 1][b + 1] == 1)
		sum++;
	if (set[a + 1][b - 1] == 1)
		sum++;
	if (set[a + 1][b + 1] == 1)
		sum++;
	return sum;
}

int main()
{
	int m, n, K;
	cin >> m >> n >> K;
	int board[m][n];
	setGame(m, n, K, board);
	int choose_col, choose_row;
	bool game_over = true;
	int move;
	do
	{
		cin >> choose_row >> choose_col;
		game_over = lose_or_not(choose_row, choose_col, board);
		if (game_over == true)
			board[choose_row][choose_col] = reveal(m, n, board, choose_row, choose_col);
		move++;
	} while (game_over == false || move == m * n);
	if (game_over == false)
		cout << "YOU'RE DEAD!";
	return 0;
}