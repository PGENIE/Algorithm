#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

typedef struct side{
	int left;
	int right;
}side;
int k;
vector<vector<int>> wheels(5,vector<int> (8,0));
vector<side> wheelside(5);
vector<int> wheeldirection(5);

//2�� ������, 6�� ����
//�´��� ���� ������ ȸ������ �ʰ�, �ٸ��� �ݴ� �������� ȸ���Ѵ�. 

void roll()
{
	//������ �����ش�
	int i, j;

	for (i = 1; i <= 4; i++)
	{
		vector<int> wheelcopy = wheels[i];
		if (wheeldirection[i] == -1)//�ݽð�
		{
			//0�ڸ��� 1�ְ� ����
			for (j = 1; j < 8; j++)
			{
				wheels[i][j-1] = wheelcopy[j];
			}
			wheels[i][7] = wheelcopy[0];
		}
		if (wheeldirection[i] == 1)//�ð�
		{
			//0�ڸ��� 7�ְ� ����
			int tmp = wheels[i][7];
			for (j = 1; j < 8; j++)
			{
				wheels[i][j] = wheelcopy[j-1];
			}
			wheels[i][0] = wheelcopy[7];
		}
		if (wheeldirection[i] == 9)//����
		{
			
		}
	}
	wheeldirection.clear();
	wheeldirection.resize(5);
}
void findRoll(int wheelnum, int direction)
{
	int i, j;

	for (i = 1; i <= 4; i++)
	{
		wheelside[i].right = wheels[i][2];
		wheelside[i].left = wheels[i][6];
	}

	if (wheelnum == 1)
	{
		wheeldirection[1] = direction;

		//1->2
		if (wheelside[1].right == wheelside[2].left || wheeldirection[1] == 9)//������ �ȿ�����
		{
			wheeldirection[2] = 9;
		}
		else //�ٸ��� �ݴ�������� ������
		{
			if (direction == -1)
			{
				wheeldirection[2] = 1;
			}
			else
				wheeldirection[2] = -1;
		}
		//2->3
		if (wheelside[2].right == wheelside[3].left || wheeldirection[2] == 9)//������ �ȿ�����
		{
			wheeldirection[3] = 9;
		}
		else //�ٸ��� �ݴ�������� ������
		{
			if (wheeldirection[2] == -1)
			{
				wheeldirection[3] = 1;
			}
			else
				wheeldirection[3] = -1;
		}
		//3->4
		if (wheelside[3].right == wheelside[4].left || wheeldirection[3] == 9)//������ �ȿ�����
		{
			wheeldirection[4] = 9;
		}
		else //�ٸ��� �ݴ�������� ������
		{
			if (wheeldirection[3] == -1)
			{
				wheeldirection[4] = 1;
			}
			else
				wheeldirection[4] = -1;
		}

		roll();
	}
	if (wheelnum == 2)
	{
		wheeldirection[2] = direction;
		//2->1
		if (wheelside[2].left == wheelside[1].right || wheeldirection[2] == 9)
		{
			wheeldirection[1] = 9;
		}
		else
		{
			if (wheeldirection[2] == -1)
			{
				wheeldirection[1] = 1;
			}
			else
			{
				wheeldirection[1] = -1;
			}
		}
		//2->3
		if (wheelside[2].right == wheelside[3].left || wheeldirection[2] == 9)//������ �ȿ�����
		{
			wheeldirection[3] = 9;
		}
		else //�ٸ��� �ݴ�������� ������
		{
			if (wheeldirection[2] == -1)
			{
				wheeldirection[3] = 1;
			}
			else
				wheeldirection[3] = -1;
		}
		//3->4
		if (wheelside[3].right == wheelside[4].left || wheeldirection[3] == 9)//������ �ȿ�����
		{
			wheeldirection[4] = 9;
		}
		else //�ٸ��� �ݴ�������� ������
		{
			if (wheeldirection[3] == -1)
			{
				wheeldirection[4] = 1;
			}
			else
				wheeldirection[4] = -1;
		}

		roll();
	}
	if (wheelnum == 3)
	{
		wheeldirection[3] = direction;
		//3->2
		if (wheelside[3].left == wheelside[2].right || wheeldirection[3] == 9)
		{
			wheeldirection[2] = 9;
		}
		else
		{
			if (wheeldirection[3] == -1)
			{
				wheeldirection[2] = 1;
			}
			else
			{
				wheeldirection[2] = -1;
			}
		}
		//2->1
		if (wheelside[2].left == wheelside[1].right || wheeldirection[2] == 9)
		{
			wheeldirection[1] = 9;
		}
		else
		{
			if (wheeldirection[2] == -1)
			{
				wheeldirection[1] = 1;
			}
			else
			{
				wheeldirection[1] = -1;
			}
		}
		//3->4
		if (wheelside[3].right == wheelside[4].left || wheeldirection[3] == 9)//������ �ȿ�����
		{
			wheeldirection[4] = 9;
		}
		else //�ٸ��� �ݴ�������� ������
		{
			if (wheeldirection[3] == -1)
			{
				wheeldirection[4] = 1;
			}
			else
				wheeldirection[4] = -1;
		}

		roll();
	}
	if (wheelnum == 4)
	{
		wheeldirection[4] = direction;
		//4->3
		if (wheelside[4].left == wheelside[3].right || wheeldirection[4] == 9)
		{
			wheeldirection[3] = 9;
		}
		else
		{
			if (wheeldirection[4] == -1)
			{
				wheeldirection[3] = 1;
			}
			else
			{
				wheeldirection[3] = -1;
			}
		}
		//3->2
		if (wheelside[3].left == wheelside[2].right || wheeldirection[3] == 9)
		{
			wheeldirection[2] = 9;
		}
		else
		{
			if (wheeldirection[3] == -1)
			{
				wheeldirection[2] = 1;
			}
			else
			{
				wheeldirection[2] = -1;
			}
		}
		//2->1
		if (wheelside[2].left == wheelside[1].right || wheeldirection[2] == 9)
		{
			wheeldirection[1] = 9;
		}
		else
		{
			if (wheeldirection[2] == -1)
			{
				wheeldirection[1] = 1;
			}
			else
			{
				wheeldirection[1] = -1;
			}
		}
		roll();
	}
}
int calculatePoint()
{
	int sum = 0;
	if (wheels[1][0] == 1)
		sum += 1;
	if (wheels[2][0] == 1)
		sum += 2;
	if (wheels[3][0] == 1)
		sum += 4;
	if (wheels[4][0] == 1)
		sum += 8;

	return sum;
}
int main()
{
	int i, j;
	char tmp;

	for (i = 1; i <= 4; i++)
	{
		for (j = 0; j < 8; j++)
		{
			scanf("%c", &tmp);
			wheels[i][j] = tmp - '0';
		}
		scanf("%c", &tmp); //\n
	}

	scanf("%d", &k);
	int wheelnum, direction;
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &wheelnum, &direction);
		findRoll(wheelnum, direction);
	}

	printf("%d", calculatePoint());

	system("pause");
}