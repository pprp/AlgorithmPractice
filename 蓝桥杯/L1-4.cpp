#include <bits/stdc++.h>

using namespace std;

int main(){
  // freopen("in.txt","r",stdin);
  int cnt = 1;
  string str;
  string name2 = "000",name14 = "000";
  while(cin >> str && str != "." && cnt < 16){
    if(cnt == 2){
      name2 = str;
    }else if(cnt == 14){
      name14 = str;
    }
    cnt++;
  }
  if(name2 == "000" && name14 == "000"){
    cout << "Momo... No one is for you ..." << endl;
  }
  else if(name14 == "000" && name2 != "000"){
    cout << name2 << " is the only one for you..." << endl;
  }
  else if(name2 != "000" && name14 != "000")
  {
    cout << name2 << " and " << name14 << " are inviting you to dinner..." << endl;
  }
return 0;
}

#include <stdio.h>
int main () {
	int i;
	char name[15][11];
	for ( i = 1; i < 15; i++ ) { //最多读取14个人，多余没用
		scanf("%s", name[i]);
		if ( name[i][0] == '.' ) //若碰到'.',就结束读入
			break;
	}
	// i - 1 即读入的有用人数
	if ( i - 1 < 2 )
		printf("Momo... No one is for you ...");
	else if ( i - 1 < 14 )
		printf("%s is the only one for you...", name[2]);
	else
		printf("%s and %s are inviting you to dinner...", name[2], name[14]);
 	return 0;
}


// #include <iostream>
// using namespace std;
//
// int main(){
//   string str = "I Love GPLT";
//   for(int i = 0 ; i < str.length(); i++)
//   {
//     cout << str[i] << endl;
//   }
//   return 0;
// }
