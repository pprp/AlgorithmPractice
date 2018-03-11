#include <iostream>

using namespace std;

int dfs(int k, int n){
	if(k == 0 || k == n)
		return 1;
	return dfs(k,n-1)+dfs(k-1,n-1);	
}

int main(){
	int k , n;
	cin >> k >> n;
	cout << dfs(k,n) << endl;	
	return 0;
}
