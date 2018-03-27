#include <bits/stdc++.h>

using namespace std;
//并查集
int father[105];

int mp[110][110];
int n,m,k;

int finds(int x){
  if(x != father[x])
    father[x] = finds(father[x]);
  return father[x];
}

void combine(int x, int y, int t){
  if(t == 1){
    int a = finds(x);
    int b = finds(y);
    if(a == b)return;
    if(a < b)father[b]=a;
    else father[a] = b;
  }else{
    mp[x][y]=mp[y][x]=-1;
  }
}
int main(){
  freopen("in.txt","r",stdin);
  memset(mp,0,sizeof mp);
  cin >> n>>m >> k;
  for(int i= 0 ; i <= n; i++){
    father[i] = i;
  }
  for(int i = 1; i <= m ; i++)
  {
    int x,y,t;
    cin >> x >> y >> t;
    combine(x,y,t);
  }
  int x,y;
  for(int i = 0 ; i < k ; i++){
    cin >> x >> y;
    if(finds(x) == finds(y) && mp[x][y] != -1)
    cout << "No problem" << endl;
    else if(finds(x) == finds(y) && mp[x][y] == -1)
    cout << "OK but..." << endl;
    else if(finds(x) != finds(y) && mp[x][y] == -1)
    cout << "No way" << endl;
    else
    cout << "OK" << endl;
  }
  return 0;
}
