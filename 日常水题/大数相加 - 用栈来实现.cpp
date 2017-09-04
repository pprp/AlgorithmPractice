/*
@theme:big number add
@writer:pprp
@begin:21:27
@end:
@declare:
@error:
@date:2017/9/3
*/

#include <bits/stdc++.h>

using namespace std;
stack <int> arr1;
stack <int> arr2;
stack <int> ans;
string str1;
string str2;

int main()
{
    freopen("in.txt","r",stdin);

    int cas;
    cin >> cas;
    for(int i = 1; i <= cas ; i++)
    {
        while(!arr1.empty())arr1.pop();
        while(!arr2.empty())arr2.pop();
        while(!ans.empty())ans.pop();

        cin >> str1;
        for(int i = 0; i < str1.length(); i++)
            arr1.push(str1[i] - '0');
        cin >> str2;
        for(int i = 0; i < str2.length(); i++)
            arr2.push(str2[i] - '0');
        int jinwei = 0;
        int yuwei = 0;

        while(!arr1.empty() && !arr2.empty())
        {
            int num1 = arr1.top();
            int num2 = arr2.top();
            arr1.pop();
            arr2.pop();

            yuwei = jinwei;
            jinwei = (num1 + num2 + jinwei)/10;
            yuwei = (num1 + num2 + yuwei)%10;

            ans.push(yuwei);
            //cout << yuwei << endl;
        }

        while(!arr1.empty())
        {
            int num = arr1.top();
            arr1.pop();

            yuwei = jinwei;
            jinwei = (num + jinwei)/10;
            yuwei = (num + yuwei) % 10;

            ans.push(yuwei);
        }
         while(!arr2.empty())
        {
            int num = arr2.top();
            arr2.pop();

            yuwei = jinwei;
            jinwei = (num + jinwei)/10;
            yuwei = (num + yuwei) % 10;

            ans.push(yuwei);
        }
        if(jinwei != 0)
            ans.push(jinwei);
        cout << "Case " << i << ":" << endl;
        cout << str1 << " + " << str2 <<"=";

        while(!ans.empty())
        {
            int num = ans.top();
            ans.pop();
            cout << num;
        }
        cout << endl;
        if(i != cas)
        cout << endl;
    }
    return 0;
}
