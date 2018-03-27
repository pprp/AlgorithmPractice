#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
bool flag;
int main()
{
    char a[10005],b[10005];
    gets(a);
    gets(b);
    int len1=strlen(a),len2=strlen(b);
    int i,j;
    for(i=0; i<len1; i++)
    {
        flag=true;
        for(j=0; j<len2; j++)
        {
            if(b[j]==a[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<a[i];
    }
    cout<<endl;
    return 0;
}
