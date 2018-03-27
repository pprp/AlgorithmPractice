#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a, b, c;
  a = n % 10;
  b = n/10%10;
  c = n/100;
  for(int i = 0 ; i < c; i++){
    cout << "B";
  }
  for(int j = 0 ; j < b ; j++){
    cout << "S";
  }
  for(int k = 1; k <= a; k++){
    cout << k;
  }
  cout << endl;



  return 0;
}
