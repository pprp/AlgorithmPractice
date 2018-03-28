#include <stdio.h>
#include <string.h>

int arr[1000];
int tmp;
int main(){
  memset(arr,0,sizeof arr);
  int n;
  scanf("%d",&n);
  int i,j;
  for(i = 0 ; i < n ; i++)
    scanf("%d",&arr[i]);
  for(i = 1 ; i < n ; i++){
    int tmp = arr[i];
    j = i-1;
    while(j >= 0 && tmp < arr[j]){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = tmp;
  }
  for(i = 0 ; i < n ; i++)
  {
    printf("%d ",arr[i]);
  }
  printf("\n");
  return 0;
}
