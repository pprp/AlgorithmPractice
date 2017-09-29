#include <iostream>
#include <cstring>
//八进制转化为十进制

using namespace std;
int arr[31];
int cnt = 0;

void cont(int n)
{
    cnt = 0;
    while(n)
    {
        arr[cnt++] = n % 10;
        n /= 10;
    }
    for(int i = 0 ; i < cnt ; i++)
    {
        if(arr[i] >= 9)
        {
            arr[i] -= 2;
        }
        else if(arr[i] >= 4)
        {
            arr[i] -= 1;
        }
    }

}

int main()
{
    long long x;
    while(cin >> x && x)
    {
        int ans = 0;
        memset(arr,0,sizeof(arr));
        cont(x);

//        for(int i = 0 ; i < cnt; i++)
//            cout << arr[i] << " ";
//        cout << endl;
//        cout << "cnt:" << cnt << endl;

        for(int i = cnt-1; i >= 0; i--)
        {
            ans *= 8;
            ans += arr[i];
        }
        cout << x << ": " << ans << endl;
    }

    return 0;
}
