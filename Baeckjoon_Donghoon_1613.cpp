//
// Created by thdeh on 2019-04-02.
//

#include <cstdio>
#include <cstring>

int n;
int k;
int s;
int pre_post[401][401];

using namespace std;

int main(void)
{
        int a, b;

        scanf("%d %d", &n, &k);

        memset(pre_post, 0, sizeof(pre_post));

        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&a, &b);
            pre_post[a][b] = 1;
            pre_post[b][a]=-1;
        }

        for(int j=1; j<=n; j++)
        {
            for(int i=1; i<=n; i++)
            {
                for (int c = 1; c <=n; c++)
                {
                    if (pre_post[i][j] == 1 && pre_post[j][c]==1) {
                        pre_post[i][c] = 1;
                        pre_post[c][i]=-1;
                    }
                }
            }
        }

        scanf("%d", &s);

        while(s--)
        {
            scanf("%d %d", &a, &b);
            if(pre_post[a][b]==0)
                printf("0");
            else if(pre_post[a][b]==-1)
                    printf("1");
            else if(pre_post[a][b]==1)
                    printf("-1");

            if(s!=0)
                printf("\n");
        }

    return 0;
}