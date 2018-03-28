#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int maxn = 30300;
int Set[maxn];

int find(int x){
  int r = x;
  while(r != Set[r])
    r = Set[r];

  int t = x;
  while(t != r){
    int p = Set[t];
    Set[t] = r;
    t = p;
  }
  return r;
}
void merge(int a, int b){
  int fa = find(a);
  int fb = find(b);
  if(fa < fb){
    Set[fb] = fa;
  }
  else if(fa > fb)
  {
    Set[fa] = fb;
  }
  return ;
}

int main(){
  // freopen("in.txt","r",stdin);
  int n,m,t,tmp1,tmp2;
  while (cin >> n >> m && n!=0) {
    if(m == 0){
      cout << "1" << endl;
      continue;
    }
    //init
    for(int i = 0 ; i < n ; i++)
      Set[i] = i;
    for(int i = 0 ; i < m ; i++){
      cin >> t;
      if(t <= 1){
        int test;
        cin >> test;
        continue;
      }
      cin >> tmp1;
      for(int j = 0 ; j < t-1 ; j++){
        cin >> tmp2;
        merge(tmp1,tmp2);
        tmp1 = tmp2;
      }
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
      if(0 == find(i))
        cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
