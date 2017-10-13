//¸çµÂ°ÍºÕ²ÂÏë
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
bool isprime[10000000];
int main()
{
    memset(isprime,1,sizeof(isprime));
    isprime[0] = isprime[1] = false;

    for(int i = 4; i <= 10000000 ; i = i+2)
        isprime[i] = false;
    for(int i = 3; i <= sqrt(10000000); i+=2)
    {
        if(isprime[i])
            for(int j = i+i; j <= 10000000; j+=i)
            {
                isprime[j] = false;
            }
    }
    int n;
    while(cin >> n)
    {
        int t = 0;
        for(int i = 2 ; i <= n/2; i++)
        {
            if(isprime[i]&&isprime[n-i])
                t++;
        }
        cout << t << endl;
    }
    return 0;
}
