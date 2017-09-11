#include <iostream>

using namespace std;

int main()
{
    long long m, k;
    while(cin >> m >> k)
        cout << k + (m - k) * k << endl;
}
