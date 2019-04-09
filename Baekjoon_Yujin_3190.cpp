#include<stdio.h>
#include<vector>
#include<deque>
#pragma warning(disable:4996)

//사과 있으면 tail 그대로, 사과 없으면 tail 줄이기
using namespace std;

typedef struct info {
	int sec;
	char direction;
}info;
typedef struct pos {
	int y;
	int x;
}pos;

int time = 0;
int head;
int tail;
int n, k, l;
int ssize = 1;
deque<pos> snake;
vector<vector<int>> map;
vector<info> moveinfo;
//동 남 서 북, 시계방향, 0 1 2 3
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1};

void move(int direction, int index, int before)
{
	int i, j;
	if (index == moveinfo.size())
	{
		while (1)
		{
			pos tmphead;
			tmphead.y = snake[head].y + dy[direction];
			tmphead.x = snake[head].x + dx[direction];

			time++;
			if (map[tmphead.y][tmphead.x] == 9) //벽에 부딫히면
			{
				return;
			}
			if (map[tmphead.y][tmphead.x] == 2) //몸에 부딫히면
			{
				return;
			}
			if (map[tmphead.y][tmphead.x] == 1) //사과이면
			{
				snake.push_front({ tmphead.y,tmphead.x });
				map[tmphead.y][tmphead.x] = 2;
				head = 0;
				tail++;
			}
			else if (map[tmphead.y][tmphead.x] == 0) // 빈자리이면
			{
				map[snake[tail].y][snake[tail].x] = 0;
				snake.push_front({ tmphead.y,tmphead.x });
				map[tmphead.y][tmphead.x] = 2;
				head = 0;
				snake.erase(snake.end() - 1); //tail은 추가하고 지우니까 그대로
			}

		}
	}
	for (i = 0; i < moveinfo[index].sec- before; i++)
	{
		pos tmphead;
		tmphead.y = snake[head].y + dy[direction];
		tmphead.x = snake[head].x + dx[direction];

		time++;
		if (map[tmphead.y][tmphead.x] == 9) //벽에 부딫히면
		{
			return;
		}
		if (map[tmphead.y][tmphead.x] == 2) //몸에 부딫히면
		{
			return;
		}
		if (map[tmphead.y][tmphead.x] == 1) //사과이면
		{
			snake.push_front({tmphead.y,tmphead.x});
			map[tmphead.y][tmphead.x] = 2;
			head = 0;
			tail++;
		}
		else if (map[tmphead.y][tmphead.x] == 0) // 빈자리이면
		{
			map[snake[tail].y][snake[tail].x] = 0;
			snake.push_front({ tmphead.y,tmphead.x });
			map[tmphead.y][tmphead.x] = 2;
			head = 0;
			snake.erase(snake.end()-1); //tail은 추가하고 지우니까 그대로
		}

	}

	if (moveinfo[index].direction == 'D')
	{
		direction++;
		if (direction == 4)
		{
			direction = 0;
		}
	}
	else
	{
		direction--;
		if (direction == -1)
			direction = 3;
	}

	move(direction, index + 1,moveinfo[index].sec);
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &k);

	int i, j;
	map.resize(n+2, vector<int>(n+2, 0));

	//사과위치
	for (i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}
	//벽위치
	for (i = 0; i < n+2; i++)
	{
		map[0][i] = 9;
		map[i][0] = 9;
		map[n+1][i] = 9;
		map[i][n+1] = 9;
	}

	//방향변환
	scanf("%d", &l);
	char d; int s;
	for (i = 0; i < l; i++)
	{
		scanf("%d %c", &s, &d);
		moveinfo.push_back({s,d});
	}
	
	map[1][1] = 2; //뱀이 있는 곳은 2이다.
	snake.push_back({ 1,1 });
	head = 0; tail = 0;

	move(0,0,0);

	printf("%d", time);

	system("pause");
}