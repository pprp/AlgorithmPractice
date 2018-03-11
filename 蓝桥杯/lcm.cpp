#include <iostream>

using namespace std;

int gcd(int l, int r){
	return r == 0 ? l : gcd(r,l%r);
} 

int main(){
	int n , m;
	cin >> n >> m;
	cout << m*n/gcd(n, m) << endl;
	
	return 0;
	
} 
