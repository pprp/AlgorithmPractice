/*
@theme:1010
*/
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 100000;
int arr[maxn];
bool vis[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int cas, len;
    cin >> cas;
    while(cas--)
    {
        cin >> len;
        for(int i = 0; i < len ; i++)
        {
            vis[i] = 1;
            cin >> arr[i];
        }

        for(int i = 0 ; i < len ; i++)
        {
            if(i == 0)
            {
                if(arr[i] > arr[i+1])
                    vis[i] = 0;
                continue;
            }
            if(i == len-1)
            {
                if(arr[i] < arr[i-1])
                    vis[i] = 0;
                continue;
            }
            if(arr[i] > arr[i+1] || arr[i] < arr[i-1])
                vis[i] = 0;
        }
        int cnt = 0;
        for(int i = 0 ; i < len; i++)
            if(vis[i] == 1)
            {
                cnt++;
            }

        if(cnt == 0)
        {
            cout << 0 << endl << endl;
        }
        else
        {
            cout << cnt << endl;
            for(int i = 0 ; i < len ; i++)
            {
                if(vis[i] == 1)
                    cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
