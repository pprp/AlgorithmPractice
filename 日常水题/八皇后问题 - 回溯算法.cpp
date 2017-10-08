/*
@theme:搜索入门：回溯算法 - 八皇后问题
@writer：pprp
@declare:
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int num;
int sum;
int * x;

bool place(int k)
{
    for(int i = 1 ; i < k ; i++)
    {
        if(abs(x[k]-x[i]) == abs(k-i)||x[i] == x[k])
            return false;
    }
    return true;
}

void backtrack(int t)
{
    if(t > num)
    {
        sum++;
        for(int i = 1; i <= num ; i++)
        {
            cout <<'('<< i <<',' << x[i] << ')';
        }
        cout << endl;
    }
    else
        for(int i = 1; i <= num ; i++)
        {
            x[t] = i;
            if(place(t))
                backtrack(t+1);
        }
}

int main()
{
    num = 12;
    sum = 0;
    x = new int[num+1];
    for(int i = 0; i <= num ; i++)
        x[i] = 0;
    backtrack(1);
    cout << sum << endl;
    delete []x;
    return 0;
}
