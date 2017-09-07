/*
@theme: hdu 1013 Digital roots
@writer:pprp
@begin:21:52
@end:21:59
@error:虽然是水题，但是还是需要对最初的处理，如果过大超过了int范围，就出错了
@date:2017/9/7
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while(cin >> str && str != "0")
    {
        long long  n = 0;
        for(int i = 0 ; i < str.length(); i++)
            n += str[i] - '0';
        int ans = 0;
        while(n)
        {
            ans += n%10;
            n /= 10;
            if(n == 0 && ans >= 10)
            {
                n = ans;
                ans = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
