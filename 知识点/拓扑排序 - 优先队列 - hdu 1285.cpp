/*
@theme:拓扑排序 hdu 1285
@writer:pprp
@declare: accepted
@begin:19:59
@end:20:38
@error:注意保持头脑清醒
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;
const int maxn = 520;
int indegree[maxn];
int n, m, x, y;

bool G[maxn][maxn];

void topsort()
{
    priority_queue<int,vector<int>,greater<int> > pq;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(G[i][j])
                indegree[j]++;

    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0)
            pq.push(i);

    int counter = 1;

    while(!pq.empty())
    {
        int v = pq.top();
        pq.pop();

        if(counter != n)
        {
            cout << v << " ";
            counter++;
        }
        else
        {
            cout << v << endl;
            break;
        }

        for(int i = 1; i <= n;i++)
        {
            if(G[v][i] == 1)
            {
                indegree[i]--;
                if(indegree[i] == 0)
                    pq.push(i);
            }
        }
    }
    if(counter != n)
        cerr << "graph has a cycle." << endl;
}

void init()
{
    memset(indegree,0,sizeof(indegree));
    memset(G,0,sizeof(G));
}

int main()
{
    freopen("in.txt","r",stdin);
    while(cin >> n >> m)
    {
        init();
        for(int i = 0 ; i < m ; i++)
        {
            cin >> x >> y;
            G[x][y] = 1;
        }
        topsort();
    }

    return 0;
}

