#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
const int maxn = 10000;
LL a[maxn];
int n;
//返回row的值
int xorGauss()//可以用来解模二的方程，加快速度
{
    int row = 0;
    for (int i = 63; i >= 0; i--)
    {
        int j;
        for (j = row; j < n; j++)
            if(a[j]&((LL)1<<i))
                break;
        if (j != n)
        {
            swap(a[row], a[j]);
            for (j = 0; j < n; j++)
            {
                if(j == row) continue;
                if(a[j]&((LL)1<<i))
                    a[j] ^= a[row];
            }
            row++;
        }
    }
    return row;
}
LL findK(int row, int k)
{
    if(row < n)
    {
        if(k == 1)
            return 0;
        else
            k--;
    }
    if(k >= (LL)1<<row)
    {
        return -1;
    }
    LL ans = 0;
//    把k二进制拆开来后，第i位就表示第i小的向量基取不取（1取，0不取）。
    for(int i = 0 ; i < 64; i++)  //  bu tai dong
    {
        if(k&(LL)1<<i)
        {
            ans ^= a[row-1-i];
        }
    }
    return ans;
}
void input()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}
void work()
{
    int row, q;
    LL k, ans;
    row = xorGauss();
    cin >> q;
    for(int i = 0 ; i < q; i++)
    {
        cin >>k;
        ans = findK(row,k);
        cout << ans << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    for(int times = 0; times < T; times++)
    {
        printf("Case #%d:\n", times+1);
        input();
        work();
    }
    return 0;
}
