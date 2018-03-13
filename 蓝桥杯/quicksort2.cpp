#include <iostream>
#include <cstring>

using namespace std;

int a[1000];

void quickSort(int l, int r)
{
	if(l > r)
	return;
	int tt = a[l];
	int i = l;
	int j = r;
	
	while(i != j){
		while(i < j && a[j] >= tt)
			j--;
		while(i < j && a[i] <= tt)
			i++;
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	
	a[l] = a[i];
	a[i] = tt;
	
	quickSort(l,i-1);
	quickSort(i+1,r);
}

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	quickSort(0,n-1);
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
