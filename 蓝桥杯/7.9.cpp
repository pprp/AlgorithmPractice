#include <bits/stdc++.h>

using namespace std;
struct person
{
  int no;
  double money;
  int time;
  person(){
    no=money=0;
  }
};
bool cmp(const person&p1,const person &p2){
  if((p1.money) == (p2.money))
  {
    if(p1.time != p2.time){
      return p1.time > p2.time;
    }
    else
    {
      return p1.no < p2.no;
    }
  }
else
  return p1.money > p2.money;
}
person red[10000+100];
int n,tmpi,k;
double tmp;
int main(){
  // freopen("in.txt","r",stdin);
  cin >> n;
  for(int p = 1; p <= n ; p++)
  {
    cin >> k;
    red[p].no = p;
    red[p].time = k;
    for(int i = 0 ; i < k ; i++){
      cin >> tmpi >> tmp;
      red[tmpi].money += tmp;
      red[p].money -= tmp;
    }
  }

  sort(red+1,red+n+1,cmp);

  for(int i = 1; i <= n ; i++){
    // cout << red[i].no << " " << red[i].in-red[i].out << endl;
    printf("%d %.2f\n",red[i].no,red[i].money*0.01);
  }


  return 0;
}
