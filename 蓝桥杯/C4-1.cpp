// #include <bits/stdc++.h>
//
// using namespace std;
//
// int main(){
//   stringstream ss;
//   string str;
//   getline(cin,str);
//   ss << str;
//   int cnt = 1;
//   int tmp;
//   while(ss >> tmp){
//     if(tmp == 250){
//       cout << cnt << endl;
//       break;
//     }
//     cnt++;
//   }
//
//   return 0;
// }
/*
#include <bits/stdc++.h>

using namespace std;

int main(){
  int m,d,y;
  scanf("%d-%d-%d",&m,&d,&y);
  printf("%d-%02d-%02d\n",y,m,d);
  return 0;
}
*/
/*
#include <bits/stdc++.h>

using namespace std;

int mms(int h,int m){
  return h * 60 + m;
}

struct node{
  int bmm;
  int emm;
  node(){
    bmm = emm = -1;
  }
};

node tmp[10000];

int main(){
  // freopen("in.txt","r",stdin);
  int n;
  cin >> n;
  int book,hh,mm;
  char ch;
  // int rec = n;

  while(n--){

    int cnttime = 0;
    int count = 0;
    for(int i = 0 ; i < n+1; i++){
        tmp[i].emm = tmp[i].bmm = -1;
    }

    while(scanf("%d %c %2d:%2d",&book,&ch,&hh,&mm) && book)
    {
      if(ch == 'S')
        tmp[book].bmm = mms(hh,mm);
      else if(tmp[book].bmm != -1 && ch == 'E')
        {
          count++;
          tmp[book].emm = mms(hh,mm);
          cnttime += (tmp[book].emm - tmp[book].bmm);
        }
    }
    if(count) cnttime = ((cnttime*1.0)/count) + 0.5;
    cout << count << ' ' << cnttime << endl;
  }
  return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll  x;
  cin >> x;
  ll mj = 1;
  int cnt = 1;
  while(true)
  {
    if(mj%x != 0){
      cnt++;
      mj *= 10;
      mj += 1;
    }
    else
    {
      cout << mj/x << ' ' << cnt << endl;
      break;
    }
  }

  return 0;
}
*/

/*
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string name;
  int a, b;
  cin >> n;
  while(n--){
    cin >> name >> a >> b;
    if(a < 15 || a > 20 || b < 50 || b > 70)
    cout << name << endl;
  }
    return 0;
}
*/

/*
#include <bits/stdc++.h>

using namespace std;
int a1,a2;
int b1,b2;

int a[110][110];
int b[110][110];
int ans[110][110];

int main(){
  freopen("in.txt","r",stdin);
  cin >> a1 >> a2;
  for(int i = 0 ; i < a1; i++){
    for(int j = 0 ; j < a2 ; j++){
      cin >> a[i][j];
    }
  }
  cin >> b1 >> b2;
  if(a2 != b1)
  {
    cout << "Error: "<<a2<<" != "<<b1<<""<< endl;
    return 0;
  }
  else
  {
    cout << a1 << " " << b2 << endl;
  }
  for(int i = 0 ; i < b1; i++){
    for(int j = 0 ; j < b2; j++){
      cin >> b[i][j];
    }
  }

  for(int a11=0; a11 < a1; a11++){
    bool tag = true;
    for(int b22=0; b22 < b2; b22++){
      int sum = 0;
      for(int i = 0 ; i < a2; i++){
        sum += a[a11][i]*b[i][b22];
      }
      if(tag)
      {
        cout << sum;
        tag = false;
      }
      else
      cout << ' ' << sum;
    }
    cout << endl;
  }


  return 0;
}
*/


/*
L2-1
*/
#include <bits/stdc++.h>

using namespace std;

int but[150];

struct node
{
  string str;
  double pt;//second
  int tt;//first
}person[110];

bool cmp(const node& n1,const node&n2){
  if(n1.tt != n2.tt)return n1.tt > n2.tt;
  return n1.pt > n2.pt;
}

vector<node> vv;

int main(){
  int n;
  string name;
  cin >> n;
  for(int k = 0; k < n ; k++){
    memset(but,0,sizeof(but));
    int times;
    cin >> name >> times;
    for(int i = 0 ; i < times; i++){
      int t;
      cin >> t;
      but[t]++;
    }
    int score = 0;
    int cnt = 0;
    for(int i = 0 ; i < 107; i++){
      score += but[i];
      if(but[i] != 0)
        cnt++;
    }
    person[k].pt = score * 1.0/times;
    person[k].str = name;
    person[k].tt = cnt;
    vv.push_back(person[k]);
  }
  sort(vv.begin(),vv.end());
  cout << vv[0].str;
  for(int i = 1 ; i < 3; i++){
    cout << " " << vv[i].str;
  }
  cout << endl;
  return 0;
}
