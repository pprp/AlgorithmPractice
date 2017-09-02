/*
@theme:LIS最长上升子序列
@writer:pprp
@begin:10:00
@end:10:15
@declare复杂度为O(n^2)
@error:dp[i] = MAX(dp[j]+1,dp[i]),dp[i] = 1初始化为1
@date:2017/9/2
*/

#include <bits/stdc++.h>

using namespace std;

/*
未优化的最长上升子序列
f(i)代表从头到i的位置最长上升子序列的长度
if( i < n && arr[i] < arr[n] )
    f(n) = max(f(i))+ 1;
dp[i]是如果取到arr[i]的时候的最长上升子序列
*/

int dp[10010],arr[10010];

int MAX(int a, int b)
{
    return a > b ? a : b;
}
/*
int main()
{
    int N, Max;
    ios::sync_with_stdio(false);
    while(cin >> N && N)
    {
        Max = 0;
        for(int i = 0 ; i < N ; i++)
        {
            dp[i] = 1;
            cin >> arr[i];
            for(int j = 0 ; j < i ; j++)
            {
                if(arr[j] < arr[i])
                    dp[i] = MAX(dp[j]+1,dp[i]);
            }
            Max = MAX(Max,dp[i]);
        }
        cout << Max << endl;
    }
    return 0;
}
*/



int main()
{
    int N;
    while(cin >> N && N)
    {
        int max = 0;
        for(int i = 0 ; i < N ;i++)
        {
            dp[i] = 1;
            cin >> arr[i];
            for(int j = 0 ;j < i ; j++)
            {
                if(arr[j] < arr[i])
                    dp[i] = MAX(dp[j] + 1, dp[i]);
            }
            max = MAX(max,dp[i]);
        }
        cout << max << endl;
    }
    return 0;
}










