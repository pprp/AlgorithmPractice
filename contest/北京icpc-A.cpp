#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 200;
int a[maxn];
bool vis[maxn];
int ansl, ansr;
struct node
{
    int index;
    int val;
};
node rec[maxn];

int main()
{
//    freopen("in.txt","r",stdin);
    int n, m;
    int num;
    int tmp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,1,sizeof(vis));
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&num);
        for(int i = 0 ; i < num ; i++)
        {
            scanf("%d",&tmp);
            vis[tmp] = 0;
        }
        //枚举起点
        int st, i;
        int ans = 10000;
        for(st = 0 ; st <= n-m; st++)
        {
            int vie = 0;
            if(vis[st]==0)
                continue;
            int cnt = 0;
            for(i = st; i < st+m+vie && i < n ; i++)
            {
                if(vis[i])
                    cnt++;
                if(vis[i] == 0)
                    vie++;
            }
            int len = m + vie;
            if(cnt != m)
                continue;
            //下标:
//            cout << st << " " << st + len - 1 <<endl;
//            cout << "len:" << len << endl;
            int j = 0 ;
            for(i = 0 ; i <= len-1; i++)
            {
                if(vis[st+i])
                {
                    rec[j].index = st+i;
                    rec[j++].val = a[st+i];
                }
            }
//            cout << "test:" << j << endl;
//            for(i = 0 ; i < j; i++)
//                cout << rec[i].val << " ";
//            cout << endl;
            //开始枚举
            int ss;
            for(ss = 1; ss < j; ss++)
            {
                if(ans > rec[0].val + rec[ss].val)
                {
                    ans = rec[0].val+rec[ss].val;
                    ansl = rec[0].index;
                    ansr = rec[ss].index;
                }
            }
//            cout << ans << endl;
        }
        cout << ansl << " " << ansr << endl;
    }

    return 0;
}
