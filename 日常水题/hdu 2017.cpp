/*
@theme:日常水题
@writer:pprp
@begin:21:41
@end:21:45
@declare:注意边界条件
@error:取等
@date:2017/9/3
*/

#include <bits/stdc++.h>

using namespace std;
string str;

int main()
{
    freopen("in.txt","r",stdin);

    int cas;
    cin >> cas;
    while(cas--)
    {
        int cnt = 0;
        cin >> str;
        for(int i = 0 ; i < str.size(); i++)
        {
            if(str[i] <= '9' && str[i] >= '0')
                cnt++;
        }
        cout << cnt << endl;
    }
}
