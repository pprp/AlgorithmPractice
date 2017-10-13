#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;

ll multi(ll a, ll b, ll m)
{
    ll ret = 0;
    while(b>0)
    {
        if(b&1)
        {
            ret = (ret+a)%m;
        }
        b >>= 1;
        a = (a<<1)%m;
    }
    return ret;
}
int main()
{
    ll sum = 1, data[66], tmp;
    int n, p;
    data[1] = 4;
    cin >> n;
    while(n--)
    {
        sum = 1;
        cin >> p;
        sum <<= p;
        sum -= 1;
//        cout << sum << endl;
        for(int i = 2; i <= p-1; i++)
        {
            tmp = multi(data[i-1],data[i-1],sum);
            data[i] = (tmp-2)%sum;
        }
        if(p == 2)
            cout << "yes" << endl;
        else
        {
            if(data[p-1] == 0)
                cout << "yes" <<endl;
            else
                cout << "no" << endl;
        }
    }
    return 0;
}
