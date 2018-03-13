/*
uva 1226
*/

#include <iostream>
#include <cstring>

using namespace std;

int a[1000][10];

int main(){
	memset(a,0,sizeof a); 
	for(int i = 1 ; i < 1000; i++){
		
		for(int j = 0 ; j < 10 ; j++){
			a[i][j] = a[i-1][j];
		}
		
		for(int k = i ; k ; k/=10){
			a[i][k%10]++;
		}		
	}
	
	int n;
	cin >> n;
	for(int i= 0 ; i < n ; i++)
	{
		int t;
		cin >> t;
		for(int j = 0 ; j < 9 ; j++){
			cout << a[t][j] << " ";
		}
		cout << a[t][9] << endl;
	}
	
	return 0;
}
