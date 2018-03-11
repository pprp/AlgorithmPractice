#include <iostream>

using namespace std;
int n, m;// n -> 1 m -> 0.5

int dfs(int n , int m){
	if(n > m)
		return 0;
	if(n == 0)
		return 1;
	if(m == 0 && n != 0)
		return 0;
		
	return dfs(n-1,m) + dfs(n,m-1);
}

int main()
{
	cin >> n >> m;
	
	cout << dfs(n,m) << endl;
	
	return 0;
}
