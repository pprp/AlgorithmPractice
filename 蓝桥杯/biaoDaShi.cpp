#include <iostream>
#include <stack>


using namespace std;

stack<char>s1;
stack<char>s2;

int priority(char ch){
	if(ch == '(' || ch == ')')
	return 1;
	if(ch == '+' || ch == '-')
	return 2;
	if(ch == '*' || ch == '/')
	return 3;
}

int calc(int a, int b, char op){
	if(op == '+')
	return b+a;
	if(op == '-')
	return a-b;
	if(op == '*')
	return a*b;
	if(op == '/'&& b != 0)
	return a/b; 
}

int main(){
	string str;
	cin >> str;
	
	
	//transform
	for(int i = 0 ; i < str.length(); i++){
		if(str[i]>= '0' && str[i] <= '9'){
			s1.push(str[i]);
			if(i == str.length()-1 || [i+1]<'0'||str[i+1]>'9'){
				s1.push('#');
			}
		}
		else
		{
			if(s2.empty() || str[i] == '(' || priority(str[i]) > priority(s2.top())){
				s2.push(str[i]);
			}
			else if(str[i] == ')')
			{
				while(s2.top())!='('){
					s1.push(s2.top());
					s2.pop(); 
				}
			}
		}
	}
	
	
	return 0;
}
