#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000000;
int pre[maxn];
int mid[maxn];
int n,m,t,tmp;

struct Tree
{
  int l,r;
}a[maxn];

int build(int pl,int pr,int ml, int mr){
  if(pl > pr)return 0;
  int rt = pre[pl];
  int top1,top2;
  top1 = ml;
  while(mid[top1]!=rt)top1++;
  top2=top1-ml;
  a[rt].l = build(pl+1,pl+top2,ml,top1-1);
  a[rt].r = build(pl+top2+1,pr,top1+1,mr);
  return rt;
}

void bfs(int x){
  queue<int> q;
  vector<int> v;
  q.push(x);
  while(!q.empty()){
    tmp = q.front();
    q.pop();
    if(tmp == 0)break;
    v.push_back(tmp);
    if(a[tmp].r != 0)q.push(a[tmp].r);
    if(a[tmp].l != 0)q.push(a[tmp].l);
  }
  int len = v.size();
  for(int i = 0 ; i < len ; i++)
    printf("%d%c",v[i],i==len-1?'\n':' ');
  return ;
}

int main(){
  cin >> n;
  for(int i = 0 ; i < n ; i++)cin >> mid[i];
  for(int j = 0 ; j < n ; j++)cin >> pre[j];
  build(0,n-1,0,n-1);
  int root = pre[0];
  bfs(root);
  return 0;
}
