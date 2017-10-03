#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 10000;
int prime[MAXN+1];
void getprime()
{
    memset(prime,0,sizeof(prime));
    for(int i = 2; i <= MAXN; i++)
    {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0] &&prime[j] <= MAXN/i; j++)
        {
            prime[prime[j]*i] = 1;
            if(i%prime[j] == 0)
                break;
        }
    }
}
long long factor[100][2];
int fatcnt;
//最终处理结果为 factor[i][0] ^ factor[i][1]
int getFactors(long long x)
{
    fatcnt = 0;
    long long tmp =x;
    for(int i = 1; prime[i] <= tmp/prime[i] ; i++)
    {
        factor[fatcnt][1] = 0;
        if(tmp%prime[i] == 0)
        {
            factor[fatcnt][0] = prime[i];
            while(tmp%prime[i] == 0)
            {
                factor[fatcnt][1]++;
                tmp /= prime[i];
            }
            fatcnt++;
        }
    }
    if(tmp != 1)
    {
        factor[fatcnt][0] = tmp;
        factor[fatcnt++][1] = 1;
    }
    return fatcnt;
}
int main()
{
    getprime();
    int cnt = getFactors(10000);
    for(int i = 0;i < cnt ; i++)
    {
        cout << factor[i][0] << " " << factor[i][1] << endl;
    }
    return 0;
}
