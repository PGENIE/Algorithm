#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
/**/
using namespace std;

int n;

int main()
{
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		if (i == 20)
		{
			printf("");
		}
		if (i / 10 == 0) //한자리 수이면
		{

			if (i % 3 == 0) //3,6,9이면
			{
				printf("- ");
			}
			else
				printf("%d ", i);
		}
		else if (i / 100 == 0) //두자리 수이면 37 
		{
			int one = i % 10;
			int ten = i / 10;

			if (i == 10)
			{
				printf("%d ", i);
			}
			//일의자리는 i % 10 십의자리는 i/10
			else if ((i % 10) % 3 == 0 && (i / 10) % 3 == 0 &&i%10 != 0)
			{
				printf("-- ");
			}
			else if ((i % 10) % 3 == 0 && i%10 != 0)
			{
				printf("- ");
			}
			else if ((i / 10) % 3 == 0)
			{
				printf("- ");
			}
			else
				printf("%d ", i);
		}
		else if (i / 1000 == 0) //세자리 수이면 367
		{
			//일의자리는 i%100 십의자리는 (i/10)%10 백의자리는 i/100
			int one = i % 100;
			int ten = (i / 10) % 10;
			int hundred = i / 100;

			if (i == 100)
			{
				printf("%d ", i);
			}
			else if (one % 3 == 0 && ten % 3 == 0 && hundred % 3 == 0 && one != 0 && ten != 0)
			{
				printf("--- ");
			}
			else if ((one % 3 == 0 && ten % 3 == 0 && one != 0 && ten != 0) || (one % 3 == 0 && hundred % 3 == 0 && one != 0)|| (ten % 3 == 0 && hundred % 3 == 0 && ten != 0))
			{
				printf("-- ");
			}
			else if ((one % 3 == 0 && one != 0) || (ten % 3 == 0 && ten != 0) || (hundred % 3 == 0))
			{
				printf("- ");
			}
			else
			{
				printf("%d ", i);
			}
		}
		else
		{
			printf("%d ", i);
		}
	}

	system("pause");
}