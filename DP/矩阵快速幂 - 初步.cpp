/*
@theme:矩阵快速幂
@writer:pprp
@begin:21:45
@end:22:25
@declare:
@date:2017/9/5
*/

#include <bits/stdc++.h>

using namespace std;

int N;

struct Matrix
{
    int a[3][3];
} origin,res;


void Init()
{
    printf("随机数组：\n");
    for(int i = 0 ; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            origin.a[i][j] = 1;
            cout << origin.a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    memset(res.a,0,sizeof(res.a));
    //单位矩阵
    res.a[0][0] =  res.a[1][1] = res.a[2][2] = 1;

}

Matrix multiply(Matrix x, Matrix y)
{
    Matrix tmp;
    memset(tmp.a,0,sizeof(tmp.a));
    for(int i = 0 ; i < 3; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            for(int k = 0 ; k < 3; k++)
            {
                tmp.a[i][j] += x.a[i][k] * y.a[k][j];
            }
        }
    }
    return tmp;
}

//快速幂关键部分
//n为指数
void calc(int n)
{
    int rec = n;
    while(n)
    {
        if(n & 1)
            res = multiply(res,origin);
        n>>=1;
        origin = multiply(origin,origin);
    }
    cout << rec << "次幂的结果如下：" << endl;
    for(int i = 0 ; i < 3; i++)
    {
        for(int j = 0 ; j < 3; j++)
            cout << res.a[i][j] << " ";
        cout << endl;
    }
}



int main()
{

    while(cin >> N)
    {
        Init();
        calc(N);
    }
    return 0;
}
