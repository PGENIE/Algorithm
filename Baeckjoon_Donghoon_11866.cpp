#include <iostream>
#include <vector>

using namespace std;



int main(void)
{
	int N, M;
	int k = -1;
	vector<int> v;
	vector<int>::iterator iter;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}

	cout << '<';
	iter = v.begin();
	while (v.size()!=1)
	{
		for (int i = 0; i < M - 1; i++)
		{
			iter++;
			if (iter == v.end())
				iter = v.begin();
		}
		cout << *iter << ", ";
		iter = v.erase(iter);
		if (iter == v.end())
			iter = v.begin();
	}
	cout << *iter << '>';

		return 0;
}
