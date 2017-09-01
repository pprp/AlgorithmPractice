/*
@param:dp 入门
@writer:pprp
@declare:最经典最简单的dp
@begin:9:00
@end:10:00
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

//未优化的最基础的
int fun(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;

    return fun(n-1) + fun(n-2);
}

//自顶向下的记忆化
//top down 小心递回过深
int dp[101] = {1,1,2};
int fun2(int n)
{
    if(dp[n] != 0)
        return dp[n];
    return fun2(n-1) + fun(n-2);
}

//自底向上
//子问题一定要比母问题要先跑到，注意递回跑法
int dp2[101] = {0};
void build()
{
    dp2[1] = 1;
    dp2[2] = 2;
    for(int i = 3 ; i < 101; i++)
     dp2[i] = dp2[i-1] + dp2[i-2];
}
int fun3(int n)
{
    return dp2[n];
}

int main()
{
    build();
    int a;
    while(cin >> a)
    {
        cout << fun(a) << endl;
        cout << fun2(a) << endl;
        cout << fun3(a) << endl;
    }

    return 0;
}
