//
// Created by thdeh on 2019-04-12.
//

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];
int arr[9];
vector<int> v;

void dfs() {
    if(v.size() == M) {
        for(int i=0; i<M; i++)
            printf("%d ", v[i]);
        printf("\n");
        return;
    }

    for(int i=1; i<=N; i++)
    {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            dfs();
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main(void) {
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        arr[i]=i;
    dfs();
}