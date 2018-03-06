#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;

int main()
{
	int t = 10;
	while (t--)
	{
		system("cmp > test.in");
		system("aaa < test.in > 1.out");
		system("bbb < test.in > 2.out");
		if (system("fc 1.out 2.out")) break;
	}
	system("pause");
	return 0;
}

