#include <iostream>
#include <cstdio> 
#include <cstring>
#include <stack>

using namespace std;
char ch[1000];
stack <int> st;

string dpj(int n){
	if(n == 0)
		return "ling";
	else if(n == 1)
		return "yi";
	else if(n == 2)
		return "er";
	else if(n == 3)
		return "san";
	else if(n == 4)
		return "si";
	else if(n == 5)
		return "wu";
	else if(n == 6)
		return "liu";
	else if(n == 7)
		return "qi";
	else if(n == 8)
		return "ba";
	else 
		return "jiu";
}

int main(){
	scanf("%s",ch);
	int len = strlen(ch);
	int sum = 0;
	for(int i = 0; i < len ; i++){
		sum += (int)(ch[i]- '0');
	}
//	cout << sum << endl;
	while(sum){
		st.push(sum%10);
		sum /= 10;
	}
//	bool t = 1;
	cout << dpj(st.top());
	st.pop(); 
	while(!st.empty()){
		cout << " " << dpj(st.top());
		st.pop();
	}

	return 0; 
}
 
