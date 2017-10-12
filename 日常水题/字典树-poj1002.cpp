
//数字树 - 字典树
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
bool findsolve = false;

struct trie
{
    bool isEnd;//标记结束
    int cnt;//标记数量
    trie * next[11];//标记下一个结点
    trie()
    {
        isEnd = false;
        cnt = 0;
        for(int i = 0 ; i < 10; i++)
            next[i] = NULL;
    }
};
trie * root = new trie;

void Insert(char * s)
{
    int len = strlen(s);
//    cout << len << endl;
    trie *p = root, *nw;
    for(int i = 6 ; i >= 0 ; i--)
    {
        if(p->next[s[i]-'0'] == NULL)
        {
            nw = new trie;
            p->next[s[i]-'0'] = nw;
        }
        p = p->next[s[i]-'0'];
    }
    p->isEnd = true;
    p->cnt++;
}

//test:ok
int trans(char *s)
{
    int x = 0;
    int len = strlen(s);
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i] == '-')
            continue;
        x *= 10;
        if(s[i] >= 'A' && s[i] <= 'Y')
            x += (s[i]-'A'-(s[i]>'Q'))/3+2;
        else if(s[i] >= '0' && s[i] <= '9')
            x += s[i]-'0';
    }
    return x;
}

void dfs(trie* p,int m,char phone[9])
{
    if(p->isEnd == true)
    {
        if(p->cnt > 1)
        {
            for(int i = 1; i <= 7 ; i++)
            {
                if(i == 4)
                    printf("-");
                printf("%c",phone[i]);
            }
            printf(" %d\n",p->cnt);
            findsolve = true;
        }
        return ;
    }

    for(int i = 0 ; i < 10 ; i++)
    {
        if(p->next[i] != NULL)
        {
            phone[m+1] = (char)(i+'0');
            dfs(p->next[i],m+1,phone);
        }
    }
    return ;
}

int main()
{
    char phone[100];
//    freopen("in.txt","r",stdin);
//    cin.sync_with_stdio(false);
    int n, num;
//    cin >> n;
    scanf("%d",&n);
    char ch[100];
    for(int i = 0 ; i < n; i++)
    {
        scanf("%s",ch);
        num = trans(ch);
        //test:ok
        char ans[100];
        int j = 0;
        if(num == 0)
        {
            for(int i = 0 ; i <= 6; i++)
            {
                ans[i] = '0';
            }
            ans[7] = '\0';
            Insert(ans);
        }
        else
        {
            while(num)
            {
                int a = num % 10;
                ans[j++] = (char)(a+'0');
                num /= 10;
            }
            ans[j] = '\0';
            Insert(ans);//插入树中
        }
    }
    dfs(root,0,phone);
    if(!findsolve)
        printf("No duplicates.\n");
    return 0;
}
