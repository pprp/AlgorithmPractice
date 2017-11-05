//writer:pprp
//前向星表示
//注意：点的编号也是从0开始的，不能从1开始
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1000;
struct node
{
    int op,ed,w;
};
node e[maxn];
int head[maxn];
bool cmp(node n1, node n2)
{
    if(n1.op == n2.op && n1.ed == n2.ed)
        return n1.w < n2.w;
    if(n1.op == n2.op)
        return n1.ed < n2.ed;
    return n1.op < n2.op;
}
int main()
{
    int vv, ee;
    cin >> vv >> ee;
    for(int i = 0; i < ee; i++)
        cin >> e[i].op >> e[i].ed >> e[i].w;
    sort(e,e+ee,cmp);
    memset(head,-1,sizeof(head));
    head[e[0].op] = 0;
    for(int i = 0 ; i < ee ; i ++)
    {
        if(e[i].op != e[i-1].op)
            head[e[i].op] = i;
    }

    for(int i = 0; i < vv; i++)
    {
        for(int k = head[i]; e[k].op == i && k < ee; k++)
        {
            cout <<"op:" << e[k].op << " ed:" << e[k].ed << " w:" << e[k].w << endl;
        }
    }

    return 0;
}
