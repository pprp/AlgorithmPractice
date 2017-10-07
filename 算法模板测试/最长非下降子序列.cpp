//最长不下降子序列 - 代码模板

#include <iostream>
#include <cstdio>
#include <algorithm>
const int maxn = 100000;
using namespace std;
int a[maxn];
int d[maxn];

int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)//从1开始
        cin >> a[i];
    if(n == 0)
    {
        printf("0\n");
        return 0;
    }
    d[1] = a[1];
    int len = 1;
    for(int i = 2; i <= n ; i++)
    {
        if(a[i] > d[len])
            d[++len] = a[i];
        else
        {
            int j = upper_bound(d+1,d+len+1,a[i]) - d;
            d[j] = a[i];
        }
    }
    printf("%d",len);
    return 0;
}
