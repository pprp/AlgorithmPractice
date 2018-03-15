#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int a[1000];
int b[1000];
int sum[1000];

int main(){
	freopen("in.txt","r",stdin);
	
	int n;
	while(cin >> n){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(sum,0,sizeof sum);
						
		for(int i = 0 ; i < n ; i++){
			cin >> a[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin >> b[i];
		}
		
		for(int k = 0 ; k < n ;k++){
				cout << a[k] << " ";
		}
		cout << endl;
		
		for(int i = 0 ; i < n ; i++){ // day 
			for(int j = 0 ; j <= i ; j++){  // decrease the file volume
				if(a[j]-b[i]>=0)
				{
					a[j] -= b[i];
					sum[i] += b[i];
				}
				else
				{
					a[j] = 0;
					sum[i] += a[j];
				}	
			}
			
			cout << "test" << endl;
			for(int k = 0 ; k < n ;k++){
				cout << a[k] << " ";
			}
			cout << endl;
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			cout << sum[i] << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}
