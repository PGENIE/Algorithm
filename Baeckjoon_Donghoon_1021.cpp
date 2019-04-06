//
// Created by thdeh on 2019-04-06.
//

#include <cstdio>
#include <queue>
int N, M;
int answer=0;
using namespace std;

queue<int> q;
deque<int> d;

void rotate_left() {
    int ft = d.front();
    d.pop_front();
    d.push_back(ft);
    answer++;
}

void rotate_right() {
    int bc = d.back();
    d.pop_back();
    d.push_front(bc);
    answer++;
}

int main() {
    int temp;
    int i=1;
    scanf("%d %d", &N, &M);
    while(M--)
    {
        scanf("%d", &temp);
        q.push(temp);
    }
    while(N--)
    {
        d.push_back(i++);
    }

    while(!q.empty())
    {
        int ob = q.front();
        q.pop();
        for(int i=0; i<d.size(); i++)
        {
            if(d[i]==ob)
            {
                if(i==0)
                {
                    break;
                }
                else if(i > d.size()-i)
                {
                    while(d[0]!=ob)
                        rotate_right();
                }
                else {
                    while (d[0]!= ob)
                        rotate_left();

                }

                break;
            }
        }
        d.pop_front();
    }

    printf("%d", answer);
}