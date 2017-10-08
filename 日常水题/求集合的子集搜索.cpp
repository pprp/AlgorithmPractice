#include <iostream>
#include <cstring>

using namespace std;
int n;
int A[20],vis[20];

void print_subset(int n, int *vis,int cur)
{
    if(cur == n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(vis[i])
                cout << A[i] << " ";
        }
        cout << endl;
        return ;
    }
    vis[cur] = 1;
    print_subset(n,vis,cur+1);
    vis[cur] = 0;
    print_subset(n,vis,cur+1);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++)
        cin >> A[i];
    memset(vis,0,sizeof(vis));
    print_subset(n,vis,0);
    return 0;
}
