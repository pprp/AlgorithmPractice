#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 10000; 
bool a[maxn][maxn];
int main(){
	int n, m;
	cin >> n >> m;
	memset(a,1,sizeof a);
	for(int i = 1 ; i <= n ; i++ ){
		for(int j = 1; j <= m ; j++){
			//mei ju le (i,j)
			for(int k = 1;i*k<=n;k++){
				for(int t = 1;j*t<= m;t++){
					a[i*k][j*t] = !a[i*k][j*t];	
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 0)
			cnt++;
		}	
	}	
	cout << cnt << endl;
		
	return 0;
} 
