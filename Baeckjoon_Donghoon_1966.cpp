#include <iostream>
#include <queue>

using namespace std;

int documents[100] = { 0, };
int importance[100] = { 0, };
int answer = 1;
int temp;
int on = 0;
queue<int> q;
int main(void)
{
	int test_case, N, M;
	cin >> test_case >> N >> M;

	for (int i = 0; i < test_case; i++)
	{
		memset(documents, 0, sizeof(documents));

		for (int h = 0; h < N; h++)
		{
			cin >> documents[h];
		}

		for (int j = 0; j < M; j++)
		{
			temp = q.front();
			q.pop();
			q.push(temp);
		}

		temp = q.front();
		q.pop();
		while(!q.empty())
		{
			if (temp < q.front())
			{
				answer++;
				on = 1;
			}
			else if (temp == q.front() && on == 1)
				answer++;
			q.pop();
		}
		cout << answer << endl;
	}













	return 0;
}