#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct element {
	int y;
	int x;
	bool left = false;
	bool right = false;
}element;

int n, m, h;

typedef struct line {
	int a;
	int b;
}line;

vector<vector<int>> map; //����Ǹ� 1 �ƴϸ� 0
vector<vector<int>> mapCopy;
vector<line> none;
vector<line> exist;

bool goDown()
{
	int i, j;
	int numtonum = 0 ;
	vector<bool> result;
	
	for (i = 1; i < n + 1; i++)
	{
		int nowy, nowx;
		nowy = 1; nowx = i;

		while (nowy != h + 1)
		{
			bool move = false;
			if (nowx != 1)//���� ���� �����Ѿֵ�
			{
				if (map[nowy][nowx-1] == 1)
				{
					nowx = nowx - 1; nowy++;
					move = true;
				}
			}
			if (nowx != n && move == false)//������ ���� �����Ѿֵ�
			{
				if (map[nowy][nowx] == 1)
				{
					nowx++; nowy++;
					move = true;
				}
			}
			if(move == false)
				nowy++;
			
		}
		if (i == nowx)
			numtonum++;
		else
		{
			numtonum = 0;
			break;
		}
	}
	
	if (numtonum == n)
		return true;
	else 
		return false;

}
bool addLine(int addCnt)
{
	int i, j;

	vector<int> coord(none.size());
	
	for (i = 0; i < addCnt; i++)
	{
		coord[coord.size() - 1 - i] = 1;
	}

	do {
		for (i = 0; i < coord.size(); i++)
		{
			if (coord[i] == 1)
			{
				map[none[i].a][none[i].b] = 1;
			}
		}
		if (goDown() == true)
		{
			return true;
		}
		map = mapCopy;
	} while (next_permutation(coord.begin(), coord.end()));
	return false;
}
int main()
{
	int i, j;

	cin >> n>> m>> h;

	map.resize(h + 1, vector<int>(n, 0));

	for (i = 0; i < m; i++)//����� ���μ� �޾ƿ���
	{
		int a, b;
		cin >> a>> b;
		map[a][b] = 1;
	}
	mapCopy = map;

	//�� ����
	for (i = 1; i < h + 1; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (map[i][j] == 0)
			{
				line l; l.a = i; l.b = j;
				none.push_back(l);
			}
			else
			{
				line l; l.a = i; l.b = j;
				exist.push_back(l);
			}
		}
	}
	
	bool find = false;
	//���μ� 0�� ~ (n-1)*m - lineCnt ����ŭ
	//����ȵ� �� ��Ͽ��� ��� �� �߰�
	//i->i�ΰ� ���� Ȯ�εǸ�, result�޾Ƽ� break;
	for (i = 0; i <= (n - 1)*h - exist.size(); i++)
	{
		if (addLine(i))
		{
			find = true;
			cout << i;
			break;
		}
	}
	if (find == false)
		cout << "-1";

	system("pause");
}	