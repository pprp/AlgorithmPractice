#include<iostream>

using namespace std;

//int dfs(int l, int r){
//	
//	if(l == 0)
//		return 1;
//	if(r == 0)
//		return dfs(l-1,1);
//	return dfs(l-1,r+1) + dfs(l,r-1); 
//}

int dfs(int l , int r){
	if(l == 0)
		return 1;
	if(r == 0)
		return dfs(l-1,1);
	return dfs(l-1,r+1) + dfs(l,r-1);
}


int main(){
	
	for(int i = 1; i <= 18 ; i++){
		cout << dfs(i,0) << endl;
	}
	
	return 0;
} 
