#include<iostream>
#include<string>

using namespace std;

int testCase;
int main()
{
	cin >> testCase;

	int i, j;

	for (i = 1; i <= testCase; i++)
	{
		int N; string X;
		int sum = 0;

		cin >> N >> X;

		for (char t: X)
		{
			sum += t - '0';
		}

		cout << "#" << i << " " << sum % (N - 1) << "\n";
	}

	system("pause");
}

/* 왜틀린지 모르겠음
#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

int testCase, n;

int main()
{
	int result = 0 ;
	char tmp = 'a';
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++)
	{
		result = 0;
		scanf("%d",&n);
		scanf("%c", &tmp);
		while (1)
		{
			scanf("%c", &tmp);
			if (tmp == '\n')
			{
				break;
			}
				result += tmp - '0';
		}

		printf("#%d %d\n", i + 1, result%(n-1));

	}

}*/