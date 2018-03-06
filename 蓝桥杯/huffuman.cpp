#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector> 

using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

int main(){
//	int a[1000];
//	srand(0);
//	for(int i = 0 ; i < 10; i++)
//	{
//		int t = rand();
//		pq.push(t);
//		cout << t << endl;
//	}
//	cout << endl;
//	while(!pq.empty()){
//		cout << pq.top() << endl;
//		pq.pop();
//	}
	int n;
	cin >> n;
	for(int i = 0; i < n  ; i++){
		int t;
		cin >> t;
		pq.push(t);
	}
	int sum = 0;
	while(pq.size() > 1){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int add = a+b;
//		cout << add << endl;
		pq.push(add);
		sum += add;		
	}
//	sum += pq.top();
	cout << sum << endl;
	return 0;
} 
