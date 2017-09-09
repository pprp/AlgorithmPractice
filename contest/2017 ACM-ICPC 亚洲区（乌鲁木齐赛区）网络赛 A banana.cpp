#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn = 55;
int N, M;

struct node
{
    int val;
    node * next;
};

node* head1[maxn];
node* head2[maxn];

bool ans[maxn][maxn];

void create()
{
    memset(ans,0,sizeof(ans));
    for(int i = 1 ; i < maxn ; i++)
        head1[i] = NULL,head2[i] = NULL;
    int st, ed;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> st >> ed;
        node *tmp = new node();
        tmp->next = NULL;
        if(head1[st] == NULL)
        {
            head1[st] = tmp;
            tmp->val = ed;
        }
        else
        {
            node * p = head1[st];
            while(p->next != NULL)
                p = p->next;
            p->next = tmp;
            tmp->val = ed;
        }
    }
    for(int i = 1 ; i <= M ; i++)
    {
        cin >> st >> ed;
        node * tmp = new node();
        tmp->next = NULL;
        if(head2[st] == NULL)
        {
            head2[st] = tmp;
            tmp->val = ed;
        }
        else
        {
            node * p = head2[st];
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = tmp;
            tmp->val = ed;
        }
    }
}

void fun()
{
    node * p, * q;
    int rec_st, rec_ed;
    for(int i = 1 ; i <= N ; i++)
    {
        p = head1[i];
        while(p != NULL)
        {
            rec_st = p->val;
            q = head2[rec_st];
            while(q != NULL)
            {
                rec_ed = q->val;
                ans[i][rec_ed] = true;
                q = q->next;
            }
            p = p->next;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    cin >> cas;
    while(cas--)
    {
        cin >> N >> M;
        create();
        fun();
        for(int i = 1; i < maxn ; i++)
        {
            for(int j = 1 ; j < maxn ; j++)
            {
                if(ans[i][j] == true)
                    cout << i << " " << j << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
