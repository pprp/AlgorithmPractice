#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

char a[maxn],b[maxn];
int x[maxn+10],y[maxn+10],z[maxn*2+10];

int len1, len2;
int main(){
	int i, j;
	memset(a,0,sizeof a);
 	memset(b,0,sizeof b);
 	memset(x,0,sizeof x);
 	memset(y,0,sizeof y);
 	memset(z,0,sizeof z);
	scanf("%s %s",a,b);
 	len1 = strlen(a);
 	len2 = strlen(b);
// 	cout << a << " " << b << endl;
 	for(j = 0 , i = len1-1; i>=0 ; i--)x[j++] = a[i] - '0';
 	for(j = 0 , i = len2-1; i>=0 ; i--)y[j++] = b[i] - '0';
 	for(i = 0 ; i < len1; i++){
 		for(j = 0 ; j < len2; j++){
 			z[i+j] = z[i+j] + x[i] * y[j];
		 }
	 }
	for(int ii = 0 ; ii < maxn * 2; ii++){
		if(z[ii] >= 10)
		{
			z[ii+1] = z[ii+1] + z[ii]/10;
			z[ii] = z[ii] % 10;
		}
	}
	
//	for(int k = 0 ; k < maxn ; k++){
//		cout << z[k];
//	}
//	cout << endl;
	
	for(i = maxn * 2; i>0;i--){ //É¾³ýÇ°µ¼0 
		if(z[i] == 0)
			continue;
		else
			break;
	}
	for(; i>= 0; i--)
		cout << z[i];
	cout << endl;	
	return 0;
}
