// #include <bits/stdc++.h>
//
// using namespace std;
//
// stack<char> st[10000];
//
// int main(){
//   int n;
//   cin >> n;
//   string line;
//   getchar();
//   getline(cin,line);
//   int len = line.length();
//   int cnt;
//
//   if(len%n==0)
//     cnt = len/n;
//   else
//     cnt = len/n+1;
//
//   for(int i = 0 ; i < cnt*n ; i++){
//     if(i < len)
//     st[i%n].push(line[i]);
//     else
//     st[i%n].push(' ');
//   }
//   for(int i = 0 ; i < n; i++)
//   {
//     while(!st[i].empty()){
//       cout << st[i].top();
//       st[i].pop();
//     }
//     cout << endl;
//   }
//
//   return 0;
// }


// #include <bits/stdc++.h>
//
// using namespace std;
//
// int main()
// {
//   int hh, mm;
//   scanf("%d:%d",&hh,&mm);
//   if(hh >= 0 && hh <= 12)
//   {
//     printf("Only %02d:%02d.  Too early to Dang.\n",hh,mm);
//     return 0;
//   }
//   else
//   {
//     if(mm > 0){
//         for(int i = 0 ; i < hh-12+1; i++){
//           cout << "Dang";
//         }
//         cout << endl;
//     }
//     else
//     {
//       for(int i = 0 ; i < hh-12; i++){
//         cout << "Dang";
//       }
//       cout << endl;
//     }
//   }
//   return 0;
// }
