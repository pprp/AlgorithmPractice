#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

#define MAXN 100010

int a[MAXN],nex[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,n,m;
        scanf("%d",&n);
        for(i = 1; i<=n; ++i)
        {
            scanf("%d",&a[i]);
        }
        for(i = 1;i<=n;++i)
        {
            nex[i] = -1;
            for(j = i+1;j<=n;++j)
            {
                if(a[j]<=a[i])
                {
                    nex[i] = j;
                    break;
                }
            }
        }
        scanf("%d",&m);
        for(i = 0;i<m;++i)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int num = a[l];
            for(j = nex[l];j<=r;j = nex[j])
            {
                if(j == -1)
                {
                    break;
                }
                num%=a[j];
            }
            printf("%d\n",num);
        }
    }
    return 0;
}
