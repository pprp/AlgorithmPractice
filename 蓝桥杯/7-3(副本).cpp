#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
int n;
char a;
cin >> n >> a;
for(int i = 0; i < (n-1)/2+1 ; i++){
  for(int j = 0 ; j < n ; j++){
    cout << a;
  }
  cout << endl;
}
return 0;
}
