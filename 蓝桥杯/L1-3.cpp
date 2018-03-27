//L1-3
#include <bits/stdc++.h>

using namespace std;
string add1,add2;
string pattern;

void reverse(){
  int len = add1.length();
  for(int i = 0 ; i < len/2; i++){
    char tmp = add1[i];
    add1[i] = add1[len-1-i];
    add1[len-i-1] = tmp;
  }

  len = add2.length();
  for(int i = 0 ; i < len/2; i++){
    char tmp = add2[i];
    add2[i] = add2[len-1-i];
    add2[len-i-1] = tmp;
  }

  len = pattern.length();
  for(int i = 0 ; i < len/2; i++){
    char tmp = pattern[i];
    pattern[i] = pattern[len-1-i];
    pattern[len-i-1] = tmp;
  }
}

int main()
{
  freopen("in.txt","r",stdin);
  stringstream ss1,ss2,ss3;
  long long a,b,c;
  cin >> a >> b >> c;

  // cout << a << endl;
  // cout << b << endl;
  // cout << c << endl;

  ss1 << a;
  ss1 >> pattern;
  ss2 << b;
  ss2 >> add1;
  ss3 << c;
  ss3 >> add2;

  // cout << pattern << endl;
  // cout <<  add1 << endl;
  // cout << add2 << endl;

  // cout << pattern.length() << add1.length() << add2.length()<< endl;
  // cin >> pattern >> add1 >> add2;
  // cout << pattern.length() << add1.length() << add2.length()<< endl;
  reverse();

  int len1 = add1.length();
  int len2 = add2.length();

  // cout << pattern << endl;
  // cout <<  add1 << endl;
  // cout << add2 << endl;

  vector<int>ans;
  for(int i=0, g=0; ; i++){

    if(g == 0 && i >= len1 && i >= len2)break;

    int x = g;
    if(i < len1) x += add1[i]-'0';
    if(i < len2) x += add2[i]-'0';
    int test = (int)(pattern[i]-'0');
    if(i <= 20 && test != 0){
      ans.push_back(x % test);
      g = x/test;
      // cout << "tag１" << endl;
    }
    else
    {
      ans.push_back(x % 10);
      g = x/10;
    }
  }

  for(int i = ans.size()-1; i >= 0 ; i--)
  cout << ans[i];
  cout << endl;
  return 0;
}

// #include<iostream>
// #include<string>
// using namespace std;
// int main() {
//     string a, b, c;
//     int l1, l2, l3, l, i, k=25;
//     int p[22] = {0}, q[22] = {0}, r[22] = {0}, d[22] = {0}, flag = 0;
//     int sum, jia=0;
//     cin>>a>>b>>c;
//     l1 = a.length();
//     l2 = b.length();
//     l3 = c.length();
//     for (i=0; i<l1; i++)
//         p[i] = a[l1-1-i] - '0';
//     for (i=0; i<l2; i++)
//         q[i] = b[l2-1-i] - '0';
//     for (i=0; i<l3; i++)
//         r[i] = c[l3-1-i] - '0';
//     l = l1 >= l2 ? l1 : l2;
//     for (i=0; i<=l; i++) {
//         sum = 0;
//         sum += jia;
//         if (p[i] == 0)
//             p[i] = 10;
//         sum = sum + q[i] + r[i];
//         d[i] += sum % p[i];
//         jia = sum / p[i];
//     }
//     for (i=l; i>=0; i--) {
//         if (d[i] != 0) {
//             k = i;
//             break;
//         }
//     }
//     if (k == 25)
//         cout<<"0";
//     else {
//         for (i=l; i>=0; i--) {
//             if (flag == 0 && d[i] == 0) {
//                 continue;
//             }
//             else
//                 cout<<d[i];
//         if (d[i] != 0)
//             flag = 1;
//         }
//     }
//     return 0;
// }
