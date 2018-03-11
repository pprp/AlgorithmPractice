#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	if(n < m)
	{
		cout << "-";
		int t = n;
		n = m;
		m = t;
	}
	int a[100001],b[100001];
	int lena = 0, lenb = 0;
	
	while(n){
		a[lena++] = n%10;
		n/=10;
	}
	while(m){
		b[lenb++] = m%10;
		m/=10;
	}
	
//	cout << lena << " " << lenb << endl; 
	int c = 0;
	for(int i = 0 ; i < lenb; i++){
		int tmp = a[i] - b[i] - c;
		if(tmp < 0)
		{
			tmp += 10;
			c = 1;
		}
		a[i] = tmp;
	}
//	for(int i = 0 ; i < lenb ; i++)
//		cout << a[i];
//		cout << endl;
	
	for(int j = lenb; j < lena ; j++){
		if(c != 0){
			a[j] -= c;
			c = 0;
		}		
	}
	int first = 1;
	for(int i = lena-1; i >= 0; i--){
		if(first && a[i] == 0)
			continue;
		else
			first = 0;
		cout << a[i]; 
	} 
	cout << endl;
	
	return 0;
}
 
