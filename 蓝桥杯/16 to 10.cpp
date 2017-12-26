#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
// 16_to_10

using namespace std;

const int maxn = 10;
char ch[maxn];

long long work()
{
    int len = strlen(ch);
    long long sum = 0;
    for(int i = len-1 ; i >= 0; i--)
    {
        if(ch[i] >= '0' && ch[i] <= '9')
        {
            int record = ch[i] - '0';
            sum += record * pow(16,len-1-i);
        }
        else
        {
            int record = ch[i] - 'A';
            record += 10;
            sum += record * pow(16,len-1-i);
        }
    }
    return sum;
}

int main()
{
    scanf("%s",ch);
    long long ans = work();
    printf("%lld",ans);
    return 0;
}
