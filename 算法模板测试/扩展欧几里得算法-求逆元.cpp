/*
扩展欧几里得算法
求解ax+by = gcd 的解以及其逆元
*/

#include <iostream>

using namespace std;
//返回d = gcd(a,b),和对应等式中的x和y
long long extend_gcd(long long a,long long b,long long&x,long long &y)
{
    if(a == 0&& b == 0)return -1;
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    long long d = extend_gcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}

//求逆元素
//ax = 1(mod m)
long long mod_reverse(long long a, long long n)
{
    long long x,y;
    long long d = extend_gcd(a,n,x,y);
    if(d == 1)
        return (x%n+n)%n;
    else
        return -1;
}

int main()
{
    long long  x, y;
    cout << extend_gcd(3,3,x,y) << endl;
    cout << x << " " << y << endl;

    cout << mod_reverse(2,3) << endl;
    return 0;
}
