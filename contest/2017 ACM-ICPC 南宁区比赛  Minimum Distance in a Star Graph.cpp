#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>

using namespace std;

string sa, sb;

int n;

struct node
{
    string str;
    int times;
    node()
    {
        str = "";
        times = 0;
    }
};

int bfs()
{
    queue<node> q;
    set<string> ss;
    node now , nex;
    now.str = sa;
    q.push(now);
    ss.insert(now.str);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        if(now.str == sb)
            return now.times;
        for(int i = 1; i < n;i++)
        {
            nex.str = now.str;
            nex.times = now.times+1;
            nex.str[i] = now.str[0];
            nex.str[0] = now.str[i];
            if(ss.count(nex.str) == 0)
            {
                ss.insert(nex.str);
                q.push(nex);
            }
            else
                continue;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < 5 ;i++)
    {
        cin >> sa >> sb;
        cout << bfs() << endl;
    }


    return 0;
}
