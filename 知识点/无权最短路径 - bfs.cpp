/*
@theme:无权最短路径问题
@complexity:O(|E| + |V|)
@writer:pprp
@begin:21:10
@end:21:53
@error:
@declare: breadth first search
@date:2017/9/13
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100;
const int INF = 10000;
vector<int> vt[maxn];
queue<int> qu;
int dis[maxn];
int vis[maxn];
int stpt, vertex, path;


void init()
{
    for(int i = 0 ; i < maxn; i++)
        dis[i] = INF;
    memset(vis,0,sizeof(vis));
}

void BFS(int v)
{
    dis[v] = 0;
    qu.push(v);
    vis[v] = 1;
    while(!qu.empty())
    {
        v = qu.front();
        qu.pop();
        for(int i = 0 ; i < (int)vt[v].size(); i++)
        {
            if(dis[vt[v][i]] == INF)
            {
                dis[vt[v][i]] = dis[v] + 1;
                qu.push(vt[v][i]);
            }
        }
    }

}

int main()
{
    freopen("in.txt","r",stdin);
    init();
    cin >> vertex >> path;
    int x, y;
    for(int i = 0 ; i < path ; i++)
    {
        cin >> x >> y;
        vt[x].push_back(y);
    }
    cin >> stpt;
    BFS(stpt);

    for(int i = 1 ; i < vertex; i++)
        cout << dis[i] << " ";
    cout << endl;

    return 0;
}
