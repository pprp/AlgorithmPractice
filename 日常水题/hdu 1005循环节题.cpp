/*
@theme: Number suquence
@writer:pprp
@begin:19:55
@end:20:22
@declare:简单递归竟然不可以！！！
@error:
@data:2017/9/6
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 49;
int a, b;
int dp[MAXN];


int fun(long long n)
{
    for(int i = 3; i < MAXN; i++)
        dp[i] = (a * dp[i-1] + b * dp[i-2] )% 7;
    return dp[n % MAXN];
}

int main()
{
    //freopen("in.txt","r",stdin);
    memset(dp,0,sizeof(dp));
    dp[1] = dp[2] = 1;
    long long n;
    while( cin >> a >> b >> n)
    {
        if(a==0&&b==0&&n==0)
            break;
        cout << fun(n) << endl;
    }
    return 0;
}
