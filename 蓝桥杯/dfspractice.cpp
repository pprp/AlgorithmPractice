#include <iostream>

using namespace std;

int res = 0;
int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

void dfs(int now){
	if(now >= 3)
	if(a[0]+a[1]!=a[2])
	return ;
	if(now >=6)
	if(a[3]-a[4]!=a[5])
	return ;
	if(now >= 9)
	if(a[6]*a[7]!=a[8])
	return ;
	if(now >=12)
		if(a[10]*a[11]==a[9])
		{
			for(int i = 0 ; i < 12; i++)
			cout << a[i] << " ";
			cout << endl;
			res++;
			return ;		
		}

	for(int i = now ; i <= 12; i++){
		int t = a[i];
		a[i] = a[now];
		a[now] = t;
		
		dfs(now+1);
		
		t = a[i];
		a[i] = a[now];
		a[now] = t;
	}
	
}

void dfs2(int now){
	if(now >= 3)
		if(a[0]+a[1] != a[2])return ;
	if(now >= 6)
		if(a[3]-a[4] != a[5])return ;
	if(now >= 9)
		if(a[6]*a[7] != a[8])return ;
	if(now >= 12)
		{
			if(a[10]*a[11] == a[9])
			{
				res++;
			}	
			return ;

		}
		
	for(int i = now ; i <= 12 ; i++){
		int t = a[now];
		a[now] = a[i];
		a[i] = t;
		
		dfs2(now+1);
		
		t = a[now];
		a[now] = a[i];
		a[i] = t;
	}
		
	
}

int main(){
	dfs2(0);
	cout << res << endl;
	return 0;
} 
