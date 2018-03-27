#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int main(){
  int top = -1;
  string str[1000];
  string tmp;
  getline(cin,tmp);
  // getchar();
  stringstream ss;
  ss << tmp;
  while(ss >> str[++top]){}
  // bool f = 1;
  cout << str[top-1];
  for(int i= top-2; i >= 0 ; i--){
      cout << " " << str[i];
  }
  cout << endl;
return 0;
}
