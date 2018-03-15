#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int a[maxn];

int main(){
	freopen("in.txt","r",stdin);
	int T;
	cin >> T;
	while(T--){
		int sum = 0;
		int n;
		cin >> n;
		int before;
		int now;
		cin >> before;
		for(int i= 0 ; i < n-1 ; i++){
			cin >> now;
			a[i] = now - before - 1;
			sum += a[i];
			before = now;
		}
//		for(int i= 0 ; i < n-1 ;i++)
//			sum += a[i];
		sum -= a[0] < a[n-1] ? a[0] : a[n-1];
//		if(abs(a[1]-a[0]) > abs(a[n-1]-a[n-2])){
//			sum -= abs(a[n-1]-a[n-2]);
//		}	
//		else
//		{
//			sum -= abs(a[1]-a[0]);
//		}
		cout << sum << endl;
	} 
	
	return 0;
}
