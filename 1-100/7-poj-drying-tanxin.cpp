#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int MAXN = 100000 + 100;
int a[MAXN];
int r,l,mid;
int k;


//judge in X times , if you can dry all this cloth
bool check(int X)
{
    int now = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] > X)
        {
            now += (a[i]-X-1)/(k-1)+1;
            if(now > X)
                return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    l=r=0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(r < a[i])
            r = a[i];
    }

    cin >> k;
    if(k == 1)
        cout << r << endl;
    else
    {
        while(l <= r)
        {
            mid = (l+r)/2;
            if(check(mid))
                r = mid-1;
            else
                l = mid+1;
        }
        cout << l << endl;
    }
    return 0;
}
