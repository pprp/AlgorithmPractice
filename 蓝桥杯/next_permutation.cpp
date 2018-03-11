#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

bool check(){
	bool b1 = (a[0]+a[1]==a[2]);
	bool b2 = (a[3]-a[4]==a[5]);
	bool b3 = (a[6]*a[7]==a[8]);
	bool b4 = (a[10]*a[11]==a[9]);
	if(b1&&b2&&b3&&b4)
		return true;
	else
		return false;
}

int main(){
	int res  = 0;
	do
	{
		if(check()){
			res++;
		}
	}while(next_permutation(a,a+13));
	
	cout << res << endl;
	
	return 0;
} 
