#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef struct pos{
	int x;
	int y;
}pos;

int testCase;
int n;
vector<long long> result;
vector<int> oddEven;
vector<int> couple; //11 22 33 44 55
vector<pos> wormList; //input��� �־��� ����Ʈ
vector<pos> coupleDir; //a to b, b to a, 2�� ab, 2�� ba, ... �̷���
vector<pos> coupleList; //1���� 1����/ 2���� 2����/ 3���� 3����/ .. �̷������� ���ĵ�
int sumx = 0; int sumy = 0;
signed long long sum_min = 99999999999;

long long allCase(int index)
{
	if (index >= n / 2)
	{
		//0000�̸� 0,2,4,8,.... 1111�̸� 1,3,5,7,.... �̷���
		for (int i = 0; i < oddEven.size(); i++)
		{
			if (oddEven[i] == 0)
			{
				sumx += coupleDir[i * 2].x;
				sumy += coupleDir[i * 2].y;
			}
			else
			{
				sumx += coupleDir[i * 2 + 1].x;
				sumy += coupleDir[i * 2 + 1].y;
			}
		}
		if (sum_min > (sumx * sumx) + (sumy * sumy))
			sum_min = (sumx * sumx) + (sumy * sumy);

		sumx = 0; sumy = 0;
		
		return sum_min;
	}
	for (int i = 0; i <= 1; i++)
	{
		oddEven[index] = i;
		allCase(index + 1);
	}
}
void findCoord()
{
	int i, j;

	do {
		for (i = 1; i <= n / 2; i++)//i��Ŀ�ó��� ¦����
		{
			for (j = 0; j < n; j++)
			{
				if (couple[j] == i)
				{
					coupleList.push_back(wormList[j]);
				}
			}
		}
		for (i = 0; i < n; i += 2)
		{
			coupleDir.push_back({ coupleList[i].x - coupleList[i + 1].x , coupleList[i].y - coupleList[i + 1].y });
			coupleDir.push_back({ coupleList[i+1].x - coupleList[i].x , coupleList[i+1].y - coupleList[i].y });
		}

		allCase(0);
		coupleList.clear();
		coupleDir.clear();
	} while (next_permutation(couple.begin(), couple.end()));
}

int main()
{
	int i, j;

	scanf("%d", &testCase);
	
	for (i = 0; i < testCase; i++)
	{
		scanf("%d", &n);

		for(j = 0 ; j < n ; j++)
		{
			int x, y;
			scanf("%lld %lld", &x, &y);
			wormList.push_back({x,y});
		}
		oddEven.resize(n/2);
		findCoord();

		result.push_back(sum_min);

		sum_min = 99999999999;
		oddEven.clear();
		couple.clear();
		wormList.clear();
	}

	for (i = 0; i < result.size(); i++)
	{
		printf("#%d %lld\n", i + 1, result[i]);
	}

	system("pause");
}