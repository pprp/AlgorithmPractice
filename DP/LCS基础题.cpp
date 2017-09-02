/*
@theme:�����������
@writer:pprp
@begin:15:37
@end:16��:2
@declare:LCS
@date:2017/9/2
*/

#include <bits/stdc++.h>

using namespace std;

char s1[1010],s2[1010];
int dp[1010][1010];

/*
״̬��ʾ:f(n,m)��ʾs1[0..n]��s2[0..m]
��0��ʼ���������ս����f(N-1,M-1)
�������������
1/ s1[n] == s2[m] : f(n,m) = f(n-1,m-1)+1;
2/ s1[n]��LCS��һ���֣�
3/ s2[m]��LCS��һ���֣�
4/ s1[n]��s2[m]������LCS��һ����
*/

int main()
{
    freopen("in.txt","r",stdin);
    //��0��ʼ
    while(~scanf("%s%s",s1+1,s2+1))
    {
        memset(dp,0,sizeof(dp));

        int n = strlen(s1+1);
        int m = strlen(s2+1);

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}


/*
int main()
{
    freopen("in.txt","r",stdin);
    while(~scanf("%s%s",s1+1,s2+1))
    {
        memset(dp,0,sizeof(dp));
        int i,j;
        for(i = 1; s1[i] ; i++)
        {
            for(j = 1; s2[j]; j++)
            {
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        cout << dp[i-1][j-1] << endl;
    }
}
*/
