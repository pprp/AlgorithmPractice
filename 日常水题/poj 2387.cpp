/*
@theme:poj 2387
@declare:最短路,从N到1点
@writer:pprp
@date:2017/9/17
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;
int N, T, Min;
const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int mp[maxn][maxn];
bool vis[maxn];
int dis[maxn];

void Dijkstra(int st)
{
    for(int i = 1 ; i <= N; i++)
    {
        dis[i] = mp[st][i];
    }


    vis[st] = 1;
    dis[st] = 0;

    int rec = -1;
    for(int i = 1 ; i <= N ; i++)//起到了循环的作用
    {
        Min = INF;
        rec = -1;
        for(int j = 1; j <= N; j++)
        {
            if(!vis[j] && Min > dis[j])
            {
                rec = j;
                Min = dis[j];
            }
        }
        if(rec == -1)return ;

        vis[rec] = 1;

        for(int j = 1; j <= N; j++)
        {
            if(!vis[j] && mp[rec][j] != INF && dis[rec] + mp[rec][j] < dis[j])
                dis[j] = mp[rec][j] + dis[rec];
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int x, y, v;
    cin >> T >> N;

    for(int i = 0 ; i < maxn; i++)
        for(int j = 0 ; j < maxn; j++)
            mp[i][j] = INF;
    memset(vis,0,sizeof(vis));

    for(int i = 0 ; i < T ; i++)
    {
        cin >> x >> y >> v;
        if(v < mp[x][y])//去重
        mp[x][y] = mp[y][x] = v;
    }

    Dijkstra(N);
    cout << dis[1] << endl;

    return 0;
}
