/*
@theme: hdu1008 Elevator
@writer:pprp
@begin:21:37
@end:19:30
@declare:Ë®Ìâ
@data:2017/9/7
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(cin >> n && n)
    {
        int before = 0,now = 0;
        int ans = 0;

        for(int i = 0; i < n ; i++)
        {
            cin >> now;
            if(now > before)
            {
                ans += 6 * (now - before);
            }
            else
            {
                ans += 4 * (before - now);
            }
            before = now;
        }
        ans += 5 * n;
        cout << ans << endl;
    }
    return 0;
}
