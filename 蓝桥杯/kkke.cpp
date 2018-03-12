#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int r = 3, c = 4;
int cc;

struct node {
	int x, y;
	node() {}
	node(int x, int y) : x(x), y(y) {}
};

node a[10];
int len;

bool mapp[10][10];
bool bm[10][10];
int cou;

int dir[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 }; //右，下，上，左

bool Isout(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c) {
		return true;
	}
	return false;
}

//能够被纳入连通域返回true
bool CanCollect(int nx, int ny) {
	return bm[nx][ny];
}

int bfs() {
	int cn;  //连通域中块的个数
	memcpy(bm, mapp, sizeof(bm));
	queue<node> Q;

	Q.push(a[0]);
	bm[a[0].x][a[0].y] = false;
	cn = 1;

	while (!Q.empty()) {
		node tx = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tx.x + dir[i][0];
			int ny = tx.y + dir[i][1];
			if (!Isout(nx, ny) && CanCollect(nx, ny)) {
				bm[nx][ny] = false;
				cn++;
				Q.push(node(nx, ny));
			}
		}
	}
	return cn;
}

void dfs(int x, int y, int dep) {
	if (dep == 5) {
		if (bfs() == 5) {
			cou++;
		}
		cc++;
		return;
	}
	if (x == r) return;
	for (int i = y; i <= c; i++) {
		if (i < c) {
			mapp[x][i] = true;
			a[len] = node(x, i);
			len++;

			dfs(x, i + 1, dep + 1);

			len--;
			mapp[x][i] = false;
		}
		else {
			dfs(x + 1, 0, dep);
		}
	}
}

int main()
{
	memset(mapp, false, sizeof(mapp));
	cou = 0;
	cc = 0;
	len = 0;
	dfs(0, 0, 0);
	cout << cou << endl; //116
	cout << cc << endl;  //792
	return 0;
}
