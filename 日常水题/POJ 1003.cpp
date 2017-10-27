#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    double target;
    while(cin >> target && target != 0.00)
    {
        int i;
        double sum = 0;
        for(i = 1; ; i++)
        {
            sum += 1.0/(i+1);
            if(sum >= target)
                break;
        }
        cout << i << " card(s)" << endl;
    }
    return 0;
}
