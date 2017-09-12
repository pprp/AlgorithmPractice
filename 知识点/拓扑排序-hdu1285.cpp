/*
@theme:拓扑排序 hdu 1285
@writer:pprp
@declare: accepted
@begin:19:00
@end:19:47
@error:
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 518;
bool G[maxn][maxn];
int ans[maxn];
int indegree[maxn];//存取入度
int n, m;

void init()
{
    memset(indegree,0,sizeof(indegree));
    memset(ans,0,sizeof(ans));
    memset(G,0,sizeof(G));
}

void toposort()
{
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ;j <= n ;j++)
        {
            if(G[i][j])
                indegree[j]++;
        }
    }
    //应该从入度为0的开始
    for(int i = 1; i <= n;i++)
    {
        int k = 1;
        while(indegree[k]!=0)
            k++;
        ans[i] = k;
        //删除根节点
        indegree[k] = -1;
        for(int j = 1; j <= n; j++)
        {
            if(G[k][j])
                indegree[j]--;
        }
    }

}

int main()
{
    //freopen("in.txt","r",stdin);
    int x, y;
    while(cin >> n >> m)
    {
        init();
        for(int i = 0 ; i < m ;i++)
        {
            cin >> x >> y;
            G[x][y] = 1;
        }

        toposort();

        for(int i = 1; i < n; i++)
            cout << ans[i] << " ";
        cout << ans[n] << endl;
    }

    return 0;
}
