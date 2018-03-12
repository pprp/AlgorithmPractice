#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

struct node
{
	int x, y;
	node(int x, int y){
		this.x = x;
		this.y = y;
	}
}

stack<node>

int a[3][4];
bool vis[3][4];
int res = 0;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool check(int x, int y){
	if(x < 0 || x > 3 || y < 0 || y > 4){
		return false;
	}
	return true;	
}

void bfs(int num,int x, int y){
	if(num == 5){
		res++;
	}
	for(int i = 0 ; i < 4; i++){
		if(check(x+dx[i],y+dy[i]) && vis[x+dx[i]][y+dy[i]] == 0){
			vis[x+dx[i]][y+dy[i]] = 1;
			bfs(num+1,x+dx[i],y+dy[i]);
			vis[x+dx[i]][y+dy[i]] = 0;
		}
	}
}

int main(){	
	
	for(int i = 0 ; i < 3; i++){
		for(int j = 0 ; j < 4; j++){
			memset(vis,0,sizeof vis);
			bfs(0,i,j);
		}
	}	
	cout << res << endl;
	
	return 0;
}
