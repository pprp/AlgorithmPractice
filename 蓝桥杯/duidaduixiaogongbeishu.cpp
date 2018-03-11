#include <iostream>
typedef long long ll;
using namespace std;


int main(){
	ll n;
	cin >> n;

	ll sum = 0;
	if(n <= 2)sum = n;
	else if(n % 2){
		sum = n * (n-1) * (n-2);
	}else
	{
		if(n % 3){
			sum = n * (n-1) * (n-3);
		}
		else
		{
			sum = (n-1) * (n-2) * (n-3);
		}
	}
	cout << sum << endl;
	
	return 0;
}
