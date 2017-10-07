/*
@theme: 最基本的线段树
@writer:pprp
@end:17:38
@attention:记录的数组应该从1开始，不能从0开始
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 2000000+50;
const int INF = 0x3f3f3f3f;

struct tree
{
    int nmax,nmin;
    int r,l;
};
tree tt[maxn*3];
int nMax,nMin;

int a[maxn];
void build(int l, int r, int i)
{
    tt[i].l = l;
    tt[i].r = r;
    if(l == r)
    {
        tt[i].nmin = tt[i].nmax = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,2*i);
    build(mid+1,r,2*i+1);
    tt[i].nmin = min(tt[i<<1].nmin,tt[i<<1|1].nmin);
    tt[i].nmax = max(tt[i<<1].nmax,tt[i<<1|1].nmax);
}
void query(int i, int l, int r)
{
    if(tt[i].nmax <= nMax && tt[i].nmin >= nMin)
        return ;
    if(tt[i].l == l && tt[i].r == r)
    {
        nMax = max(tt[i].nmax,nMax);
        nMin = min(tt[i].nmin,nMin);
        return;
    }
    int mid = (tt[i].l+tt[i].r) >> 1;
    if(r <= mid)
        query(i<<1,l,r);
    else if(l > mid)
        query(i<<1|1,l,r);
    else
    {
        query(i<<1,l,mid);
        query(i<<1|1,mid+1,r);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    cin.sync_with_stdio(false);
    int n, q;
    int l, r;
    while(cin >> n >> q)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            cin>>a[i];
        }
        build(1,n,1);
        for(int i = 1; i <= q; i++)
        {
            cin >> l >> r;
            nMax = -INF,nMin = INF;
            query(1,l,r);
//            cout << "__++_+_+_+_" << endl;
//            cout << nMax << endl;
//            cout << nMin << endl;
            cout << nMax-nMin << endl;
        }
    }

    return 0;
}
