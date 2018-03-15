#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
vector<int> factor[1000];
int main(){
	for(int i = 2 ; i <= 1000 ; i++){
		for(int j = i ; j <= 1000; j += i){
			factor[j].push_back(i);
		}
	}
	
	for(int i = 2 ; i < 100; i++){
		cout << i << ":";
		for(int j = 0 ; j < factor[i].size(); j++){
			cout << factor[i][j] << " ";
		}
		cout << endl; 
	}
	return 0;
} 
