#include <bits/stdc++.h>
using namespace std;
int main(){
  freopen("in.txt","r",stdin);
  int N;
  double h,w;
  cin >> N;
  while(N--){
    cin >> h >> w;
    int biaozhun = (h-100)*0.9*2;
    double up = biaozhun*1.1;
    double down = biaozhun*0.9;
    if(w < up && w > down){
      cout << "You are wan mei!" << endl;
    }
    else if(w <= down){
      cout << "You are tai shou le!" << endl;
    }
    else if(w >= up)
    {
      cout << "You are tai pang le!" << endl;
    }
  }
  return 0;
}
