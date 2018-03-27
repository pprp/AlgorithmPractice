#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<char> vv[1000];
int main(){
  int n;
  string str;
  cin >> n;
  getchar();
  getline(cin,str);
  // cout << str << endl;
  int len = str.length();

  int dpj;
  if(len%n == 0)
    dpj = (len/n);
  else
    dpj = (len/n)+1;


  for(int i= 0 ; i < dpj*n ; i++){
    if(i < len)
    vv[i%n].push_back(str[i]);
    else
    vv[i%n].push_back(' ');
  }

  for(int i = 0 ; i < n; i++)
  {
    reverse(vv[i].begin(),vv[i].end());
    for(int j = 0; j < vv[i].size(); j++){
      cout << vv[i][j];
    }
    cout << endl;
  }

  return 0;
}
