//#include <iostream>
//#include <string>
//#include <cstdio>
//
//using namespace std;
//int N,M;
//
//string str[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//string num[5000];
//string cmp[5000];
//
//int Find(char ch)
//{
//    for(int i = 2; i <= 9 ; i++)
//    {
//        if(str[i].find(ch) != string::npos)
//        {
//            return i;
//        }
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    int cas;
//    cin >> cas;
//    while(cas--)
//    {
//        cin >> N >> M;
//        for(int i = 0 ; i < N ; i++)
//        {
//            cin >> num[i];
//        }
//        for(int i = 0 ; i < M ; i++)
//        {
//            cin >> cmp[i];
//            int len = cmp[i].length();
//            for(int j = 0 ; j < len ; j++)
//            {
//                int pprp = Find(cmp[i][j]);
//                cmp[i][j] = '0' + pprp;
//            }
//        }
//        int cnt = 0;
//        for(int i = 0; i < N ; i++)
//        {
//            cnt = 0;
//            for(int j = 0; j < M ; j++)
//            {
//                if(num[i].length() != cmp[j].length())
//                    continue;
//
//                if(num[i] == cmp[j])
//                    cnt++;
//            }
//            cout << cnt << endl;
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char ch[20];
int num[2000000];
int a[10000];

int cc(char str[])
{
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        ans*=10;
        if(str[i]=='a'||str[i]=='b'||str[i]=='c')ans+=2;
        else if(str[i]=='d'||str[i]=='e'||str[i]=='f')ans+=3;
        else if(str[i]=='g'||str[i]=='h'||str[i]=='i')ans+=4;
        else if(str[i]=='m'||str[i]=='n'||str[i]=='o')ans+=6;
        else if(str[i]>='p'&&str[i]<='s')ans+=7;
        else if(str[i]>='t'&&str[i]<='v')ans+=8;
        else if(str[i]>='w'&&str[i]<='z')ans+=9;
        else ans+=5;
    }
    return ans;
}

int main()
{
    int cas;
    int n, m;
    cin >> cas;
    while(cas--)
    {
        cin >> n >> m;
        memset(num,0,sizeof(num));
        for(int i = 0 ; i < n ;i++)
        {
            cin >> a[i];
        }
        getchar();
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%s",ch);
            int pprp = cc(ch);
            num[pprp]++;
        }
        for(int i = 0 ; i < n ; i++)
        {
            cout << num[a[i]] << endl;
        }
    }


    return 0;
}
