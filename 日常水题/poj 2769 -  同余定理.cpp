#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int people[330];
bool vis[1000010];
bool judge[1000010];

int main()
{
    int cas;
    scanf("%d",&cas);
    int num;
    while(cas--)
    {
        scanf("%d",&num);
        memset(judge,0,sizeof(judge));
        for(int i = 0 ; i < num ; i++)
            scanf("%d",&people[i]);
        //¼ôÖ¦
        for(int i = 0 ; i < num ; i++)
            for(int j = 0 ; j < num ; j++)
                judge[abs(people[i]-people[j])] = 1;
        //Ã¶¾Ù
        int k;
        for(k = 1 ;; k++)
        {
            if(!judge[k])
            {
                bool isfind = true;
                memset(vis,0,sizeof(vis));
                for(int i = 0 ; i < num ; i++)
                {
                    if(vis[people[i]%k])
                    {
                        isfind = false;
                        break;
                    }
                    vis[people[i]%k] = 1;
                }
                if(isfind)
                {
                    printf("%d\n",k);
                    break;
                }
            }
        }
    }
    return 0;
}
