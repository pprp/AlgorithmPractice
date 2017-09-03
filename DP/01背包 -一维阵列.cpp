/*
@theme: 01 背包问题 - 一维阵列
@writer:pprp
@begin:14::43
@end:15:30
@declare:最基本的01背包问题 POJ 3624
@error:最后取得是dp[M]不是 dp[M-1],然后注意数据范围dp的数据范围是M的范围
@date:2017/9/3
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 3500;
int w[maxn],v[maxn];
int dp[13000];
int N, M;

int main()
{
    //    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&N,&M))
    {
        for(int i = 1; i <= N ; i++)
        {
            scanf("%d%d",&w[i],&v[i]);
        }
        for(int i = 1 ; i <= N ; i++)
        {
            for(int j = M ; j >= w[i] ; j--)
            {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        printf("%d\n",dp[M]);
        memset(dp,0,sizeof(dp));
    }


    return 0;
}

