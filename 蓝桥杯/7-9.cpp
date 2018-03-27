/*
7-9 集合相似度
*/

#include <bits/stdc++.h>

using namespace std;

set<int>ss[100];
int aa, bb, n, m, t;


void solve(int a, int b){
  int same = 0;
  set<int>::iterator it;
  for(it = ss[a].begin(); it != ss[a].end(); it++){
    if(ss[b].find(*it) != ss[b].end())same++;
  }
  int sum = ss[a].size() + ss[b].size();
  int cnt = sum - same;
  printf("%.2lf\%\n",same*1.0/cnt*100);

}


int main(){
  // ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0 ; i < n ;i++)
  {
    cin >> t;
    for(int j = 0 ; j < t ; j++){
      scanf("%d",&aa);
      ss[i].insert(aa);
    }
  }

  cin >> m;

    for(int i = 0 ; i < m ; i++){
      scanf("%d%d",&aa,&bb);
      aa--;
      bb--;
      solve(aa,bb);
    }

  return 0;
}
