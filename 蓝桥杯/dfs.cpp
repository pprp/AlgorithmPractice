#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;
int n, targetnum, targetlen;
int sumlen = 0;
int stick[1000];
bool vis[1000];

bool cmp(int a, int b){
	return a > b;
}
void init(){
	sumlen = 0;
	for(int i = 0 ; i < n ; i++){
		cin >> stick[i];
		sumlen += stick[i];
	}
	memset(vis,0,sizeof vis);	
	sort(stick,stick+n,cmp);
}

bool dfs(int cnt, int len , int pos){
	if(cnt == targetnum)
		return true;
	if(len == targetlen)
		return dfs(cnt+1,0,0);
	for(int i = pos ; i < n ; i++){
		if(!vis[i] && len + stick[i] <= targetlen){
			vis[i] = 1;
			if(dfs(cnt,len+stick[i],i+1))
				return true;
			vis[i] = 0;
			if(len == 0) return false;
			while(i+1<n && stick[i] == stick[i+1])
				i++;
		}
	}
	return false;
}

void solve(){
	int ans = 0;
	for(int i = 1; i <= sumlen ; i++){
		memset(vis,0,sizeof vis);	
		if(sumlen % i == 0){
			targetnum = i;
			targetlen = sumlen / i;
		}
		if(dfs(0,0,0))
		{
			ans = targetlen;
		}
	}
	cout << ans << endl;
}

int main(){
	while(cin >> n && n){
		init();
		solve();
//		cout << targetnum << endl;
	}
	return 0;
}

