//http://blog.csdn.net/creatorx/article/details/71100840
#include <iostream>
#include <cstdio>
#include <cstring>
//ac 自动机
using namespace std;
const int maxn = 26;
char s[100005];
char keyword[55];
struct node
{
    node * next[maxn];
    node * fail;
    int sum;//相应的个数
    node()
    {
        for(int i = 0 ; i < maxn; i++)
            next[i] = NULL;
        fail = NULL;
        sum  = 0;
    }
};
node * q[500005];
node * root;

void Build_Trie(char * s)
{
    node * p = root;
    int len = strlen(s);
    for(int i = 0 ; i < len ; i++)
    {
        int tmp = s[i]-'a';
        if(p->next[tmp] == NULL)
        {
            node *newnode = new node;
            p->next[tmp] = newnode;
        }
        p = p->next[tmp];
    }
    p->sum++;
}
void build_fail_pointer()
{
    int head = 0;
    int tail = 0;
    q[head++] = root;
    node * p, *tmp;
    while(head != tail)
    {
        tmp = q[tail++];
        for(int i = 0 ; i < maxn; i++)
        {
            if(tmp->next[i] != NULL)
            {
                //所有第一层的点都要指向root
                if(tmp == root)
                {
                    tmp->next[i]->fail = root;
                }
                else
                {
                    p = tmp->fail;
                    while(p != NULL)
                    {
                        if(p->next[i] != NULL)
                        {
                            tmp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL)
                        tmp->next[i]->fail = root;
                }
                q[head++] = tmp->next[i];
            }
        }
    }
}

int query(node * root)
{
    int i, v, cnt = 0;
    node *p = root;
    int len = strlen(s);
    for(int i = 0 ; i < len; i++)
    {
        v = s[i]-'a';
        while(p->next[v] == NULL && p!=root)
            p = p->fail;
        p = p->next[v];
        if(p == NULL)
            p = root;
        node * tmp = p;
        while(tmp != root)
        {
            if(tmp->sum >= 0)
            {
                cnt += tmp->sum;
                tmp->sum = -1;
            }
            else
                break;
            tmp = tmp->fail;
        }
    }
    return cnt;
}
int main()
{
    int T, n;
    scanf("%d",&T);
    while(T--)
    {
        root = new node;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%s",keyword);
            Build_Trie(keyword);
        }
        build_fail_pointer();
        scanf("%s",s);
        printf("%d\n",query(root));
    }
    return 0;
}
