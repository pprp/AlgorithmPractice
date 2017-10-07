#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char A[10005];
char B[10005];
int fa, fb;
void swap(char *a, int i, int j)
{
    char t = a[i]-'0';
    a[i] = a[j]-'0';
    a[j] = t;
}
void add(char *a, char *b)
{
    int la = strlen(a),lb = strlen(b);
    int i,j,c=0,s,l;
    for(i=fa,j=la-1; i<=j; ++i,--j) swap(a,i,j);
    for(i=fb,j=lb-1; i<=j; ++i,--j) swap(b,i,j);
    for(i=fa; i<la||i<lb; ++i)
    {
        s = a[i] + b[i] + c;
        c = s/10;
        a[i] = s%10;
    }
    a[i] = c;
    l = c ? i : i-1;
    if(fa) printf("-");
    for(i=l; i>=fa; --i) printf("%d", a[i]);
}

int cmp(char *a, char *b)
{
    int i,j,la,lb;
    la = strlen(a);
    lb = strlen(b);
    if(la-fa>lb-fb)
        return 1;
    else if(la-fa<lb-fb)
        return 0;
    else
    {
        for(i=0; i<la&&a[i+fa]==b[i+fb]; ++i);
        return a[i+fa]>b[i+fb];
    }
}
void minus(char *a, char *b)
{
    char *t;
    int i,j,ft,la,lb,c,l,s;
    if(!cmp(a,b))
    {
        t=a;
        a = b;
        b = t;
        ft = fa;
        fa = fb;
        fb = ft;
    }
    la = strlen(a);
    lb = strlen(b);
    for(i=fa,j=la-1; i<=j; ++i,--j) swap(a,i,j);
    for(i=fb,j=lb-1; i<=j; ++i,--j) swap(b,i,j);
    c = 0;
    l = -1;
    for(i=0; i+fa<la; ++i)
    {
        s = a[i+fa]-b[i+fb]-c>=0 ? 0 : 1;
        a[i+fa] = (10+a[i+fa]-b[i+fb]-c)%10;
        l = a[i+fa] ? i+fa : l;
        c = s;
    }
    if(l<0)
        printf("0");
    else
    {
        if(fa) printf("-");
        for(i=l; i>=fa; --i) printf("%d", a[i]);
    }
}
int main()
{
    scanf("%s%s", A, B);
    fa = ('-'==A[0]);
    fb = ('-'==B[0]);
    if(fa^fb)
        minus(A,B);
    else
        add(A,B);
}
