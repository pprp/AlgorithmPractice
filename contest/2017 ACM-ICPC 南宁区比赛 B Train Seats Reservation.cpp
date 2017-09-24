
//ac B
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 105;
int a[maxn];

int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        if(n==0)
        {
            cout<<"*"<<endl;
            break;
        }

        memset(a,0,sizeof(a));

        while(n--)
        {
            int s,t,k;
            cin>>s>>t>>k;
            a[s]+=k;
            a[t]-=k;
        }
        int ans=0,temp=0;
        for(int i=1; i<=100; i++)
        {
            temp+=a[i];
            ans=max(ans,temp);
        }

        cout<<ans<<endl;
    }
    return 0;
}
