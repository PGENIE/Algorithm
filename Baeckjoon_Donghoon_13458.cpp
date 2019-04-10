//
// Created by thdeh on 2019-04-09.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int N, B, C;
//int *A;
//int count = 0;

//int len = 0;

//void dfs(int count, int arr[], long long people);

int main() {
    int A[1000001];
    long long min_people=0;
    scanf("%d", &N);
    //A = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d %d", &B, &C);
    for (int i = 0; i < N; i++) {
        A[i] -= B;
        min_people++;
        if (A[i] <= 0)
            continue;
        else {
            min_people += (A[i] / C);
            if (A[i] % C == 0)
                continue;
            else
                min_people++;
        }
    }

    cout << min_people;

    return 0;
}
