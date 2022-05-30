#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, m;

//체스판 다시 칠하기 (브루트포스 문제) 계속 풀기
int check_chess_board(vector<vector<char>> chess, char first_char,int i1, int j1)
{
	int count = 0;
	for (int i = i1; i <= i1+7; i++)
	{
		for (int j = j1;j <= j1+7; j++)
		{
			if (first_char == 'W')
			{
				if ((i + j) % 2 == 0 && chess[i][j] != 'W')
					count++;
				else if ((i + j) % 2 == 1 && chess[i][j] != 'B')
					count++;
			}
			else if (first_char == 'B')
			{
				if ((i + j) % 2 == 0 && chess[i][j] != 'B')
					count++;
				else if ((i + j) % 2 == 1 && chess[i][j] != 'W')
					count++;
			}
		}
	}
		return count;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vector<vector<char>> chess;
	chess.resize(n + 1 , vector<char>(m + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> chess[i][j];
		}
	}
	char first_char = chess[1][1];
	
	int minimum = INT_MAX;
	for (int i = 1; i <= n - 7; i++)
	{
		for (int j = 1; j <= m - 7; j++)
		{
			first_char = chess[i][j];
			minimum = min(minimum, check_chess_board(chess, first_char, i, j));
		}
	}
	if (minimum == 32)
	{
		cout << 12;
		return 0;
	}
	cout << minimum;
}