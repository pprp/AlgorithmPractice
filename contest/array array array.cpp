#include <bits/stdc++.h>

using namespace std;

int arr1[100005],tmp1[100005],arr2[100005], tmp2[100005];
int len1,len2;

int main()
{
    int cas;
//    cin >> cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int N, K;
//        cin >> N >> K;
        scanf("%d%d",&N,&K);
        len1=1, len2 = 1;
        for(int i = 0 ; i < N ; i++)
        {
             scanf("%d",&arr1[i]);
        }
        for(int i = N - 1; i >= 0; i--)
        {
            arr2[i] = arr1[N-i];
        }
        tmp1[len1] = arr1[0];
        tmp2[len2] = arr2[0];

        for(int i=1; i<N; i++)
        {
            if(arr1[i] > tmp1[len1])//如果当前i指向的arr的值大于tmp当前的值
            {
                len1++;
                tmp1[len1]=arr1[i];
            }
            else
                *lower_bound(tmp1,tmp1+len1,arr1[i]) = arr1[i];
        }

        for(int i = 1; i < N ; i++)
        {
            if(arr2[i] > tmp2[len2])
            {
                len2++;
                tmp2[len2] = arr2[i];
            }
            else
                *lower_bound(tmp2,tmp2+len2,arr2[i]) = arr2[i];
        }

        int cmp = N - K;
        if(cmp > len1 && cmp > len2)
            cout << "A is not a magic array." << endl;
        else
            cout << "A is a magic array." << endl;
    }
    return 0;
}
