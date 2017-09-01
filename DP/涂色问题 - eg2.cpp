/*
@param:dp 入门
@writer:pprp
@declare:最经典最简单的dp，给红绿蓝三种颜色，让你求出蓝绿不相邻的排列n个元素的情况
@begin:10:10
@end:10:28
@date:2017/9/1
*/

#include <bits/stdc++.h>

using namespace std;

/*
状态确定：按照最后一位的颜色确定状态
f(n,0):最后一位是红色的数量
f(n,1):最后一位是绿色的数量
f(n,2):最后一位是蓝色的数量
状态转移：
f(n,0) = f(n-1,0) + f(n-1,1) + f(n-1,2)
f(n,1) = f(n-1,0) + f(n-1,1)
f(n,2) = f(n-1,0) + f(n-1,2)
初始条件：
f(1,0) = 1;
f(1,1) = 1;
f(1,2) = 1;
最终答案：
f(n,0) + f(n,1) +ｆ(n,2);
*/

// top down
int dp1[101][3] = {0};

void init()
{
    dp1[1][0] = dp1[1][1] = dp1[1][2] = 1;
}

int fun(int n,int m)
{
    if(dp1[n][m] != 0)
        return dp1[n][m];

    if(m == 0) dp1[n][0] = fun(n-1,0) + fun(n-1,1) + fun(n-1,2);
    if(m == 1) dp1[n][1] = fun(n-1,0) + fun(n-1,1);
    if(m == 2) dp1[n][2] = fun(n-1,0) + fun(n-1,2);

    return dp1[n][m];
}

//bottom up
int dp2[101][3] = {3};
int build()
{
    dp2[1][0] = dp2[1][1] = dp2[1][2] = 1;
    for(int i = 2; i < 101 ; i++)
    {
        dp2[i][0] = dp2[i-1][0] + dp2[i-1][1] + dp2[i-1][2];
        dp2[i][1] = dp2[i-1][0] + dp2[i-1][1];
        dp2[i][2] = dp2[i-1][0] + dp2[i-1][2];
    }
}
int fun2(int n)
{
    return dp2[n][0] + dp2[n][1] + dp2[n][2];
}

//run
int main()
{
    int a;
    cin >> a;
    init();
    build();

    cout << fun(a,0) + fun(a,1) + fun(a,2) << endl;
    cout << fun2(a) << endl;
    return 0;
}
