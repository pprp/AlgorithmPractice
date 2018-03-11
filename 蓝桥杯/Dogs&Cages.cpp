#include <iostream>
#include <cstring>
using namespace std;

int main(){	
	int T;
	cin >> T;
	for(int i = 1 ; i <= T; i++){
		int n;
		cin >> n;
				cout << "Case #" << i << ": ";
		printf("%10f\n",(n-1)*1.0);
	}
	
	return 0;
}
