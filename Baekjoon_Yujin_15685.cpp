#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

typedef struct pos {
	int x;
	int y;
}pos;

int n;
vector<vector<int>> map(101, vector<int> (101,0));
vector<vector<pos>> d0(11);
vector<vector<pos>> d1(11);
vector<vector<pos>> d2(11);
vector<vector<pos>> d3(11);
//	d[0].push_back({ 1,2 }); �ϸ� 0������ 0���� �� ��� ��.

void makeGeneration(int g, pos end, vector<vector<pos>>& d)
{
	//1������� 10������� �����. g�� ����
	//���������� �������κ��� ���������� ���� ���� ã�´�. �׷��� ������� �ٲٴ� �� add���ش�.

	if (g > 10)
		return;
	int i, j;
	vector<int> addMove;
	int beforeSize = d[g - 1].size();
	for (i = 0; i < d[g - 1].size() - 1; i++)
	{
		int tmpx; int tmpy;
		tmpx = d[g - 1][beforeSize - 1 - i].x - d[g - 1][d[g - 1].size() - 2 - i].x;
		tmpy = d[g - 1][beforeSize - 1-i].y - d[g - 1][d[g - 1].size() - 2 - i].y;

		if (tmpx == 1 && tmpy == 0)
		{
			//�������� �����ϱ� ���� ������
			addMove.push_back(1);
		}
		else if (tmpx == -1 && tmpy == 0)
		{
			//���������� �����ϱ� �Ʒ�
			addMove.push_back(3);
		}
		else if (tmpx == 0 && tmpy == 1)
		{
			//���� �����ϱ� ������
			addMove.push_back(0);
		}
		else if (tmpx == 0 && tmpy == -1)
		{
			//�Ʒ��� �����ϱ� ����
			addMove.push_back(2);
		}
		else
		{
			printf("error");
		}
		
	} //������ ��

	d[g] = d[g - 1];
	pos tmpend = end;

	for (i = 0; i < addMove.size(); i++)
	{
		if (addMove[i] == 0)
		{
			tmpend.x += 1;
		}
		else if (addMove[i] == 1)
		{
			tmpend.y -= 1;
		}
		else if (addMove[i] == 2)
		{
			tmpend.x -= 1;
		}
		else if (addMove[i] == 3)
		{
			tmpend.y += 1;
		}
	
		d[g].push_back({ tmpend.x ,tmpend.y });
		end = tmpend;
	}
	addMove.clear();
	makeGeneration(g + 1, end, d);

}
void addPoint(int x, int y, int d, int g)
{
	//map[y][x]�� �ִ� �� Ȯ���ϰ� add�� ��
	int i, j;

	if (d == 0)
	{
		for (i = 0; i < d0[g].size(); i++)
		{

			if (map[y + d0[g][i].y][x + d0[g][i].x] != 1)
				map[y + d0[g][i].y][x + d0[g][i].x] = 1;

		}
	}
	else if (d == 1)
	{
		for (i = 0; i < d1[g].size(); i++)
		{
			if (y + d1[g][i].y >= 0 && x + d1[g][i].x >= 0)
			{
				if (map[y + d1[g][i].y][x + d1[g][i].x] != 1)
					map[y + d1[g][i].y][x + d1[g][i].x] = 1;

			}
		}
	}
	else if (d == 2)
	{
		for (i = 0; i < d2[g].size(); i++)
		{
			if (y + d2[g][i].y >= 0 && x + d2[g][i].x >= 0)
			{
				if (map[y + d2[g][i].y][x + d2[g][i].x] != 1)
					map[y + d2[g][i].y][x + d2[g][i].x] = 1;


			}
		}
	}
	else if (d == 3)
	{
		for (i = 0; i < d3[g].size(); i++)
		{
			if (y + d3[g][i].y >= 0 && x + d3[g][i].x >= 0)
			{
				if (map[y + d3[g][i].y][x + d3[g][i].x] != 1)
					map[y + d3[g][i].y][x + d3[g][i].x] = 1;

			}
		}
	}

	
}
int countSquare()
{
	int i, j;
	int cnt = 0;

	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (map[i][j] == 1)
			{
				if (map[i + 1][j] == 1 && map[i + 1][j + 1] == 1 && map[i][j + 1] == 1)
					cnt++;
			}
		}
	}

	return cnt;
}
int main()
{
	int i, j;
	
	d0[0].push_back({ 0,0 });
	d0[0].push_back({ 1,0 });

	d1[0].push_back({ 0,0 });
	d1[0].push_back({ 0,-1 });

	d2[0].push_back({ 0,0 });
	d2[0].push_back({ -1,0 });

	d3[0].push_back({ 0,0 });
	d3[0].push_back({ 0,1 });

	makeGeneration(1, { 1,0 }, d0);
	makeGeneration(1, { 0,-1 }, d1);
	makeGeneration(1, { -1,0 }, d2);
	makeGeneration(1, { 0,1 }, d3);

	scanf("%d", &n);
	int x, y, d, g;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &x, &y, &d, &g);
		addPoint(x, y, d, g);

	}

	printf("%d",countSquare());

	system("pause");
}