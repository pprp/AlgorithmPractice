/*
@theme:hdu1257
@writer:pprp
@begin:17:13
@end:17:
@declare:LIS的裸题,温习一下
@error:
@date:2017/9/2
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
int arr[maxn];
int tmp[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int N,len = 0;
    while(cin >> N)
    {
        len = 1;
        cin >> arr[0];
        tmp[len] = arr[0];
        for(int i = 1 ; i < N ; i++)
        {
            cin >> arr[i];
            if(arr[i] > tmp[len])
            {
                len++;
                tmp[len] = arr[i];
            }
            else
                *lower_bound(tmp,tmp+len,arr[i]) = arr[i];
        }
        cout << len << endl;
    }

    return 0;
}
