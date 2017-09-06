/*
@theme:Max Sum
@writer:pprp
@end:21:26
@declare:连续区间最大和
@data:2017/9/6
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    cin >> cas;
    for(int l = 1; l <= cas; l++)
    {
        int n;
        cin >> n;
        int tmp = 0, ans = -999, data2;
        int op = 1, ed = 1, k = 1;

        for(int i = 1 ; i <= n ; i++)
        {
            cin >> data2;
            tmp += data2;

            if(ans < tmp)
            {
                ans = tmp;
                ed = i;
                op = k;
            }if(tmp < 0)
            {
                tmp = 0;
                k = i + 1;
            }
        }
        if(l != 1)
            cout << endl;

        cout << "Case " << l << ":" << endl;

        cout << ans << " " << op <<  " " << ed << endl;
    }

    return 0;
}
