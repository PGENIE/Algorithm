#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef struct info {
	int time;
	int pay;
}info;

vector<info> schedule;
vector<int> maxPay;
int n;
int nowMax = 0;

void dp(int d)
{
	if (d == 0)
		return;
	if (nowMax < maxPay[d] + maxPay[d + schedule[d].time])
	{
		nowMax = maxPay[d] + maxPay[d + schedule[d].time];
		maxPay[d] = maxPay[d] + maxPay[d + schedule[d].time];
	}
	else
	{
		maxPay[d] = nowMax;
	}
	dp(d - 1);
}
int main()
{
	int i, j;

	scanf("%d", &n);

	schedule.resize(21, { 0,0 });
	maxPay.resize(21,0);

	int t, p;
	for (i = 1; i < n + 1; i++)
	{
		scanf("%d %d", &t, &p);
		schedule[i].time = t;
		schedule[i].pay = p;

	}

	for (i = 1; i < n + 1; i++)
	{
		if (i + schedule[i].time > n + 1)
			maxPay[i] = 0;
		else
			maxPay[i] = schedule[i].pay;
	}

	dp(n);

	printf("%d", nowMax);

	system("pause");
}