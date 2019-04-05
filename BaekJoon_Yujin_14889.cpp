#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<vector<int>> map;
vector<int> teamA;
vector<int> teamB;
vector<int> result;
int teamAsum;
int teamBsum;
int n;

void findSum()
{
	int i, j;
	teamAsum = 0;
	teamBsum = 0;

	for (i = 0; i < teamA.size(); i++)
	{
		for (j = i + 1; j < teamA.size(); j++)
		{
			teamAsum += map[teamA[i]][teamA[j]];
			teamAsum += map[teamA[j]][teamA[i]];

			teamBsum += map[teamB[i]][teamB[j]];
			teamBsum += map[teamB[j]][teamB[i]];
		}
	}

	result.push_back(abs(teamAsum - teamBsum));
	
}

void divideTeam()
{
	int i, j;

	vector<int> twoTeam(n,0);
	for (i = 1; i <= n/2; i++)
	{
		twoTeam[n - i] = 1;
	}

	do {
		for (i = 0; i < twoTeam.size(); i++)
		{
			if (twoTeam[i] == 0)
				teamA.push_back(i);
			else
				teamB.push_back(i);
		}
		findSum();
		teamA.clear();
		teamB.clear();
	} while (next_permutation(twoTeam.begin(), twoTeam.end()));
}

int main()
{
	int i,j;

	cin >> n;
	map.resize(n, vector<int> (n,0));

	for (i = 0; i < n; i++)
	{
		for(j = 0 ; j < n ; j++)
			cin >> map[i][j];
	}

	divideTeam();

	sort(result.begin(), result.end());

	cout << result[0];

	system("pause");
}