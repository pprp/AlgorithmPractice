#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
//bool isprime[1000];
vector<int> prime_factor[1000];

void init(){
	for(int i = 2 ; i <= 1000 ; i++)
	{
		if(prime_factor[i].size() == 0){
			for(int j = i ; j <= 1000; j+= i)
			{
				prime_factor[j].push_back(i); 
			}
		}
	}
	
	return ;
}

int main(){
	init();
	
	for(int i  = 0 ; i < 100 ; i++){
		cout << i << ":"; 
		for(int j = 0 ; j < prime_factor[i].size(); j++)
		{
			cout << prime_factor[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}

