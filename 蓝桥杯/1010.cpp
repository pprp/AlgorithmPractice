#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int main(){
  int a, b;
  int tag = 1;
  while(cin >> a >> b && b){
    if(tag == 0)cout << " ";
    cout << a*b << " " << b-1;
    tag = 0;
  }
  if(a == 0 && b == 0)cout << "0 0" << endl;

return 0;
}
