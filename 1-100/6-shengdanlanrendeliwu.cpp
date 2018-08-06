#include<stdio.h>
#include<iostream>
#include <algorithm>

using namespace std;

#define MAXN (100+10)

struct Box
{
    int v,w;
    double density;
};

int n, w;

Box boxes[MAXN];

double totw, totv;

bool operator < (const Box & a, const Box & b)
{
    return a.density < b.density;
}

int main()
{
    cin >> n >> w;
    for(int i = 0 ; i < n ; i++){
        cin >> boxes[i].v >> boxes[i].w;
        boxes[i].density = boxes[i].v * 1.0 / boxes[i].w;
    }
    sort(boxes,boxes+n);
    for(int i = n-1; i >= 0 ; i--)
    {
        if(totw+boxes[i].w <= w)
        {
            totw += boxes[i].w;
            totv += boxes[i].v;
        }
        else
        {
            totv += boxes[i].density * (w - totw);
            totw = w;
            break;
        }
    }
    cout << totv << endl;

}
/*
int main()
{
    scanf("%d%d",&n,&w);

    for(int i = 0 ; i < n; i++)
    {
        scanf("%d%d",&boxes[i].v,&boxes[i].w);
        boxes[i].density = 1.0 * boxes[i].v / boxes[i].w;
    }
    sort(boxes,boxes+n);
    totw = totv = 0;

    for(int i = n-1; i >= 0 ; i--)
    {
        if(totw+boxes[i].w <= w)
        {

            totw += boxes[i].w;
            totv += boxes[i].v;
        }
        else
        {
            totv += boxes[i].density * (w-totw);
            totw = w;
            break;
        }
    }
    printf("%.11f\n",totv);

    return 0;
}
*/
