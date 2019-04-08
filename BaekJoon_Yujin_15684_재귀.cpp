#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int N, M, H;
bool checkLedder(vector<vector<int> >& ledder)
{

	for (int i = 0; i < N; i++)
	{
		int arrow = i;
		for (int j = 0; j < H; j++)
		{
			if (arrow < N - 1 && ledder[j][arrow] == 1)
			{
				arrow++;
			}
			else if (arrow > 0 && ledder[j][arrow - 1] == 1)
			{
				arrow--;
			}
		}
		if (arrow != i)
			return false;
	}
	return true;
}

void fake(vector<vector<int> >& ledder, int cnt, int& result, int x, int y)
{

	if (checkLedder(ledder))
	{
		if (result > cnt)
			result = cnt;
	}
	if (cnt == 3)
	{
		return;
	}
	if (cnt + 1 >= result)
		return;

	bool isFirst = true;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (isFirst)
			{
				i = y;
				j = x;
				isFirst = false;
			}
			if (j + 1 < N - 1 && ledder[i][j + 1] == 1)
				continue;

			if (j - 1 >= 0 && ledder[i][j - 1] == 1)
				continue;

			if (cnt + 1 >= result)
				return;
			if (ledder[i][j] == 0)
			{
				ledder[i][j] = 1;
				fake(ledder, cnt + 1, result, j, i);
				ledder[i][j] = 0;
			}
		}
	}
}

int main()
{
	//fstream FILE("input.txt");
	cin >> N >> M >> H;
	int result = 5;

	vector<vector<int> > ledder(H, vector<int>(N - 1, 0));
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ledder[a - 1][b - 1] = 1;
	}

	fake(ledder, 0, result, 0, 0);


	if (result == 5)
		cout << -1 << endl;
	else
		cout << result << endl;

	return 0;
}