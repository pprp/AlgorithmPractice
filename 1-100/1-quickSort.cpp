#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int arr[10000];

void quickSort(int l, int r){
  if(l >= r)return ;
  int tmp = arr[l];
  int i = l;
  int j = r;
  cout << i << " " << j << endl;
  while(i != j){
    while(arr[j] >= tmp && i < j)
      j--;
    while(arr[i] <= tmp && i < j)
      i++;
    if(i < j){
      int tt = arr[j];
      arr[j] = arr[i];
      arr[i] = tt;
    }
  }
  arr[l] = arr[j];
  arr[j] = tmp;
  quickSort(l,j-1);
  quickSort(j+1,r);
}
int main(){
  memset(arr,0,sizeof arr);
  cin >> n;
  for(int i = 0 ; i < n ;i++){
    cin >> arr[i];
  }
  quickSort(0,n-1);
  for(int i = 0 ; i < n ;i++){
    cout << arr[i] << " ";
  }
  cout << endl;



  return 0;
}
