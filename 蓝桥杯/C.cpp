#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int N = 1000;
vector<int> prime_factor[1000];

void init(){
	int tmp;
	for(int i = 2;  i <= N ; i++){
		if(prime_factor[i].size() == 0){
			for(int j = i ; j <= N; j+=i){
				tmp = j;
				while(tmp % i == 0){
					prime_factor[j].push_back(i);
					tmp /= i;
				}
			}
		}
	}
}

int main(){
	init();	
	
	for(int i = 2 ; i <= 100 ; i++){
		cout << i << ":";
		for(int j = 0 ;j < prime_factor[i].size() ; j++){
			cout << prime_factor[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
