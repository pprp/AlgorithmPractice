#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

const int maxn =  100000+100;
vector<int>vv;
// vector<int>ans;
int n;
bool num[maxn];
void create()
{
  memset(num,1,sizeof(num));
  num[1] = 0;
  num[2] = 1;

  for(int i = 2; i <= maxn ; i++){
    if(num[i] == 1){
      for(int j = i*i; j <= maxn ; j+=i){
        num[j] = 0;
      }
    }
  }
}

bool judge(int n){
  if(n < 2)return false;
  if(n == 2)return true;
  for(int i = 2 ; i < sqrt(n)+1; i++){
    if(n%i == 0)
    return false;
  }
  return true;
}

int main(){
  int cnt =0;
  // int top = -1;
  // while(cin >> n){
  //   cout << judge(n) << endl;
  // }

cin >> n;

  // create();
  // for(int i = 1 ; i < n ; i++){
  //   if(num[i] != 0){
  //     vv.push_back(i);
  //     // cout << i << endl;
  //   }
  // }

  for(int i=1; i <= n ; i++){
    if(judge(i))
    {
      vv.push_back(i);
    }
  }
  for(int i= 0 ; i < vv.size(); i++){
    if(vv[i]+2 == vv[i+1])
    cnt++;
  }

  cout << cnt << endl;


  return 0;
}
