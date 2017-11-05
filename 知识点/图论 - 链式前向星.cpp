#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
struct node
{
    int to;
    int w;
    int next;
};
int head[maxn];
node e[maxn];

int main()
{
    int vv, ee;
    int x, y, z;
    cin >> vv >> ee;
    memset(head,-1,sizeof(head));
    for(int i = 0 ; i < ee; i++)
    {
        //i是第几条边
        cin >> x >> y >> z;
        e[i].to = y;
        e[i].w = z;
        //第i条边下一个指向起点x所指向的边
        e[i].next = head[x];
        //起点x指向第i条边
        head[x] = i;
    }
    for(int i = 0 ; i < vv; i++)
        cout << head[i] << ' ';
    cout << endl;
    for(int i = 0 ; i < ee; i++)
    {
        cout << i << ":" << e[i].to << " " << e[i].w << " " << e[i].next << endl;
    }
    for(int i = 0 ; i < vv; i++)
        for(int k = head[i]; k != -1 ; k = e[k].next)
            cout << "op:" << k << " ed:" << e[k].to << " w:" << e[k].w << endl;
    return 0;
}
