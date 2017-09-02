/*
@theme:hdu1159
@writer:pprp
@begin:17:01
@end:17:06
@declare:LCS的裸题,温习一下
@error:从1开始读入的话，用strlen也要从1开始测才可以
@date:2017/9/2
*/

#include <bits/stdc++.h>

using namespace std;

char s1[1010],s2[1010];
int dp[1010][1010];
int main()
{

    //freopen("in.txt","r",stdin);
    while(~scanf("%s%s",s1+1,s2+1))
    {
        memset(dp,0,sizeof(dp));
        int n = strlen(s1+1);
        int m = strlen(s2+1);

        for(int i = 1; i <= n ;i++)
        {
            for(int j = 1; j <= m ; j++)
            {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}
