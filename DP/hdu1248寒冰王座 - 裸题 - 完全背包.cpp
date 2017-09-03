/*
@theme:hdu1248 寒冰王座
@writer:pprp
@begin:16:00
@end:16:14
@declare:完全背包问题
@error:方向问题，这次是从左向右进行扫描
@date:2017/9/3
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 10100;
int dp[maxn];
int w[4] = {0,150,200,350};
int N;

int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    cin >> cas;
    while(cas--)
    {
        memset(dp,0,sizeof(dp));
        cin >> N;
        for(int i = 1; i <= 3 ; i++)
        {
            for(int j = 1 ; j <= N; j++)//error
            {
                if(j >= w[i])//error
                dp[j] = max(dp[j],dp[j-w[i]] + w[i]);
            }
        }
        cout << N - dp[N] << endl;
    }
    return 0;
}
