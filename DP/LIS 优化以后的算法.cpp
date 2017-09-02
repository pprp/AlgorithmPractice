/*
@theme:tmp最长上升子序列
@writer:pprp
@begin:10:00
@end:14:32
@declare复杂度为O(n^2)
@error:dp[i] = MAX(dp[j]+1,dp[i]),dp[i] = 1初始化为1
@date:2017/9/2
*/

#include <bits/stdc++.h>

using namespace std;

int arr[10010],tmp[10010];
int len;

/*
状态定义：用到tmp数组
tmp[i]:代表的是对于所有长度为i的LIS,他的结果最小有可能是多少，
       如果越小那就越容易被取到
tmp中的元素是严格递增的
状态转移：
        if( dp[j] = i )
            tmp[i] = min(arr[j])
结果查找--用二分的方法去找
if(tmp[i] < arr[n] && tmp[i+1] >= arr[n] )
    f[n] = i+1 .... i 代表的是长度

*/

//二分查找,在tmp中进行二分查找arr[i]
//对tmp数组进行更新
void bisearch(int x)
{
    int left=1,mid,right=len;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(tmp[mid]<x)
            left=mid+1;
        else
            right=mid-1;
    }
    tmp[left]=x;
}

int main()
{
    int N;
    while(cin >> N && N)
    {
        len=1;
        cin >> arr[0];
        tmp[len]=arr[0];

        for(int i=1; i<N; i++)
        {
            scanf("%d",&arr[i]);

            if(arr[i] > tmp[len])//如果当前i指向的arr的值大于tmp当前的值
            {
                len++;
                tmp[len]=arr[i];
            }//向tmp数组中加入arr的值
            else
                bisearch(arr[i]);//在tmp中进行查找找到的就将其更新
            //如果用lower_bound的话就这样：
            //*lower_bound(tmp,tmp+len,arr[i]) = arr[i];
        }
        printf("%d\n",len);
    }
    return 0;
}
