/*
Uva 1585
*/ 

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
	
	int T;
	cin >> T;
	while(T--){
		string tt;
	cin >> tt;
	
	int len = tt.length();
	
	int rec[100];
	
	memset(rec,0,sizeof rec);
	
	for(int i = 0 ; i < len ; i++){
		if(tt[i] == 'O')
		{
			rec[i] = 1;
		}
		else
		{
			rec[i] = 0;
		}
	}
	
	int conticnt = 0;
	int sum = 0;
	
	for(int i = 0 ; i < len ; i++){
		if(rec[i] == 1)
		{
			conticnt++;
			sum += conticnt;
		}
		else
		{
			conticnt = 0;
		}
	}
	
	cout << sum << endl;	
	}
	
		
	return 0;
}
