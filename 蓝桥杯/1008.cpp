#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int vv[10000];
int N, M;


void print()
{
  bool t = 1;
  for(int i= 0 ; i < N; i++)
  {
    if(t)
    cout << vv[i];
    else
    cout << " " << vv[i];

    t = 0;
  }
  cout << endl;
  return;
}

int main(){
  cin >> N >> M;
  for(int i= 0 ; i < N ; i++){
    cin >> vv[i];
  }

  M %= N;
  reverse(vv,vv+N-M);
  reverse(vv+N-M,vv+N);
  reverse(vv,vv+N);

  print();

  return 0;
}
