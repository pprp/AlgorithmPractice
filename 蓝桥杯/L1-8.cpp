#include <bits/stdc++.h>

using namespace std;

int tominite(int day,int hh,int mm){
  int ans = (day-1)*24*60 + hh * 60 + mm;
  ans /= 2;
  return ans;
}

int main(){
  int n;
  cin >> n;
  int day, hh,mm;
  while(n--){
    scanf("%d %d:%d",&day,&hh,&mm);
    if(day == 0)
    {
        printf("%d %02d:%02d\n",day,hh,mm);
        continue;
    }
    int mis = tominite(day,hh,mm);
    int dy = mis/(24*60);
    // cout << dy << endl;
    int hr = (mis-dy*24*60)/60;
    // cout << hr << endl;
    int me = mis-dy*24*60-hr*60;
    // cout << me << endl;
    printf("%d %02d:%02d\n",dy+1,hr,me);
  }
  return 0;
}
