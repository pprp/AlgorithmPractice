/*
@theme:hdu1257
@writer:pprp
@begin:17:13
@end:17:26
@declare:LIS的裸题,温习一下
@error:注意题目中说明了是多组数据
@date:2017/9/2
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
int arr[maxn];
int dp[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int N,Max = 0;
    while(cin >> N)
    {
        Max = 0;
        for(int i = 0 ; i < N; i++)
        {
            dp[i] = 1;
            cin >> arr[i];
            for(int j = 0 ; j < i ; j++)
            {
                if(arr[j] < arr[i])
                {
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
            Max = max(Max,dp[i]);
        }
        cout << Max << endl;
    }

    return 0;
}
