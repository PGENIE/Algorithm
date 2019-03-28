#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

vector<char> noHole = { 'C','E','F','G','H','I','J','K','L','M','N','S','T','U','V','W','X','Y','Z' };
vector<char> oneHole = { 'A','D','O','P','Q','R' };
vector<char> twoHole = { 'B' };

int n;
vector<int> vec1; 
vector<int> vec2;

void checkHole(vector<int>& vec, char tmp)
{
	int i;
	bool find = false;

	for (i = 0; i < noHole.size(); i++)
	{
		if (tmp == noHole[i])
		{
			find = true;
			vec.push_back(0);
		}
	}
	if (find == false)
	{
		for (i = 0; i < oneHole.size(); i++)
		{
			if (tmp == oneHole[i])
			{
				find = true;
				vec.push_back(1);
			}
		}
	}
	if (find == false)
	{
		for (i = 0; i < twoHole.size(); i++)
		{
			if (tmp == twoHole[i])
			{
				find = true;
				vec.push_back(2);
			}
		}
	}
}
int main()
{
	int i;
	char tmp;

	scanf("%d", &n);
	scanf("%c", &tmp);
	for (i = 0; i < n; i++)
	{
		while (1)
		{
			scanf("%c", &tmp);
			if (tmp == ' ')
			{
				break;
			}
			else
			{
				checkHole(vec1,tmp);
			}
		}
		while (1)
		{
			scanf("%c", &tmp);
			if (tmp == '\n')
			{
				break;
			}
			else
			{
				checkHole(vec2,tmp);
			}
		}
		bool check = true;
		if (vec1.size() != vec2.size())
		{
			printf("#%d DIFF\n", i + 1);
			vec1.clear(); vec2.clear();
		}
		else
		{
			for (int j = 0; j < vec1.size(); j++)
			{
				if (vec1[j] != vec2[j])
				{
					check = false;
					printf("#%d DIFF\n", i + 1);
					break;
				}
			}
			if (check == true)
			{
				printf("#%d SAME\n", i + 1);
			}
		}
		check = true;
		vec1.clear(); vec2.clear();
	}

	system("pause");
}