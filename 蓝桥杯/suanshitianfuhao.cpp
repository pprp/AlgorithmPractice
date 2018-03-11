//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//stringstream ss;
//
//int trans(int a, int b){
//	return a * 10 + b;
//}
//
//string transtoString(string sig, int a, string so){
//	
//	ss << a;
//	
//	string x = ss.str();
//	
//	return sig + x + so;
//}
//
//void dfs(int a[], int k, string so, int goal){
//	
//	if(k == 0){
//		if(a[0] == goal){
//			cout << transtoString("",a[0],so) << endl;
//		}
//		return ;
//	}
//	dfs(a,k-1,transtoString("+",a[k],so),goal-a[k]);
//	dfs(a,k-1,transtoString("-",a[k],so),goal+a[k]);
//	
//	int old = a[k-1];
//
//	a[k-1] = trans(a[k-1],a[k]);
//	dfs(a,k-1,so,goal);	
//	a[k-1] = old;
//}
//
//int main(){
//	int a[] = {1,2,3,4,5,6,7,8,9};
//	dfs(a,8,"",110);
//
//
////	cout << transtoString(33423,"+1234 = 110") << endl;		
//	return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void dfs(int a[],int k,char b[],int goal){
	if(k == 0)
	{
		if(a[0] == goal)
		{
			cout << goal;
			cout << b << endl;		
		}
	}
	char tmp[100];
	tmp = strcat('+',(char)(a[k]+'0'));
	b = strcat(tmp,b);
	dfs(a,k-1,b,goal-a[k]);
	dfs(a,k-1,b,goal+a[k]);
	
	int old = a[k-1];
	a[k-1] = a[k-1] * 10 + a[k];
	
	dfs(a,k-1,b,)
	
}

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	dfs(a,8,"",110);
	
	
	
	return 0;
}
