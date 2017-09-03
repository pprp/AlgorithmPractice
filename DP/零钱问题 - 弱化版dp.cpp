/*
@theme:换零钱问题 hdu 1284
@writer:pprp
@begin:17:10
@end:18:53
@declare:1分，2分，3分硬币，将钱N兑换成硬币有很多种兑法
@error:
@date:2017/9/3
*/

#include <bits/stdc++.h>

using namespace std;

int dp[4][40000];

int main()
{
    freopen("in.txt","r",stdin);
    int N;
    memset(dp,0,sizeof(dp));

    dp[0][0] = 1;

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 0 ; j <= 32770; j++)
        {
            dp[i][j] =  dp[i-1][j] + dp[i][j-i];
        }
    }
    while(cin >> N)
    {
        cout << dp[3][N] << endl;
    }

    return 0;
}
