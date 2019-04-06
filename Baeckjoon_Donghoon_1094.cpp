//
// Created by thdeh on 2019-04-06.
//

#include <cstdio>
#include <vector>
using namespace std;


vector<int> v;
int main(){
    int sum=0;
    int X;
    scanf("%d", &X);
    v.push_back(64);

    while(1)
    {
        int len = v.size();
        sum=0;
        for(int i=0; i<len; i++)
        {
            sum+=v[i];
        }
        if(sum==X)
        {
            printf("%d", len);
            break;
        } else if(sum>X)
        {
            int temp = v[len-1];
            temp = temp/2;
            v[len-1]=temp;
            if((sum-temp)<X)
                v.push_back(temp);
        }
    }
}