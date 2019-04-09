#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef struct line {
	int a;
	int b;
}line;

typedef struct pos {
	int y;
	int x;
}pos;

vector<pos> added;
vector<vector<int>> map;
vector<vector<int>> mapCopy;
vector<line> none;
int n, m, h;

bool goDown()
{
	int i, j;
	bool checkResult = false;

	for (i = 0; i <= n - 1; i++)
	{
		int nowx = i; int nowy = 0;

		while (nowy != h)
		{

			if (nowy == h)
			{
				break;
			}

			if (nowx == 0)//오른쪽만 무브 가능
			{
				if (map[nowy][nowx] == 1)
				{
					nowy++; nowx++;
				}
				else
					nowy++;
			}
			else if (nowx == n - 1)//왼쪽만 무브 가능
			{
				if (map[nowy][nowx - 1] == 1)
				{
					nowy++; nowx--;
				}
				else nowy++;
			}
			else //양쪽 다 무브 가능
			{
				if (map[nowy][nowx] == 1)
				{
					nowy++; nowx++;
				}
				else if (map[nowy][nowx - 1] == 1)
				{
					nowy++; nowx--;
				}
				else
				{
					nowy++;
				}
			}

		}
		if (nowx == i)
			continue;
		else
			return false;
	}
	return true;
}
bool addLine(int cnt)
{
	int i, j;
	int addCnt = 0;

	if (cnt > none.size())
	{
		return false;
	}
	vector<int> coord(none.size(), 0);

	for (i = 0; i < cnt; i++)
	{
		coord[coord.size() - 1 - i] = 1;
	}

	do {
		for (i = 0; i < coord.size(); i++)
		{
			if (coord[i] == 1)//가로선 추가할 것
			{
				if (none[i].b == 0)//오른쪽만 확인
				{
					if (map[none[i].a][none[i].b] == 0)
					{
						map[none[i].a][none[i].b] = 1;
						addCnt++;
					}

				}
				else if (none[i].b == n - 2)//왼쪽만 확인
				{
					if (map[none[i].a][none[i].b - 1] == 0)
					{
						map[none[i].a][none[i].b] = 1;
						addCnt++;
					}
				}
				else//오-왼 다확인
				{
					if (map[none[i].a][none[i].b - 1] == 0)
					{
						map[none[i].a][none[i].b] = 1;
						addCnt++;
					}
					else if (map[none[i].a][none[i].b] == 0)
					{
						map[none[i].a][none[i].b] = 1;
						addCnt++;
					}
				}
			}
		}
		if (addCnt == cnt)
		{

			if (goDown() == true)
			{
				return true;
			}

		}
		map = mapCopy;


		addCnt = 0;
	} while (next_permutation(coord.begin(), coord.end()));
	return false;
}
int main()
{
	int i, j;

	scanf("%d %d %d", &n, &m, &h);

	map.resize(h, vector<int>(n - 1, 0));

	for (i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a - 1][b - 1] = 1;
	}
	mapCopy = map;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (map[i][j] == 0)
			{
				none.push_back({ i,j });
			}
		}
	}

	bool find = false;
	for (i = 0; i <= 3; i++)
	{
		if (addLine(i) == true)
		{
			find = true;
			printf("%d", i);
			break;
		}
	}
	if (find == false)
		printf("-1");

	system("pause");

}