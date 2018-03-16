#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char ch[10000];
int main(){
	scanf("%s",ch);
	int len = strlen(ch);
	int cnt[4] = {0};
	for(int i = 0; i < len ; i++){
		if(ch[i] == 'g' || ch[i] == 'G')cnt[0]++;
		if(ch[i] == 'p' || ch[i] == 'P')cnt[1]++;
		if(ch[i] == 'l' || ch[i] == 'L')cnt[2]++;
		if(ch[i] == 't' || ch[i] == 'T')cnt[3]++;
	}
	int min = 1000;
	for(int i = 0 ; i< 4; i++){
//		cout << cnt[i] << endl;
		if(min > cnt[i]){
			min = cnt[i];
		}
	}
	
	while(cnt[0] != 0 && cnt[1] != 0 || cnt[2] != 0 || cnt[3] != 0){
		if(cnt[0] != 0){
			cout << "G";
			cnt[0]--; 
		}
		if(cnt[1] != 0){
			cout << "P";
			cnt[1]--; 
		}if(cnt[2] != 0){
			cout << "L";
			cnt[2]--; 
		}if(cnt[3] != 0){
			cout << "T";
			cnt[3]--; 
		}
		
	}	
	return 0;
}
