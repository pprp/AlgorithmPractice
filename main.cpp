#include <iostream>
#include <algorithm>
#include <cstdio>
#include<iomanip>  


using namespace std;

const int maxn = 1010;

class mouse
{
public:
    int j;
    int f;
    int divide;
};

bool cmp(mouse m1,mouse m2)
{
    if(m1.divide > m2.divide)
        return true;
    else
        return false;
}

int main()
{
    int m,n;

    mouse mou[maxn];
    while(cin >> m >> n &&  m != -1 && n != -1)
    {
        double lp = 0;
        for(int i = 0 ; i < n ; i++)
        {
            mou[i].f = 0;
            mou[i].j = 0;
            mou[i].divide = 0;
        }

        for(int i = 0 ; i < n ; i++)
        {
            cin >> mou[i].j>>mou[i].f;
            mou[i].divide = mou[i].j/mou[i].f;
        }

        sort(mou,mou+n,cmp);

        for(int i = 0 ; i <n ; i++)
        {
            if(m >= mou[i].f)
            {
                m -= mou[i].f;
                lp += mou[i].j;

            }
            else
            {
                lp += mou[i].j*(m/(double)mou[i].f);
            }
        }
        printf("%.3f\n",lp);
    }


    return 0;
}
