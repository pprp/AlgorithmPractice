#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

int gcd(int l, int r){
  return r == 0 ? l : gcd(r,l%r);
}

int main(){
  int n;
  cin >> n;
  int a[100], b[100];
  int up, down;
  scanf("%d/%d",&a[0],&b[0]);
  for(int i = 1 ; i < n ;i++)
  {
    scanf("%d/%d",&a[i],&b[i]);
    // cout << a << " " << b << endl;
    if(a[i] < 0){
      up = a[i] * b[i-1] - b[i]*a[i-1];
      down = b[i]*b[i-1];
      int t = gcd(up,down);
      if(t == 0)continue;
      up /= t;
      down /= t;
    }
    else
    {
      up = a[i] * b[i-1] + b[i]*a[i-1];
      down = b[i]*b[i-1];
      int t = gcd(up,down);
      if(t == 0)continue;
      up /= t;
      down /= t;
    }
  }

  cout << up << " " << down << endl;

return 0;
}
