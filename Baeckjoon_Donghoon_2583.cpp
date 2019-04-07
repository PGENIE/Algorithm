//
// Created by thdeh on 2019-04-07.
//

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int board[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int area=1;
int answer=0;
vector<int> v;

void bfs(int x, int y)
{
    if(x<0 || x>N-1 || y<0 || y>M-1 || visited[x][y]==1 || board[x][y]==-1)
        return;

    visited[x][y]=1;
    board[x][y]=area;
    for(int i=0; i<4; i++) {
        bfs(x + dx[i], y + dy[i]);
    }
}
int main(){
    scanf("%d %d %d", &M, &N, &K);

    while(K--)
    {
        int x_left, x_right, y_left, y_right;

        scanf("%d %d %d %d", &x_left, &y_left, &x_right, &y_right);

        for(int i=x_left; i<x_right; i++){
            for(int j=y_left; j<y_right; j++)
                board[i][j]=-1;
        }

    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(!visited[i][j] && board[i][j]!=-1)
            {
                bfs(i, j);
                area++;
            }
        }
    }

    printf("%d\n", area-1);
    for(int k=1; k<area; k++) {
        answer=0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(board[i][j]==k)
                        answer++;
            }
        }
        v.push_back(answer);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
    {
        printf("%d",v[i]);
        if(i!=v.size()-1)
            printf(" ");
    }

}