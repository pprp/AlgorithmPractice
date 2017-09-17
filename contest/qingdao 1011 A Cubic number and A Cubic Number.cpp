#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;
const ll maxn = 1e12 + 1000;
ll x,y;

int main()
{
   ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    int cas;
    cin >> cas;
    while(cas--)
    {
        bool tag = 0;
        cin >> x;
        if((x - 1) % 3 == 0)
        {
            ll pprp = (x-1)/3;
            ll tmp = sqrt(pprp);
            for(ll i = 1 ; i <= tmp ; i++)
            {
                if(i * i + i == pprp)
                {
                    tag = 1;
                    break;
                }
            }
        }
        if(tag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }
    return 0;
}
