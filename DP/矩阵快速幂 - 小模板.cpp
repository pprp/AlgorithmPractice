/*
@theme:矩阵快速幂二
@writer:pprp
@end:19:25
@declare:注意边长的赋值
@date:2017/9/6
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 100;

class Matrix
{
public:
    int data[N][N];
    int len;
    //judge 如果真就是单位矩阵，否则是普通矩阵
    void Init(bool judge,int Size)
    {
        len = Size;
        memset(data,0,sizeof(data));
        if(judge)
        {
            for(int i = 0 ; i < len ; i++)
                data[i][i] = 1;
        }
        else
        {
            cout << "array is : " << endl;
            for(int i = 0 ; i < len ; i++)
            {
                for(int j = 0 ; j < len ; j++)
                {
                    data[i][j] = rand()%5;
                    //data[i][j] = 1;
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    void input()
    {
        for(int i = 0 ; i < len; i++)
        {
            for(int j = 0 ; j < len; j++)
            {
                cin >> data[i][j];
            }
        }
    }
};

Matrix multiply(const Matrix& A, const Matrix& B)
{
    Matrix tmp;
    tmp.len  = A.len;
    memset(tmp.data,0,sizeof(tmp.data));

    for(int i = 0; i < tmp.len ; i++)
    {
        for(int j = 0 ; j < tmp.len ; j++)
        {
            for(int k = 0 ; k < tmp.len; k++)
                tmp.data[i][j] += A.data[i][k] * B.data[k][j];
        }
    }
    return tmp;
}


void calc(int n,Matrix res, Matrix origin)
{
    int rd = n;
    int len = res.len;
    while(n)
    {
        if(n & 1)
            res = multiply(res,origin);
        n>>=1;
        origin = multiply(origin,origin);
    }
    cout << rd << "次幂的结果如下：" << endl;
    for(int i = 0 ; i < len; i++)
    {
        for(int j = 0 ; j < len; j++)
            cout << res.data[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    int len;
    cout << "请输入矩阵的边长：" << endl;
    cin >> len;
    Matrix origin, res;
    origin.Init(false,len);
    res.Init(true,len);
    cout << "请输入矩阵的元素："<< endl;
    origin.input();
    cout << "请输入矩阵的幂次："<< endl;
    int nn;
    cin >> nn;
    calc(nn,res,origin);

    return 0;
}
