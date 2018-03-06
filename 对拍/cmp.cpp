#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	srand(time(0));
	long long a,b,c;
	a = (rand() << 16) + rand();
	b = (rand() << 16) + rand();
	c = (rand() << 16) + rand();
	printf("%lld %lld %lld\n",a,b,c);
	return 0;
}

