#include <iostream>
#include <stack>
#include <cstring>
#define MAXN 100

using namespace std;

int count = 0;

int stamps[3][4] =
{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
};

int index[3][4],temp[3][4];

int dir[4][2] =
{
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};

typedef struct
{
    int i,j;
    int data;
    int pre;
} Box;

typedef struct
{
    Box data[MAXN];
    int front,rear;
} Queue;

Queue bfs(int x,int y)
{
    Queue qu;
    int m,n;
    qu.front = -1;
    qu.rear = 0;
    qu.data[qu.rear].data = stamps[x][y];
    qu.data[qu.rear].pre = -1;
    qu.data[qu.rear].i = x;
    qu.data[qu.rear].j = y;
    qu.rear++;
    qu.front++;
    memset(index,0,48);
    index[x][y] = 1;
    while(x>-1 && x<3 && y>-1 && y<4)
    {
        for(int i = 0; i<4; i++)
        {
            m = x;
            n = y;
            m += dir[i][0];
            n += dir[i][1];
            if(m>=0 && m<=2 && n>=0 && n<= 3 && index[m][n] == 0)
            {
                qu.data[qu.rear].data = stamps[m][n];
                qu.data[qu.rear].pre = qu.front;
                qu.data[qu.rear].i = m;
                qu.data[qu.rear].j = n;
                index[m][n] = 1;
                qu.rear++;
            }
        }
        qu.front++;
        x = qu.data[qu.front].i;
        y = qu.data[qu.front].j;
    }
    return qu;
}

bool Check(int i,int j)
{
    if(i>=0 && i<=2 && j>=0 &&j<=3)
        return true;
    return false;
}

void bfs(stack<int> s,int s1,int s2,int e1,int e2,int k)
{
    int n;
    if(s1 == e1 && s2 == e2)
    {
        if(s.size() == 5){
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
        }
        if(k == 5)
            count++;
        return;
    }
    else
    {
        for(n=0; n<4; ++n)
        {
            if(Check(s1+dir[n][0],s2+dir[n][1]) && temp[s1+dir[n][0]][s2+dir[n][1]] != -1)
            {
                temp[s1][s2] = -1;
                k++;
                s.push(stamps[s1][s2]);
                bfs(s,s1+dir[n][0], s2+dir[n][1],e1,e2,k);
                k--;
                temp[s1][s2] = 0;
            }
        }
    }
}

int main()
{
    int k = 1;
    for(int m = 0; m < 3; m++)
    {
        for(int n = 0; n<4; n++)
        {
            Queue q = bfs(m,n);
            memset(temp,0,48);
            for(int i = 0; i<q.rear; i++)
            {
                stack<int> s;
                bfs(s,q.data[m].i,q.data[n].j,q.data[i].i,q.data[i].j,k);
                //cout<<q.data[i].i<<"  "<<q.data[i].j<<"  "<<q.data[i].pre<<"  "<<q.data[i].data<<endl;
            }
        }
    }
    /*Queue q = bfs(0,0);
    memset(temp,0,48);
    for(int i = 0; i<q.rear; i++)
    {
        bfs(q.data[0].i,q.data[0].j,q.data[i].i,q.data[i].j,k);
        //cout<<q.data[i].i<<"  "<<q.data[i].j<<"  "<<q.data[i].pre<<"  "<<q.data[i].data<<endl;
    }*/
    cout<<count;
    return 0;
}

