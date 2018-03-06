#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n , m;
	cin >> n >> m;
	
	int a[10001];
//	int ans[10010];
	memset(a,0,sizeof a);
//	memset(ans,0,sizeof ans);
	
	int e = 0;
	while(n){
		a[e++] = n % 10;
		n /= 10;
	}
//	for(int i = 0 ; i< e; i++)
//	cout << a[i];
//	cout << endl;
	int c = 0;
	for(int i = 0 ; i < e ; i++){
		int tmp = a[i] * m + c;
		c = tmp/10;
		a[i] = tmp%10;
	}
	
	while(c){
		a[e++] = c % 10;
		c/=10;		 
	}
	for(int i = e-1; i >= 0; i--){
		cout << a[i];
	}
	cout << endl;


	return 0;
}
