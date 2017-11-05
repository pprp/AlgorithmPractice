### 拓扑排序
#### writer：pprp

#### 分析：
建立一个队列，将所有入度为0的节点放到队列中

输出该节点，更新与其相连的其他点的入度

再次将所有更新节点中入度为0的点加入队列
#### 算法思路：
每次选取一个入度为0的点，将其从该图中删除，再按照以上步骤进行依次删除，如果不能删除那么说明存在环状结构导致没有入度为0的点，将每次删除的点记录在一个vector数组中，最后进行输出

#### 代码如下：


```
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
//图的拓扑排序
using namespace std;
const int maxn = 1000;
int vv,ee;
struct node
{
    int to;
    int w;
    int next;
};
queue <int> qu;

node edge[maxn];
int head[maxn];
int indegree[maxn];
/*
@declare：
建立一个队列，将所有入度为0的节点放到队列中
输出该节点，更新与其相连的其他点的入度
再次将所有更新节点中入度为0的点加入队列
*/
vector <int> vt;
void dfs()
{
    int cnt = 0;
    for(int i = 0 ; i < vv ; i++)
        if(indegree[i] == 0)
        qu.push(i), vt.push_back(i);

    while(!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        for(int k = head[x]; k != -1 ; k = edge[k].next)
        {
            indegree[edge[k].to]--;
            if(indegree[edge[k].to] == 0)
            {
                qu.push(edge[k].to);
                vt.push_back(edge[k].to);
            }
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int x, y,z ;
    cin >> vv >> ee;
    memset(head,-1,sizeof(head));
    memset(indegree,0,sizeof(indegree));
    for(int i = 0 ; i < ee; i++)
    {
        cin >> x >> y >> z;
        edge[i].to = y;
        edge[i].w = z;
        edge[i].next = head[x];
        head[x] = i;
        indegree[y]++;
    }
    dfs();
    for(int i = 0; i < vt.size(); i++)
        cout << vt[i] << " ";
    cout << endl;

    return 0;
}

/*
9 8
0 1 1
0 2 1
0 3 1
1 4 1
2 5 1
2 6 1
3 7 1
3 8 1
*/

```
