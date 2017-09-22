#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 110000;
int arr[maxn];

int main()
{
    int cas;
    cin >> cas;
    while(cas--)
    {
        int n, k;
        cin >> n >> k;
        int ans = 1;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        for(int i = n-1; i > 0 ; i--)
        {
            if(arr[i]-arr[i-1] > k)
                break;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
