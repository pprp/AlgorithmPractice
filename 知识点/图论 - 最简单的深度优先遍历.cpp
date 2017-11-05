### 深度搜索 - 链式前向星表示法

#### writer：pprp

#### 分析：
- 参数：当前节点的标号为dfs的参数
- 注意：要另外开一个VIS数组进行涂色，涂过色的就不要再涂色了
- head数组应该全置-1，VIS数组全置0
- 遍历的条件应该注意一下 k = edge[k].next

##### 代码如下：

```
#include <iostream>
#include <cstring>
#include <cstdio>
//图的遍历
using namespace std;
const int maxn = 1000;
int vv,ee;
struct node
{
    int to;
    int w;
    int next;
};

node edge[maxn];
int head[maxn];
bool vis[maxn];

//顶点
void dfs(int x)
{
    vis[x] = 1;
    cout << x << endl;
    for(int k = head[x]; k != -1; k = edge[k].next)
    {
        if(!vis[edge[k].to])
            dfs(edge[k].to);
    }
}

int main()
{
    int x, y,z ;
    cin >> vv >> ee;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    for(int i = 0 ; i < ee; i++)
    {
        cin >> x >> y >> z;
        edge[i].to = y;
        edge[i].w = z;
        edge[i].next = head[x];
        head[x] = i;
    }
    dfs(0);
    return 0;
}

```
