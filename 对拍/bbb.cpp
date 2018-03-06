#include<cstdio>
#include<iostream>
using namespace std;

typedef long long LL;

LL n,m,k;

LL mi(LL x,LL y)
{
	LL ret = 1,now = x;
	for (; y; y >>= 1)
	{
		if (y & 1) ret = ret * now % m;
		now = now * now % m;
	}
	return ret;
}

int main()
{
	cin >> n >> m >> k;
	cout << mi(n,k);
	return 0;
}

