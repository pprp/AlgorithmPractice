#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib> 
using namespace std;


char str[100];

char M[] = {'1','0','X','9','8','7','6','5','4','3','2'}; //0-10

int power[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

int main(){
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0 ; i < n; i++){
		cnt = 0;
		scanf("%s",str);
//		cout << str[i] << endl;
		int tmp = 0;
		for(int j = 0 ; j < 17; j++){
			tmp	+= (str[j]-'0') * power[j];
			
//			cout << str[j] << "++++" << power[j] << endl;
		}
//		cout << tmp << endl; 
		tmp %= 11;
//		cout << tmp << endl;
		if(str[17] != M[tmp])
		{
			cout << str << endl;
			cnt--;
		}
	}
	
//	cout << cnt << endl; 
	
	if(cnt == 0)
	{
		cout << "All passed" << endl;
	}
	
	
	return 0;
}
