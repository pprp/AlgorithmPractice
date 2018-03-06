#include<cstdio>
#include<iostream>
using namespace std;

long long n,m,k;

int main()
{
	cin >> n >> m >> k;
	long long sum = 1;
	for (int i = 1; i <= k; i++) sum = sum * n % m;
	cout << sum;
	return 0;
}
