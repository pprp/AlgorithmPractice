#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;
int main()
{
    int cas;
    cin >> cas;
    while(cas--)
    {
        ll n,p;
        ll ans = 0;
        cin >> n >> p;
        ll tmpp = p;
        while(tmpp <= n)
        {
            ans += n/tmpp;
            tmpp *= p;
        }

        ll ans1 = 0;
        tmpp = p;
        while(tmpp <= 2*n)
        {
            ans1 += 2*n/tmpp;
            tmpp *= p;
        }
        cout << ans1-2*ans << endl;
    }
    return 0;
}
