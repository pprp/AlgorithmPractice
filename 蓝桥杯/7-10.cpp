#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
int a[100002];
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int s1=0,s2=0;
    for(int i=0; i<n/2; i++)
        s1+=a[i];
    for(int i=n/2; i<n; i++)
        s2+=a[i];
    printf("Outgoing #: %d\n",(n+1)/2);
    printf("Introverted #: %d\n",n/2);
    printf("Diff = %d\n",s2-s1);
    return 0;
}

//using namespace std;
//
//int arr[1000000];
//int main(){
//	int n;
//	cin >> n;
//	for(int i = 0 ; i < n ; i++){
//		cin >> arr[i];
//	}
//	sort(arr,arr+n);
//	
//	int s1 = 0, s2 = 0;
//	for(int i= 0 ; i < n/2 ; i++){
//		s1 += arr[i];
//	}	
//	for(int j = n/2+1; j < n ; j++){
//		s2 += arr[j]; 
//	}
//	if(n % 2== 0)
//	{
//		cout << "Outgoing #: " << n/2 << endl;
//		cout << "Introverted #: " << n/2 << endl;
//		cout << abs(s1-s2) << endl;
//	}
//	else
//	{
//		cout << "Outgoing #: " << n/2 << endl;
//		cout << "Introverted #: " << n/2+1 << endl;
//		cout << abs(s1-s2) << endl;
//	}
//	
//	return 0;
//}
//
//
//#include<bits/stdc++.h>
