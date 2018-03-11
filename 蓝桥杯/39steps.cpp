#include <iostream>

using namespace std;

int dfs(int now,int steps){
	if(now == 0 && steps % 2 == 0)
		return 1;
	if(now < 0)
		return 0;	
	return dfs(now-1,steps+1) + dfs(now-2,steps+1);
}

int main(){
	
	cout << dfs(39,0) << endl;
	return 0;
}
