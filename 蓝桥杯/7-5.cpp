#include <iostream>
#include <cstdio>
#include <cstring>

#include <cmath>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		double h, w;
		cin >> h >> w;
		double tmp = (h-100)*0.9;
		tmp *= 2.0;
		if(abs(tmp-w) < tmp*0.1){
			cout << "You are wan mei!" << endl;
		}
		if(w-tmp >= tmp*0.1)
		{
			cout << "You are tai pang le!" << endl;
		}
		if(tmp-w >= tmp * 0.1)
		{
			cout << "You are tai shou le!" << endl;
		}
	}
	return 0;
}
