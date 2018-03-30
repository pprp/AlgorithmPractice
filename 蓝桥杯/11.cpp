#include <iostream>

using namespace std;

int gcd(int l, int r){
	return r == 0? l : gcd(r,r%l);
}

int main(){
	int a, b, c;
	cin >> a >> b >> c; 
	int t = gcd(a,b);
	t = gcd(t,c);
	cout << t << endl;
	
	return 0;
}
