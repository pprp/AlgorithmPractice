#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string mode[12];

bool judge1(string str){
	for(int i = 0 ; i < str.length() ; i++)
	{
		if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T')
			return false;
	}
	return true;
}

bool judge2(string str){
	int len = str.length();
	int i = 0 ; 
	int j = 0 ;
	 
	
}

bool judge3(string str){
	
}

int main(){
	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> mode[i];
	}
	
	return 0;
}
