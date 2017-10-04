/*
模线性方程组
中国剩余定理
*/
//模数为m,余数为a (x % m = a)
#include <iostream>
#include <cmath>

using namespace std;

int m[10],a[10];
long long extend_gcd(long long a, long long b, long long &x,long long &y)
{
    if(a == 0 && b == 0)return -1;
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extend_gcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
bool solve(int &m0,int &a0,int m,int a)
{
    long long x, y;
    int g = extend_gcd(m0,m,x,y);
    if((int)(abs(a - a0))%g )
        return false;
    x *= (a-a0)/g;
    x %= m/g;
    a0 = (x * m0 + a0);
    m0 *= m/g;
    a0 %= m0;
    if(a0 < 0)
        a0 += m0;
    return true;
}
/*
有解无解，返回true , false
解的形式：x = a0+m0*t(0 <= a0 < m0)
*/
bool MLES(int &m0,int & a0,int n)
{
    bool flag = true;
    m0 = 1;
    a0 = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(!solve(m0,a0,m[i],a[i]))
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    int sz;
    cin >> sz;
    for(int i =0 ; i < sz; i++)
    {
        cin >> m[i] >> a[i];
    }
    int m0,a0;
    MLES(m0,a0,sz);
    for(int i = 0; i < 3 ; i++)
        cout << a0 + m0* i<< endl;

    return 0;
}
