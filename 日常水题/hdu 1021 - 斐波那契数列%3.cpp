#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
int F[1000000+10];

void process()
{
    memset(F,0,sizeof(F));
    F[0] = 7%3, F[1] = 11%3;
    for(int i = 2 ; i < 1000000 ; i++)
    {
        F[i] = (F[i-1]%3+F[i-2]%3)%3;
    }
}

int main()
{
    process();
    int n;
    while(cin >> n)
    {
        if(F[n])
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}
