#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
static const int maxm=1e6+10;
LL tree[maxm],lazy[maxm],A[maxm],left[maxm],right[maxm];
int n,m;
void build(int num,int l,int r)
{
    left[num]=l;
    right[num]=r;
    int mid=(l+r)>>1;
    if(l==r)
    {
        tree[num]=A[l];
        return;
    }
    build(num<<1,l,mid);
    build(num<<1|1,mid+1,r);
    tree[num]=tree[num<<1]+tree[num<<1|1];
}
void pushdown(int num)
{
    if(lazy[num])
    {
        int mid=(left[num]+right[num])>>1;
        tree[num<<1]+=(mid-left[num]+1)*lazy[num];
        tree[num<<1|1]+=(right[num]-mid)*lazy[num];
        lazy[num<<1]+=lazy[num];
        lazy[num<<1|1]+=lazy[num];
        lazy[num]=0;
    }
}
void update(int num,int l,int r,LL add)
{
    if(left[num]>=l&&right[num]<=r)
    {
        tree[num]+=(right[num]-left[num]+1)*add;
        lazy[num]+=add;
        return;
    }
    if(left[num]>r||right[num]<l)return;
    pushdown(num);
    update(num<<1,l,r,add);
    update(num<<1|1,l,r,add);
    tree[num]=tree[num<<1]+tree[num<<1|1];
}
LL Query(int num,int l,int r)
{
    if(left[num]>=l&&right[num]<=r)return tree[num];
    if(left[num]>r||right[num]<l) return 0;
    LL ret=0;
    pushdown(num);
    ret+=Query(num<<1,l,r);
    ret+=Query(num<<1|1,l,r);
    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)scanf("%lld",&A[i]);
    build(1,1,n);
    for(int i=1; i<=m; i++)
    {
        int f,x,y;
        LL add;
        scanf("%d",&f);
        switch(f)
        {
        case 1:
            scanf("%d%d%lld",&x,&y,&add);
            update(1,x,y,add);
            break;
        case 2:
            scanf("%d%d",&x,&y);
            printf("%lld\n",Query(1,x,y));
            break;
        default:
            printf("Orz %%%");
            break;
        }
    }
    return 0;
}
