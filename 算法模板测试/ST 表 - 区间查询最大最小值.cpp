#include <bits/stdc++.h>

using namespace std;

int F[1000000][20];
void ST(int a[],int len)
{
    for(int i = 0 ; i < len ; i++)
        F[i][0] = a[i];
    int nlog = int(log(double(len))/log(2.0));
    for(int j = 1; j <= nlog; j++)
    {
        for(int i = 0 ; i < len ; i++)
        {
            if(i+(1<<j)-1 < len)
                F[i][j] = max(F[i][j-1],F[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQ(int a[],int len, int l, int r)
{
    int nlog = floor(log(double(r-l+1))/log(2.0));
    return max((F[l][nlog]),F[r-(1<<nlog)+1][nlog]);
}

int main()
{
    int a[10000];
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    ST(a,n);
    int l,r;
    int cas;
    cin >> cas;
    while(cas--)
    {
        cin >> l >> r;
        cout << RMQ(a,n,l,r) << endl;
    }

    return 0;
}
