//
// Created by thdeh on 2019-04-01.
//

#include <cstdio>
#include <cstring>

int N;
char board[100][100];
bool visited[100][100];
int bd[100][100];

int cnt=0;
char area;
int now=1;
int now_again=1;
int answer=0;
int dx[4] = {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

void dfs(int row, int col, int bd_num);
void findArea();

int main(void)
{
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++)
            scanf("%c", &board[i][j]);
        getchar();
    }

    findArea();

    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            if (now < bd[i][j]) {
                now = bd[i][j];
            }
        }
    }

    printf("%d", now);


    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(board[i][j]=='G')
                board[i][j]='R';
        }
    }

    memset(visited, false, sizeof(visited));

    cnt=0;

    findArea();

    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            if (now_again < bd[i][j]) {
                now_again = bd[i][j];
            }
        }
    }

    printf(" %d", now_again);

    return 0;
}

void findArea(){
    int bd_num=1;
    while(cnt!=N*N) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    area = board[i][j];
                    visited[i][j] = true;
                    bd[i][j]=bd_num;
                    dfs(i, j, bd_num);
                    cnt++;
                    bd_num++;
                }
            }
    }
}

void dfs(int row, int col, int bd_num) {

    if(row>=0 && row<=N-1 && col>=0 && col<=N-1)
    {
        for(int i=0; i<4; i++)
        {
            if(row+dx[i]>=0 && row+dx[i]<=N-1 && col+dy[i]>=0 && col+dy[i]<=N-1) {
                if (!visited[row + dx[i]][col + dy[i]]) {
                    if (board[row + dx[i]][col + dy[i]] == area) {
                        visited[row + dx[i]][col + dy[i]] = true;
                        bd[row + dx[i]][col + dy[i]] = bd_num;
                        cnt++;
                        dfs(row + dx[i], col + dy[i], bd_num);
                    }
                }
            }
        }
    }
}