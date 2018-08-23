#include <iostream>
using namespace std;
const long long M = 1000000007;
const long long MAXL = 1000000;

long long a[MAXL];

long long Q(int n, long long t)
{
    if(n<0)
        return t;
    return(Q(n-1,t)+Q(n-1,(t*a[n]%M)))%M;
}

int main()
{
    int n;
    while(cin >> n){
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
            a[i] %= M;
        }
        cout << Q(n-1,1) << endl;
    }
    return 0;
}
