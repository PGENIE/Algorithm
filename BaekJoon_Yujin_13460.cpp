#include<stdio.h>
#include<vector>

using namespace std;

typedef struct pos {
	int y;
	int x;
}pos;

vector<vector<int>> map;
vector<vector<int>> mapCopy;
vector<int> direction;
int n, m;
int minValue = 20;
int maxCnt = 9;
pos red, blue, hole;
pos redCopy, blueCopy, holeCopy;
//동 서 남 북 0 1 2 3 순

int moveBall()
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		if (direction[i] == 0) //동쪽으로 움직이면
		{
			//더 동쪽에 있는 애(x값이 더 큰 애)부터 움직인다.
			if (blue.x < red.x)
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1) //red move. 벽이나 구멍을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽
						{
							red.x--;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.x++;
				}
				while (1) //blue move. 벽이나 구멍이나 red구슬을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.x--;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.x++;
				}
			}
			else
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1) //blue move. 벽이나 구멍을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.x--;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.x++;

				}
				while (1) //red move. 벽이나 구멍이나 blue구슬을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽 or 구슬
						{
							red.x--;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.x++;
				}
			}
			if (red.x == hole.x && red.y == hole.y && blue.x == hole.x && blue.y == hole.y)
				return 20;
			else if (map[red.y][red.x] == 5)
				return i + 1;
			else if (map[blue.y][blue.x] == 5)
				return 20;
		}
		if (direction[i] == 1)//서
		{
			//더 서쪽에 있는 애(값이 작은 애)부터 움직인다.
			if (red.x < blue.x)
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1) //red move. 벽이나 구멍을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽
						{
							red.x++;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.x--;

				}
				while (1) //blue move. 벽이나 구멍이나 red구슬을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.x++;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.x--;
				}
			}
			else
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1) //blue move. 벽이나 구멍을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.x++;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.x--;

				}
				while (1) //red move. 벽이나 구멍이나 blue구슬을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽
						{
							red.x++;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.x--;
				}
			}

			if (red.x == hole.x && red.y == hole.y && blue.x == hole.x && blue.y == hole.y)
				return 20;
			else if (map[red.y][red.x] == 5)
				return i + 1;
			else if (map[blue.y][blue.x] == 5)
				return 20;
		}
		if (direction[i] == 2)//남
		{
			//더 남쪽에 있는 애(더 값이 큰 애) 먼저 움직인다.
			if (blue.y < red.y)//red move
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1)//red가 벽이나 구멍을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽
						{
							red.y--;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.y++;
				}
				while (1) //blue move. 벽이나 구멍이나 red구슬을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.y--;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.y++;

				}
			}
			else //블루먼저이동
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1)//벽이나 구멍을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.y--;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.y++;
				}
				while (1) //red move. 벽이나 구멍이나 blue구슬을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽
						{
							red.y--;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.y++;

				}
			}

			if (red.x == hole.x && red.y == hole.y && blue.x == hole.x && blue.y == hole.y)
				return 20;
			else if (map[red.y][red.x] == 5)
				return i + 1;
			else if (map[blue.y][blue.x] == 5)
				return 20;
		}
		if (direction[i] == 3)//북
		{
			//더 북쪽에 있는 애(더 값이 작은 애) 먼저 움직인다.
			if (red.y < blue.y)//red move
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1)//벽이나 구멍을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽
						{
							red.y++;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.y--;
				}
				while (1) //blue move. 벽이나 구멍이나 red구슬을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.y++;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.y--;

				}
			}
			else //블루먼저이동
			{
				map[red.y][red.x] = 0;
				map[blue.y][blue.x] = 0;

				while (1)//벽이나 구멍을 만날때까지
				{
					if (map[blue.y][blue.x] == 9 || map[blue.y][blue.x] == 5 || map[blue.y][blue.x] == 1)
					{
						if (map[blue.y][blue.x] == 5) // 홀에 들어간 경우
						{
							blue.x = hole.x;
							blue.y = hole.y;
						}
						else //벽이나 빨간구슬과 만난 경우
						{
							blue.y++;
							map[blue.y][blue.x] = 2;
						}
						break;
					}
					blue.y--;
				}
				while (1) //red move. 벽이나 구멍이나 blue구슬을 만날때까지
				{
					if (map[red.y][red.x] == 9 || map[red.y][red.x] == 5 || map[red.y][red.x] == 2)
					{
						if (map[red.y][red.x] == 5)//홀에 들어간경우
						{
							red.x = hole.x;
							red.y = hole.y;
						}
						else //벽
						{
							red.y++;
							map[red.y][red.x] = 1;
						}
						break;
					}
					red.y--;

				}
			}


			if (red.x == hole.x && red.y == hole.y && blue.x == hole.x && blue.y == hole.y)
				return 20;
			else if (map[red.y][red.x] == 5)
				return i + 1;
			else if (map[blue.y][blue.x] == 5)
				return 20;
		}


	}

	return 20;
}
void findDir(int index)
{
	int i;

	if (index > maxCnt)
	{

		map = mapCopy;
		red = redCopy;
		blue = blueCopy;
		int result = moveBall();
		if (minValue > result)
			minValue = result;
		if (minValue < maxCnt)
			maxCnt = minValue;
		return;
	}

	for (i = 0; i < 4; i++)
	{
		direction[index] = i;

		if (index >= 1)
		{
			if (direction[index] == direction[index - 1])
				continue;
		}
		if (index >= 2)
		{
			if (direction[index - 2] == 1 && direction[index - 1] == 0 && direction[index] == 1) //좌-우-좌, 우-좌-우, 하-상-하, 상-하-상 방지
				continue;
			if (direction[index - 2] == 0 && direction[index - 1] == 1 && direction[index] == 0)
				continue;
			if (direction[index - 2] == 2 && direction[index - 1] == 3 && direction[index] == 2)
				continue;
			if (direction[index - 2] == 3 && direction[index - 1] == 2 && direction[index] == 3)
				continue;
		}

		findDir(index + 1);
	}
}

int main()
{
	int i, j;

	scanf("%d %d", &n, &m);

	map.resize(n, vector<int>(m, 0));
	direction.resize(10, 9);

	char tmp;
	scanf("%c", &tmp);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%c", &tmp);
			if (tmp == '#')
			{
				map[i][j] = 9;
			}
			else if (tmp == 'B')
			{
				map[i][j] = 2;
				blue.y = i; blue.x = j;
				blueCopy = blue;
			}
			else if (tmp == 'R')
			{
				map[i][j] = 1;
				red.y = i; red.x = j;
				redCopy = red;
			}
			else if (tmp == 'O')
			{
				map[i][j] = 5;
				hole.y = i; hole.x = j;
				holeCopy = hole;
			}
		}
		scanf("%c", &tmp);
	}

	mapCopy = map;

	findDir(0);

	if (minValue == 20)
	{
		printf("-1");
	}
	else
		printf("%d", minValue);

}