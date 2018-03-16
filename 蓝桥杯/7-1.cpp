#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	int liang1,liang2;
	cin >> liang1 >> liang2;
	int n;
	cin >> n;
	
	int tmpa = liang1, tmpb = liang2;
	
	int ahan,bhan,ahua,bhua;
	
	int tag = 0;
	
	for(int i = 0 ; i < n ; i++){
		cin >> ahan >> ahua >> bhan >> bhua;
		if(ahan+bhan == ahua && ahan+bhan != bhua){
			tmpa -= 1;
		}
		if(ahan+bhan == bhua && ahan+bhan != ahua){
			tmpb -= 1; 
		}
		if(ahan+bhan == bhua && ahan+bhan == ahua){
			tmpa -= 1;
			tmpb -= 1;
		}

		if(tmpa == 0){			
			tag  = 1;
			break;
		}
		if(tmpb == 0){
			tag = -1;
			break;
		}
	}
	
	if(tag == 1)
	{
		cout << 'A' << endl;
		cout << liang2 - tmpb<< endl;
	}
	
	if(tag == -1)
	{
		cout << 'B' << endl;
		cout << liang1 - tmpa << endl;
	}
	
	
	return 0;
} 


#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,a,b,c,d,ma,mb,na,nb;
	scanf("%d%d%d",&na,&nb,&num);
	ma=na;
	mb=nb;
	while(num--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b==a+c&&d!=a+c){
			ma--;
		}else if(b!=a+c&&d==a+c){
			mb--;
		}
		if(ma==-1){
			printf("A\n%d",nb-mb);
			break;
		}else if(mb==-1){
			printf("B\n%d",na-ma);
			break;
		}
	}
	return 0;
}
