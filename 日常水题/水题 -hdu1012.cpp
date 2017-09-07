/*
@theme: hdu 1012 u calculate e
@writer:pprp
@begin:21:31
@end:21:47
@error:前几个应该特别的输出
@date:2017/9/7
*/

#include <bits/stdc++.h>

using namespace std;
int dp[10];
void build()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i < 10; i++)
    {
        dp[i] = dp[i-1] * i;
    }
}

int main()
{
    build();
//    for(int i = 0 ; i < 10 ;i++)
//    cout << dp[i] << endl;
    double ans;

    cout << "n e" << endl;
    cout << "- -----------" << endl;
    cout << "0 1" << endl;
    cout << "1 2" << endl;
    cout << "2 2.5" << endl;
    for(int i = 3 ; i < 10 ; i++)
    {
        ans = 0.0;
        for(int j = 0; j <= i; j++)
        {
            ans += 1.0/dp[j];
        }
        cout << i << " " ;
        printf("%.9lf\n",ans);
    }
    return 0;
}
