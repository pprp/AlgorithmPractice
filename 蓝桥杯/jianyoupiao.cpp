#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int r = 3, c = 4;

bool mp[10][10];
bool vis[10][10];
int res = 0;
int len = 0;
//int ccccc = 0; 

struct node{
	int x, y;
	node(){
	}
	node(int xx, int yy){
		this->x = xx;
		this->y = yy;
	}
};

node a[10];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool isRight(int x, int y){
	if(x < 0 || x > r || y < 0 || y > c)
		return false;
	return true;
}

int bfs(){
	
	int cn = 0;
	memcpy(vis,mp,sizeof vis);
	queue<node> qu;	
	
	qu.push(a[0]);
	vis[a[0].x][a[0].y] = false;
	cn = 1;
	
	while(!qu.empty()){
		node tmp = qu.front();
		qu.pop();
		for(int i= 0 ; i < 4 ;i++){
			int tx = tmp.x + dx[i];
			int ty = tmp.y + dy[i];
			
			if(isRight(tx,ty) && vis[tx][ty])
			{
				vis[tx][ty] = false;
				cn++;
				qu.push(node(tx,ty));
			}
		}		
	}
	return cn;	
}


void dfs(int x, int y, int now){
	if(now == 5){
		if(bfs() == 5)
		{
			res++;
		}		
//		ccccc++;s
		return;
	}
	if(x == r) return ;
	for(int i = y ; i <= c; i++){
		if(i < c)
		{
			mp[x][i] = true;
			a[len] = node(x,i);
			len++;
			
			dfs(x,i+1,now+1);
			
			len--;
			mp[x][i] = false;
		}
		else
		{
			dfs(x+1,0,now);	
		}
	}		
}

int main(){
	memset(mp,false,sizeof mp);
	res = 0;
	len = 0;
	dfs(0,0,0);
	
	cout << res << endl;
	
//	cout << ccccc << endl;
	
	return 0;
} 
