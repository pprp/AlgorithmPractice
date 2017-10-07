/*
@theme:51nod 加农炮
@writer:pprp
@begin:16:00
@end:16：17
@declare:暴力求解
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdiO>

using namespace std;
int M, N;
int h[1000000];

int main()
{
    freopen("in.txt","r",stdin);
    memset(h,0,sizeof(h));
    cin >> M >> N;
    int maxh = -100;
    for(int i = 0 ; i < M ; i++)
    {
        cin >> h[i];
        if(maxh < h[i])
        {
            maxh = h[i];
        }
    }
    int cmp;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> cmp;
        if(cmp <= h[0] || cmp > maxh)
            continue;
        for(int j = 0 ; j < M ; j++)
        {
            if(h[j] >= cmp)
            {
                h[j-1]++;
                break;
            }
        }
    }
    for(int i = 0 ; i < M ; i++)
    {
        cout << h[i] << endl;
    }

    return 0;
}
