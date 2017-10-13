#include <iostream>
#include <cmath>

using namespace std;
const double e = 2.71828;


int main()
{
    int n;
    while(cin >> n)
    {
        cout << (int)(n - log(n)/log(10) - log(log(10)/log(e))/log(10) + 1) << endl;
    }
    return 0;
}
