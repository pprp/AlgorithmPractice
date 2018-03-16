#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ji = 0;
	int ou = 0;
	for(int i = 0 ; i< n ; i++){
		int tmp;
		cin >> tmp;
		if(tmp & 1)
		ji++;
		else
		ou++;
	}
	cout <<ji << " " << ou << endl;
	
	
	return 0;
}
