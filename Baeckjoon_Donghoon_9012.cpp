//
// Created by thdeh on 2019-04-10.
//

#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
stack<char> s;
int T;
int count=0;

int main(void)
{
    char temp='a';
    char result='a';
    //int temp=0;
    cin >> T;
    while(T--)
    {
        cin >> temp;
        if(temp=='(') {
            s.push(temp);
            count++;
        }
        else {
            result = s.top();
            s.pop();
        }
    }
}