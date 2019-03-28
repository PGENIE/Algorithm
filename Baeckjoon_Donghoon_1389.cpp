#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int** relation;
bool* visited;
int* kebin;
int* sum;
int kebin_num = 999999999;
int kebin_person = 0;
queue<int> q;
void bfs(int start);

int main(void) {
	cin >> N >> M;

	relation = (int**)malloc(sizeof(int*)*(N + 1));
	visited = (bool*)malloc(sizeof(bool)*(N + 1));
	kebin = (int*)malloc(sizeof(int)*(N + 1));
	sum = (int*)malloc(sizeof(int)*(N + 1));

	for (int i = 0; i <= N + 1; i++)
	{
		relation[i] = (int*)malloc(sizeof(int) * (N + 1));
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		relation[a][b] = relation[b][a] = 1;
	}

	for (int i = 0; i <= N; i++)
	{
		sum[i] = 0;
		kebin[i] = 0;
		visited[i] = false;
	}

	//memset(visited, false, sizeof(visited)*(N+1));


	for (int i = 1; i <= N; i++)
	{
		bfs(i);
		//memset(visited, false, sizeof(visited)*(N+1));
		for (int k = 1; k <= N; k++)
			visited[k] = false;
		for (int j = 1; j <= N; j++)
		{
			sum[i] += kebin[j];
			kebin[j] = 0;
		}

		if (kebin_num > sum[i])
		{
			kebin_num = sum[i];
			kebin_person = i;
		}
	}

	cout << kebin_person << endl;
	return 0;

}

void bfs(int start) {
	visited[start] = true;
	q.push(start);
	int temp = 0;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (visited[i]==false && relation[temp][i]==1)
			{
				visited[i] = true;
				q.push(i);
				kebin[i] = kebin[temp] + 1;
			}
		}
	}
}
