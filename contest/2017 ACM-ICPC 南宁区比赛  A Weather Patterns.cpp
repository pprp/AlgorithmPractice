#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
    double mtx[5][5];
    double ans = 1;
    int neo;

    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            scanf("%lf",&mtx[i][j]);
    getchar();
    int pre, nex;
    pre = -1;
    while(1)
    {
        scanf("%d",&neo);
        char ch = getchar();

        if(pre == -1)
        {
            pre = neo;
        }
        else
        {
            nex = neo;
            ans *= mtx[pre][nex];
            pre = neo;
        }
        if(ch == '\n')
            break;
    }
    printf("%.8lf\n",ans);
    pre = -1;
    ans = 1;

    while(1)
    {
        scanf("%d",&neo);
        char ch = getchar();

        if(pre == -1)
        {
            pre = neo;
        }
        else
        {
            nex = neo;
            ans *= mtx[pre][nex];
            pre = neo;
        }
        if(ch == '\n')
            break;
    }
    printf("%.8lf\n",ans);

    int rec;
    scanf("%d",&rec);
    double pprp = mtx[rec][rec];
    ans = 1;
    double tmp = pprp;
    for(int i = 2;; i++)
    {
        double j = i*tmp;
        if(j < 1e-10)
            break;
        ans += j;
        tmp *= pprp;
    }
    printf("%.8lf\n",ans*(1-pprp));

    scanf("%d",&rec);
    pprp = mtx[rec][rec];
    ans = 1;
    tmp = pprp;
    for(int i = 2;; i++)
    {
        double j = i*tmp;
        if(j < 1e-10)
            break;
        ans += j;
        tmp *= pprp;
    }
    printf("%.8lf\n",ans*(1-pprp));
    return 0;
}
