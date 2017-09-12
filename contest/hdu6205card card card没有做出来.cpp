/*
@theme:card card card
@writer:pprp
@date:2017/9/11
@begin:19:08
@end:
*/
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000005;
struct PAIR
{
    int a, b;
    int sub;
};
vector<PAIR> vt;

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    int n, tmp;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin >> tmp;
        PAIR temp;
        temp.a = tmp;
        vt.push_back(temp);
    }
    for(int i = 0 ; i < n ; i++)
    {
        cin >> tmp;
        vt[i].b = tmp;
        vt[i].sub = vt[i].a - vt[i].b;
    }
    int cnt = 0;
    int Max = -1;
    int rec_cnt = 0;
    for(int i = 0; i < n+1; i++) //进行枚举的次数
    {
        int sum_sub = 0, sum_score = 0;
        int j;
        cnt++;
        for(j = 0 ; j < n ; j++)
        {
            sum_sub += vt[j].sub;
            sum_score += vt[j].a;
            if(sum_sub < 0)
            {
                if(Max <= sum_score)
                {
                    Max = sum_score;
                    rec_cnt = cnt;
                }
                break;
            }
        }
        if(j == n)
            if(Max <= sum_score)
            {
                Max = sum_score;
                rec_cnt = cnt;
            }
//cout << sum_score << " " << cnt  << endl;

        //开始旋转
        PAIR tmp2 = vt.front();
        vt.erase(vt.begin());
        vt.push_back(tmp2);
    }
    cout << rec_cnt << endl;

    return 0;
}
