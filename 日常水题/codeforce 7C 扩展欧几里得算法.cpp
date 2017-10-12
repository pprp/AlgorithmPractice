#include <iostream>

using namespace std;
typedef long long ll;

ll ex_gcd(ll a, ll b, ll&x, ll&y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ans = ex_gcd(b,a%b,x,y);
    int tmp = x;
    x = y;
    y = tmp - a/b * y;
    return ans;
}
int main()
{
    ll x, y;
    ll a, b, c;
    cin >> a >> b >> c;
    c *= -1;
    ll gcd =  ex_gcd(a,b,x,y);
    if(c%gcd)
    {
        cout << "-1" << endl;
    }
    else
    {
        int k = c/gcd;
        x *= k;
        y *= k;
        cout << x << " " << y << endl;
    }

    return 0;
}
