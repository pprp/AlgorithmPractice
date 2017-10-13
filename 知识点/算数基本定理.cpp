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
        ll n;
        cin >> n;
        ll five = 5;
        ll sum = 0;
        while(five < n)
        {
            sum += n/five;
            five *= 5;
        }
        cout << sum << endl;
    }
    return 0;
}
