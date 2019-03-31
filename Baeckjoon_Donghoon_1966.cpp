#include <cstdio>
#include <queue>
#pragma warning(disable :4996)

using namespace std;

int main(void)
{
	int testcase;
	scanf("%d", &testcase);
	
	for (int loop = 0; loop < testcase; loop++)
	{
		int N, M, answer = 0;
		queue <pair<int, int>> q;
		priority_queue <int> pq;

		scanf("%d %d", &N, &M);

		for (int i = 0; i < N; i++)
		{
			int temp;
			scanf("%d", &temp);
			q.push({ i,temp });
			pq.push(temp);
		}

		while (!q.empty())
		{
			int nowidx = q.front().first;
			int nowval = q.front().second;
			q.pop();

			if (pq.top() == nowval)
			{
				pq.pop();
				answer++;
				if (nowidx == M)
				{
					printf("%d\n", answer);
					break;
				}
			}
			else {
				q.push({ nowidx,nowval });
			}
		}
		

	}
	return 0;
}
