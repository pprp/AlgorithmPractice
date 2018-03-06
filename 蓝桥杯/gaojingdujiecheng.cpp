#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	if(n == 1)
		cout << 1 << endl;
	else
	{
		int h = 0, e = 0;
		int a[100001];
		memset(a,0,sizeof a);
		a[0] = 1;
		int c = 0;
		for(int i = 2; i <= n; i++){
			c = 0;
			for(int j = h ; j <= e; j++){
				int tmp = a[j] * i + c;
				c = tmp / 10;
				a[j] = tmp % 10;
			}
			while(c){
				e++;
				a[e] = c % 10;
				c /= 10;
			}			
		}
		for(int i = e ; i >= h ; i--){
			cout << a[i];
		}
		cout << endl;
	}
	
	return 0;
}
