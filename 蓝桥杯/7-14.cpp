#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
	int N;
const int maxn = 1000;

int map[10000][10000];
bool vis[10000][10000];
int cnt = 0; /// liang tong kuai

void floyd(){
	int i, j, k;
	for(k = 0;k< N; k++ ){
		for(i = 1; i < N; i++){
			for(j = 1; j < N ; j++){
				if(map[i][k] != maxn && map[k][j] != maxn){
					map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
				}
			}
		}
	}
}

void dfs(int r,int c, int id){
	if(r < 0 || r >= N || c < 0 || c >= N)return ;
	if(vis[r][c] > 0 || map[r][c] != 1)return ;
	vis[r][c] = id;
	for(int dr =  -1; dr <= 1; dr++){
		for(int dc = -1 ; dc <= 1; dc++){
			if(dr != 0 || dc != 0)
				dfs(r+dr,c+dc,id);
		}
	}
}

int main(){
	memset(vis,0,sizeof vis);
	cin >> N;
	char f;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			map[i][j] = maxn;
		}
	}
	while(cin >> f){
		int a, b;
		if(f == 'S')
		{
			for(int i = 0 ; i < N ; i++){
				for(int j = 0 ; j < N ; j++){
					if(vis[i][j] == 0 && map[i][j] == 1)
						dfs(i,j,++cnt);
				}
			}
			if(cnt != 1)
			cout << "There are "<< cnt <<" components." << endl;
			else
			cout << "The network is connected." << endl;			
			break;
		}
		if(f == 'C')
		{
			cin >> a >> b;
			floyd();
			if(map[a][b] != maxn){
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
//			if(dfs(a,b)){
//				cout << "yes" << endl;
//			}
//			else
//			{
//				cout << "no" << endl;
//			}
		}
		if(f == 'I')
		{
			cin >> a >> b;
			map[a][b] = map[b][a] = 1;
		}
	}
	
	
	return 0;
} 
