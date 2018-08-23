#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 * 2 + 200;
int n;
int a[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin >>n;
    for(int i = 0; i <n ; i++)
    {
        cin >> a[i];
    }

    sort(a,a+n);
    int qc = unique(a,a+n) - a;

    int ans = 0;

    for(int i = 0 ; i < qc ; i++)
    {
        for(int j = a[i] ; j <= a[qc-1]; j+=a[i])
        {
            int x = lower_bound(a+i,a+qc,j+a[i]) - a;
            ans = max(a[x] % a[i],ans);

        }
    }
    cout << ans;



    return 0;
}
