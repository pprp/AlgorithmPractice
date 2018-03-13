/*
quick sort
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int a[1000];


void quickSort(int l,int r){
	
	if(l > r)
		return ;
	int i = l;
	int j = r;
	int ttmp = a[l];
	
//	while(1){
//		while(a[j] > ttmp)
//			j--;
//		while(a[i] < ttmp)
//			i++;
//	 	
//    	int tmp = a[i];
//    	a[i] = a[j];
//    	a[j] = tmp;
//	 	if(i >= j)
//			break; 
//	}

	while(i != j){
		while(a[j] >= ttmp && i < j)
			j--;
		while(a[i] <= ttmp && i < j)
			i++;
		if(i < j)
		{
			swap(a[i],a[j]);
		}
	}	
	a[l] = a[j];
	a[j] = ttmp;
	quickSort(l,j-1);
	quickSort(j+1,r);	
}

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
	{
		cin >> a[i];
	}
	quickSort(0,n-1);
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
