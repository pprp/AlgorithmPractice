#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
struct node
{
    int to;
    int w;
    node(int tt, int ww):to(tt),w(ww){}
};
bool cmp(node n1, node n2)
{
    if(n1.to == n2.to)
        return n1.w < n2.w;
    return n1.to < n2.to;
}
int main()
{
    vector<node> vt[maxn];
    int vv, ee;
    int ff, tt, ww;
    cin >> vv >> ee;
    for(int i = 0 ; i < ee ; i++)
    {
        cin >> ff >> tt >> ww;
        node nn(tt,ww);
        vt[ff].push_back(nn);
    }
    for(int i = 0 ; i < vv; i++)
    {
        sort(vt[i].begin(),vt[i].end(),cmp);
    }
    for(int i = 0 ; i < vv; i++)
    {
        if(vt[i].size() > 0)
        {
            for(size_t j = 0 ; j < vt[i].size(); j++)
            {
                cout << "op:" << i << " ed:" << vt[i][j].to << " w:" << vt[i][j].w << endl;
            }

        }
    }
    return 0;
}
