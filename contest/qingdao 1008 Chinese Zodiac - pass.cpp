#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

string str[12] = {"rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog","pig"};

int main()
{
    //freopen("in.txt","r",stdin);
    int cas;
    cin >> cas;
    while(cas--)
    {
        string st1,st2;
        cin >> st1 >> st2;
        int num1, num2;
        for(int i = 0 ; i < 12; i++)
        {
            if(st1 == str[i])
                num1 = i;
            if(st2 == str[i])
                num2 = i;
        }
//        cout << num1 <<" " << num2 << endl;
        if(num1 == num2 )
            cout << 12 << endl;
        else if(num1 > num2)
        {
            int Min = 12-abs(num1-num2);
            cout << Min << endl;
        }
        else
        {
            cout << num2-num1 << endl;
        }

    }
    return 0;
}
