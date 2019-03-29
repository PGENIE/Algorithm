#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int main(void)
{
	int N, M;
	int k = -1;
	vector<int> numbers;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		numbers.push_back(i + 1);

	cout << '<';
	for (int i = 0; i < N; i++)
	{
		k += M;
		cout << numbers[k%N];
		cout << ',';
		cout << " ";
	}
	cout << '>';

		return 0;
}