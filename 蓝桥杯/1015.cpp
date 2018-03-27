#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, L, H;

struct node
{
  int no;
  int de,cai;
};

bool cmp(const node&n1,const node&n2){
  if(n1.de+n1.cai != n2.de + n2.cai)
    return n1.de + n1.cai > n2.de + n2.cai;
  else
  {
    if(n1.de != n2.de){
      return n1.de > n2.de;
    }
    else
    {
      return n1.no < n2.no;
    }
  }
}

int main(){

  std::ios::sync_with_stdio(false);
  cin >> n >> L >> H;
  vector<node> v1,v2,v3,v4;
  node ns;
  int count = 0;
  for(int i = 0 ; i < n ;i++){
    cin >> ns.no >> ns.de >> ns.cai;
    if(ns.de >= L && ns.cai >= L){
      count++;
      if(ns.de >= H && ns.cai >= H)
        v1.push_back(ns);
      else if(ns.de >= H && ns.cai <= H)
        v2.push_back(ns);
      else if(ns.de >= ns.cai && ns.de < H && ns.cai < H)
        v3.push_back(ns);
      else
        v4.push_back(ns);

    }
  }

  sort(v1.begin(),v1.end(),cmp);
  sort(v2.begin(),v2.end(),cmp);
  sort(v3.begin(),v3.end(),cmp);
  sort(v4.begin(),v4.end(),cmp);

  cout << count << endl;
  for(int i= 0 ; i < v1.size(); i++){
    cout << v1[i].no << " " << v1[i].de << " " << v1[i].cai << endl;
  }
  for(int i= 0 ; i < v2.size(); i++){
    cout << v2[i].no << " " << v2[i].de << " " << v2[i].cai << endl;
  }
  for(int i= 0 ; i < v3.size(); i++){
    cout << v3[i].no << " " << v3[i].de << " " << v3[i].cai << endl;
  }
  for(int i= 0 ; i < v4.size(); i++){
    cout << v4[i].no << " " << v4[i].de << " " << v4[i].cai << endl;
  }

  return 0;
}
