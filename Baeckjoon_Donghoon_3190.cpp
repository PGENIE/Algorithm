//
// Created by thdeh on 2019-04-04.
//

#include <cstdio>
#include <queue>
#include <utility>

using namespace std;
int N, K, L;
int board[101][101];
int time = 0;
char now_direction;
bool game_end = false;
queue<pair<int, char>> q;
deque<pair<int, int>> snake;

void snake_move(char now_direction);

int main(void) {
    scanf("%d %d", &N, &K);

    while (K--) {
        int a, b;
        scanf("%d %d", &a, &b);
        board[a][b] = 2; //사과
    }

    scanf("%d", &L);

    while (L--) {
        int a;
        char c;
        scanf("%d %c", &a, &c);

        pair<int, char> p = make_pair(a, c);
        q.push(p);
    }
    pair<int, char> p = make_pair(-1, 'X');
    q.push(p);

    now_direction = 'R';
    board[1][1] = 1;//뱀
    p = make_pair(1, 1);
    snake.push_back(p);
    //1,1짜리뱀

    int time_up = q.front().first;
    char direction = q.front().second;
    q.pop();

    while (!game_end) {
        if (time == time_up && !q.empty()) {
            if (now_direction == 'R') {
                if (direction == 'L')
                    now_direction = 'U';
                else if (direction == 'D')
                    now_direction = 'D';
            } else if (now_direction == 'L') {
                if (direction == 'L')
                    now_direction = 'D';
                else if (direction == 'D')
                    now_direction = 'U';
            } else if (now_direction == 'U') {
                if (direction == 'L')
                    now_direction = 'L';
                else if (direction == 'D')
                    now_direction = 'R';
            } else if (now_direction == 'D') {
                if (direction == 'L')
                    now_direction = 'R';
                else if (direction == 'D')
                    now_direction = 'L';
            }
            time_up = q.front().first;
            direction = q.front().second;
            q.pop();
        }
        snake_move(now_direction);
        time++;
    }
    printf("%d", time);
    return 0;
}

void snake_move(char now_direction) {
    int len = snake.size();
    int temp_x = snake[len - 1].first;
    int temp_y = snake[len - 1].second;
    int pre_x, pre_y;
    bool apple = false;

    switch (now_direction) {
        case 'R':
            //범위 안이면
            if (temp_y + 1 <= N && board[temp_x][temp_y + 1] != 1) {
                if (board[temp_x][temp_y + 1] == 2) {
                    apple = true;
                }
                for (int i = len - 1; i >= 0; i--) {
                    pre_x = snake[i].first;
                    pre_y = snake[i].second;

                    if (i == len - 1) {
                        snake[i].second += 1;

                        board[snake[i].first][snake[i].second] = 1;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    } else {
                        snake[i].first = temp_x;
                        snake[i].second = temp_y;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    }
                }
                //사과 먹으면 길이 1증가 아니면 0처리
                if (apple) {
                    pair<int, int> p = make_pair(pre_x, pre_y);
                    board[pre_x][pre_y] = 1;
                    snake.push_front(p);
                } else {
                    board[pre_x][pre_y] = 0;
                }
            } else {
                game_end = true;
                return;
            }
            break;

        case 'L':
            //범위 안이면
            if (temp_y - 1 >= 1 && board[temp_x][temp_y - 1] != 1) {
                if (board[temp_x][temp_y - 1] == 2) {
                    apple = true;
                }
                for (int i = len - 1; i >= 0; i--) {
                    pre_x = snake[i].first;
                    pre_y = snake[i].second;

                    if (i == len - 1) {
                        snake[i].second -= 1;

                        board[snake[i].first][snake[i].second] = 1;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    } else {
                        snake[i].first = temp_x;
                        snake[i].second = temp_y;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    }
                }
                //사과 먹으면 길이 1증가 아니면 0처리
                if (apple) {
                    pair<int, int> p = make_pair(pre_x, pre_y);
                    board[pre_x][pre_y] = 1;
                    snake.push_front(p);
                } else {
                    board[pre_x][pre_y] = 0;
                }
            } else {
                game_end = true;
                return;
            }
            break;

        case 'U':
            //범위 안이면
            if (temp_x - 1 >= 1 && board[temp_x - 1][temp_y] != 1) {
                if (board[temp_x - 1][temp_y] == 2) {
                    apple = true;
                }
                for (int i = len - 1; i >= 0; i--) {
                    pre_x = snake[i].first;
                    pre_y = snake[i].second;

                    if (i == len - 1) {
                        snake[i].first -= 1;

                        board[snake[i].first][snake[i].second] = 1;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    } else {
                        snake[i].first = temp_x;
                        snake[i].second = temp_y;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    }
                }
                //사과 먹으면 길이 1증가 아니면 0처리
                if (apple) {
                    pair<int, int> p = make_pair(pre_x, pre_y);
                    board[pre_x][pre_y] = 1;
                    snake.push_front(p);
                } else {
                    board[pre_x][pre_y] = 0;
                }
            } else {
                game_end = true;
                return;
            }
            break;

        case 'D':
            //범위 안이면
            if (temp_x + 1 <= N && board[temp_x + 1][temp_y] != 1) {
                if (board[temp_x + 1][temp_y] == 2) {
                    apple = true;
                }
                for (int i = len - 1; i >= 0; i--) {
                    pre_x = snake[i].first;
                    pre_y = snake[i].second;

                    if (i == len - 1) {
                        snake[i].first += 1;

                        board[snake[i].first][snake[i].second] = 1;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    } else {
                        snake[i].first = temp_x;
                        snake[i].second = temp_y;

                        temp_x = pre_x;
                        temp_y = pre_y;
                    }
                }
                //사과 먹으면 길이 1증가 아니면 0처리
                if (apple) {
                    pair<int, int> p = make_pair(pre_x, pre_y);
                    board[pre_x][pre_y] = 1;
                    snake.push_front(p);
                } else {
                    board[pre_x][pre_y] = 0;
                }
            } else {
                game_end = true;
                return;
            }
            break;
    }
}
