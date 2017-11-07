//×ÖµäÊ÷Ñ§Ï°
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 26;
struct trie
{
    trie* nex[maxn];
    int v;
    bool isEnd;
    trie()
    {
        for(int i = 0 ; i < maxn; i++)
            nex[i] = NULL;
        v = 1;
        isEnd = 0;
        //init as 1 but when it is end, v = -1
    }
};
trie root;

void createTrie(char * str)
{
    int len = strlen(str);
    trie* p = &root, *q;
    for(int i= 0; i < len ; i++)
    {
        int tmp = str[i] - 'a';
        if(p->nex[tmp] == NULL)
        {
            q = new trie;
            p->nex[tmp] = q;
            p = p->nex[tmp];
        }
        else
        {
            p->nex[tmp]->v++;
            p = p->nex[tmp];
        }
    }
    p->isEnd = 1;
}
int findTrie(char *str)
{
    int len = strlen(str);
    trie* p = &root;
    for(int i = 0; i < len ; i++)
    {
        int tmp = str[i]-'a';
        p = p->nex[tmp];
        if(p == NULL)
            return 0;//not exist
    }
    return p->v;//it is prefix of the set
}
int dealTrie(trie * root)
{
    if(root == NULL)
        return 0;
    for(int i = 0 ; i < maxn ; i++)
    {
        if(root->nex[i] != NULL)
            dealTrie(root->nex[i]);
    }
    delete root;
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    char ss[maxn];
    while(gets(ss) && ss[0]!='\0')
        createTrie(ss);
//    while(~scanf("%s",ss) && ss[0] != '\0')
//    {
//        createTrie(ss);
//        printf("%s\n",ss);
//    }
    memset(ss,0,sizeof(ss));
    while(scanf("%s",ss)!= EOF)
    {
        cout << findTrie(ss) << endl;
    }
//    dealTrie(&root);
    return 0;
}
