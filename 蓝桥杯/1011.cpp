#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main(){
  long long n, a, b, c;
  cin >>n;
  for(int i= 1; i <= n; i++)
  {
    cin >> a >> b >> c;
    if(a+b>c)
    printf("Case #%d: true\n",i);
    else
    printf("Case #%d: false\n",i);
  }
return 0;
}
