/*
@param:dp 入门
@writer:pprp
@declare:最经典最简单的dp， 给你2*1 & 3*1 L型骨牌填满2*n的格子，有几种拍法
@begin:10:36
@end:11:00
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

/*
状态分析：
f(n) 代表的是放n*2个格子时候的方法数
状态转移：
如果最后那块放2*1的：f(n) = f(n-1) + f(n-2)
如果最后那块放3*1的：f(n) = f(n-3) + f(n-4) + ... + f(0)，由于对称的关系，要乘2
综合起来： f(n) = f(n-1) + f(n-2) + 2 * (f(n-3) + f(n-4) +...+ f(0))
边界状态：f(0) = 1; f(1) = 1; f(2) = 2;
*/

//top down
int dp[101] = {0};
void init()
{
    dp[0] = dp[1] = 1;
    dp[2] = 2;
}
int fun(int n)
{
    init();
    if(dp[n] != 0) return dp[n];
    dp[n] = 2 * fun(n-1) + fun(n-3);
    return dp[n];
}

//bottom up
int dp2[101] = {};

void build()
{
    dp2[0] = dp2[1] = 1;
    dp2[2] = 2;

    for(int i = 3 ; i < 101 ; i++)
        dp2[i] = 2 * dp2[i-1] + dp2[i-3];
}

int fun2(int n)
{
    return dp2[n];
}

int main()
{
    int a;
    srand((int)time(NULL));
    a = rand()%100;

    build();
    cout << fun(a) << endl;
    cout << fun2(a) << endl;

    return 0;
}
