/*
@param:dp 入门
@writer:pprp
@declare:最经典最简单的dp，给你一个正整数阵列，
从里边取出不相邻的数，问你取出数字和最大为多少？
@begin:1:05
@end:11:25
@error:应该是从1开始不是从0开始
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

/*
状态分析：
f(n)代表的是当前取了这个位置以后的最大数字和
状态转移：
f(n) = max(f(n-2),f(n-3) + arr[n];
边界状态：f(0) = 0, f(1) = arr[1], f[2] = max(arr[1],arr[2])
*/

//top down
int arr[101] = {};
int dp[110] = {};

void init()
{
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = max(arr[1],arr[2]);
    dp[3] = max(arr[1]+arr[3],arr[2]);
}

int fun(int n)
{
    init();
    if(dp[n] != 0)
        return dp[n];
    dp[n] = max(fun(n-2),fun(n-3)) + arr[n];
    return dp[n];
}

int dp2[110] = {};
//bottom up
void build()
{
    dp2[0] = 0;
    dp2[1] = arr[1];
    dp2[2] = max(arr[1],arr[2]);

    for(int i = 3; i < 101 ; i++)
    {
        dp2[i] = max(dp2[i-2],dp2[i-3]) + arr[i];
    }
}

int fun2(int n)
{
    return dp2[n];
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> arr[i];

    init();
    build();

    cout << max(fun(4),fun(5)) << endl;
    cout << max(fun2(4),fun2(5)) << endl;
    return 0;
}

