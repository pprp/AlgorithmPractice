/*
@theme:1003
@declare:The Dominator of Strings
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>


using namespace std;
const int maxn = 100010;
int next[maxn];
char ch[1000][maxn];


//构造next数组
void get_next(char * S, char * P)
{
    int i = 0 ;
    int j = -1;

    int lenp = strlen(P); //要用额外变量，如果写在while循环中就会TLE

    next[0] = -1;

    while(i < lenp)
    {
        if(j == -1 || P[i] == P[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

//开始模式匹配
bool kmp(char * S, char * P)
{
    int i = 0 ;
    int j = 0 ;
    bool tag = 0;

    //要用额外变量，如果写在while循环中就会TLE
    int lens = strlen(S);
    int lenp = strlen(P);

    get_next(S,P);  //这个构造不能忘记写

    while(i < lens && j < lenp)
    {
        if(j == -1 || P[j] == S[i])
        {
            i++;
            j++;
        }
        else
            j = next[j];
        if(j == lenp)
        {
            tag = 1;
            j = next[j];
        }
    }
    if(tag)
        return true;
    else
        return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int cas,T;
    cin >> cas;

    while(cas--)
    {
        cin >> T;
        char * tmp[1000];
        int Max = -10000;
        int rec;
        int cnt = 0;
        int j = 0;

        for(int i = 0; i < T; i++)
        {
            scanf("%s",ch[i]);
            int len = strlen(ch[i]);
            if(Max < len)
            {
                len = Max;
                rec = i;
            }
            tmp[j++] = ch[i];
        }
        bool tag = 0;
        memset(next,0,sizeof(next));
        for(j = 0 ; j < T ; j++)
        {
            cnt = 0;
            for(int i = 0 ; i < T ; i++)
            {
                if(i != rec)
                {
                    if(kmp(tmp[j],ch[i]))
                        cnt++;
                }
            }
            if(cnt == T-1)
            {
                printf("%s\n",tmp[j]);
                tag = 1;
                break;
            }
        }
        if(tag == 0)
            printf("No\n");
    }
    return 0;
}
