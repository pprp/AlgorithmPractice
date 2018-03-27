#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
int n, t,tmp,q;
set<int> s;
set<int> ss;
int main(){
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++){
    cin >> t;
    if(t == 1)
    {
      cin >> tmp;
      continue;
    }
    for(int j = 0 ; j < t; j++){
      cin >> tmp;
      s.insert(tmp);
    }
  }
  cin >> q;
  int f = 1;
  for(int i = 0 ; i < q ; i++){
    cin >> tmp;
    if(ss.find(tmp) != ss.end())continue;
    ss.insert(tmp);
    // set<int>::iterator it;
    if(s.find(tmp) == s.end()){
      if(f)
      {
        printf("%05d",tmp);
        f = 0;
      }
      else
      printf(" %05d",tmp);
    }
  }
  if(f)
    cout << "No one is handsome" << endl;
  else
    cout << endl;


  return 0;
}
