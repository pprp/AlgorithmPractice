#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int sumlen = 0,tlen = 0, tnum = 0;
int stick[100];
bool vis[100];

bool cmp(int a, int b){
	return a > b;
}

bool dfs(int cnt, int len , int pos){
	if(cnt == tnum)return true;
	if(len == tlen)return dfs(cnt+1,0,0);
	for(int i= pos ; i < n ; i++){
		if(!vis[i] && len + stick[i] <= tlen){
			vis[i] = 1;
			if(dfs(cnt,len+stick[i],pos+1)) return true;
			vis[i] = 0;
//			if(len == 0) return false;
			while(i+1<n&&stick[i]==stick[i+1])i++;
		}
	}
	return false;
}
void solve(){
	int ans = 0;
	memset(vis,0,sizeof vis);
	for(int i = 1 ; i <= sumlen ; i++){
		if(sumlen % i == 0){
			tlen = i;
			tnum = sumlen / i;
		}
		if(dfs(0,0,0)){
			ans = tlen;
			break;
		}
	}
	cout << ans << endl;
}
int main(){
	
	while(cin >> n && n){
		sumlen = 0;
		for(int i = 0 ; i < n ; i++)
		{
			cin >> stick[i];
			sumlen += stick[i];
		}
		sort(stick,stick+n,cmp);
		solve();
	}
	
	
	return 0;
}
