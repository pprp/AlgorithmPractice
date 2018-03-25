#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int>v[100000];
double ZZ[100000];
queue<int>q;
const int maxn = 100000;
int N;
double Z, r;
int t;
int times;
double sum = 0.0;

void sovle(int rt)
{
  ZZ[rt] = Z;
  q.push(rt);
  int last = 0;
  int tmp = rt;
  while(!q.empty()){
    last = tmp;
    tmp = q.front();
    q.pop();
    for(size_t i = 0 ; i < v[tmp].size(); i++){
      int ttt = v[tmp][i];
      if(ttt > maxn){
        ttt -= maxn;
        ZZ[tmp] = (ZZ[last]*r)*ttt;
        sum += ZZ[i];
        // q.push(i);
      }
      else
      {
        ZZ[ttt] = ZZ[tmp]*r;
        q.push(ttt);
      }
    }
  }
}

int main(){
  // freopen("in.txt","r",stdin);
  cin >> N >> Z >> r;
  r = (100-r)/100.0;
  for(int i = 0 ; i < N ; i++){
     cin >> times;
     if(times != 0)
       for(int j = 0 ; j < times; j++){
         cin >> t;
         v[i].push_back(t);
       }
     else
     {
       cin >> t;
       v[i].push_back(maxn+t);
     }
  }
  memset(ZZ,0,sizeof ZZ);
  sovle(0);
  cout << (int)sum << endl;
  return 0;
}
