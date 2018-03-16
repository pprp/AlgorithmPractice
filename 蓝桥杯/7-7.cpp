//#include <iostream>
//
//using namespace std;
//
//struct node
//{
//	int zhengshu;
//	int up,down;
//	void yuefen(){
//		int t = gcd(i,j);
//		up /= t;
//		down /= t;
//	}
//	node(int i, int j){
//		int t = gcd(i,j);
//		up = i/t;
//		down = j/t;
//		getzhengshu();
//	}	
//	void getzhengshu(){
//		while(up > down){
//			zhengshu++;
//			up -= down;
//		}
//	}
//	void output()
//	{
//		if(zhengshu != 0 && up != 0)
//		cout << zhengshu << " " << up << "/" << down << endl;
//		else if(zhengshu == 0)
//		cout << up << "/" << down << endl;
//		else if(zhengshu != 0 && up == 0)
//		cout << zhengshu << endl;
//	}	
//	int gcd(int l, int r){
//		return r == 0 ? l : gcd(r%l,l);
//	}
//	void add(node tt){
//		down = down*tt.down;
//		up = up * tt.down + down * tt.up;
//		yuefen();
//		getzhengshu();
//		output();
//	}
//	void sub(node tt){
//		down= down * tt.down;
//		up = up*tt.down - down * tt.up;
//		yuefen();
//		getzhengshu();
//		output();
//	}
//}
//
//char target[1000];
//
//int main(){
//	int n;
//	cin >> n;
//	cin >> target;
//	int len = strlen(target);
//	int aa,bb;
//	for(int i = 0 ; i < len ; i++){
//		
//	}
//	
//	
//	return 0;
//}



#include <stdio.h>
#include <iostream>

using namespace std;

long long gcd(long long a,long long b)//求最大公约数。
{
	return b == 0 ? a : gcd(b,a%b); 
}

int main()
{
    int N;
    long long lcp;//用以记录最小公倍数
    long long a,b,c,d;
    int i = 1;
    scanf("%d",&N);
    scanf("%lld/%lld",&a,&b);
    int t0 = gcd(a,b);
    if(a)
    {
        a /= t0;
        b /= t0;
    }

    while(i < N)
    {
        scanf("%lld/%lld",&c,&d);
        lcp = b / gcd(b,d) * d;//通过最大公约数换算出两个分母的最小公倍数
        a = a * lcp / b + c * lcp / d;//通分后分子和
        b = lcp;
        int t0 = gcd(a,b);
        if(t0 != 0)//从扩大最小公倍数之后的形式变换回来
        {
            a = a / t0;
            b = b / t0;
        }
        i++;
    }
    if(a && a/b == 0)/// 整数部分为0 且 a不为 0
        printf("%lld/%lld\n",a%b,b);
    else if(a%b == 0)/// 小数部分为0
        printf("%lld\n",a/b);
    else
        printf("%lld %lld/%lld\n",a/b,a%b,b);
    return 0;
}

