#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 20;

int board[MAX][MAX];
int N;
int answer=0;
queue<int> q;

void move_left();
void move_right();
void move_up();
void move_down();
void dfs(int cnt);

int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            scanf("%d", &board[i][j]);
    }

    dfs(0);

    printf("%d", answer);
    return 0;
}

void dfs(int cnt){
    if(cnt==5) {
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                answer = max(answer, board[i][j]);
            return;
    }

    int copyBoard[MAX][MAX];

memcpy(copyBoard, board, sizeof(int)*400);

    for(int i=0; i<4; i++)
    {
        switch(i){
            case 0: move_left(); break;
            case 1: move_right(); break;
            case 2 : move_up(); break;
            case 3 : move_down(); break;
        }
        dfs(cnt+1);

        memcpy(board, copyBoard, sizeof(int)*400);
    }
}


void move_left() {

    //왼쪽이동후
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++) {
            if (board[row][col] == 0 && col != N - 1) {
                for (int j = col + 1; j < N; j++) {
                    if (board[row][j] != 0) {
                        board[row][col] = board[row][j];
                        board[row][j] = 0;
                        break;
                    }
                }
            }
        }
    }


    //합침
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N-1; col++)
        {
            if(board[row][col] == board[row][col+1]) {
                board[row][col] *= 2;
                //왼쪽정렬
                for(int j=col+1; j<N-1; j++)
                    board[row][j]=board[row][j+1];
                board[row][N-1]=0;
            }
        }
    }


}

void move_right() {


    //오른쪽이동후
    for(int row=N-1; row>=0; row--) {
        for (int col = N - 1; col >= 0; col--) {
            if (board[row][col] == 0 && col != 0) {
                for (int j = col - 1; j >= 0; j--) {
                    if (board[row][j] != 0) {
                        board[row][col] = board[row][j];
                        board[row][j] = 0;
                        break;
                    }
                }
            }
        }
    }


    //합침
    for(int row=N-1; row>=0; row--)
    {
        for(int col=N-1; col>0; col--)
        {
            if(board[row][col] == board[row][col-1]) {
                board[row][col] *= 2;
                //오른정렬
                for(int j=col-1; j>0; j--)
                {
                    board[row][j] = board[row][j-1];
                }
                board[row][0]=0;
            }
        }
    }



}

void move_up() {


    //위쪽이동후 0 0
    for(int col=0; col<N; col++)
    {
        for(int row=0; row<N; row++)
        {
            if(board[row][col] == 0 && row != N-1) {
                for(int i=row+1; i<N; i++) {
                    if(board[i][col] != 0) {
                        board[row][col] = board[i][col];
                        board[i][col]=0;
                        break;
                    }
                }
            }
        }
    }


    //합침
    for(int col=0; col<=N-1; col++)
    {
        for(int row=0; row<N-1; row++)
        {
            if(board[row][col] == board[row+1][col]) {
                board[row][col] *= 2;
                //위쪽정렬
                for(int i=row+1; i<N-1; i++) {
                    board[i][col] = board[i+1][col];
                }
                board[N-1][col]=0;
            }
        }
    }

}

void move_down() {

    //아래
    for(int col=N-1; col>=0; col--)
    {
        for(int row=N-1; row>0; row--)
        {
            if(board[row][col]==0 && row!=0) {
                for(int i=row-1; i>=0; i--)
                {
                    if(board[i][col]!=0) {
                        board[row][col] = board[i][col];
                        board[i][col] = 0;
                        break;
                    }

                }
            }
        }
    }

    //합침
    for(int col=N-1; col>=0; col--)
    {
        for(int row=N-1; row>0; row--)
        {
            if(board[row][col] == board[row-1][col]) {
                board[row][col] *= 2;

                for(int i=row-1; i>0; i--)
                    board[i][col] = board[i-1][col];
                board[0][col]=0;
            }
        }
    }

}