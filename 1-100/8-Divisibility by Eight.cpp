#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    for(int i = a.size()-1; i >= 0 ; i--)
    {
        if(a[i] == '8')
        {
            cout << "YES" << endl;
            cout << 8;
            return 0;
        }
        if(a[i] == '0')
        {
            cout << "YES" << endl;
            cout << "0";
            return 0;
        }
    }
    for(int i = a.size()-1; i>=0; i--)
    {
        for(int j = i-1; j>=0; j--)
        {
            if((a[i]-'0'+(a[j]-'0') * 10) % 8 == 0)
            {
                cout << "YES" << endl;
                cout << a[i]-'0' + (a[j]-'0') * 10;
                return 0;
            }

        }
    }

    for(int i = a.size()-1; i >= 0; i--)
    {
        for(int j = i-1; j >= 0; j--)
        {
            for(int k = j-1 ; k >= 0 ; k--)
            {
                if((a[i]-'0'+(a[j]-'0')*10+(a[k]-'0')*100)%8==0)
                {
                    cout<<"YES"<<endl;
                    cout<<a[i]-'0'+(a[j]-'0')*10+(a[k]-'0')*100;
                    return 0;
                }

            }
        }
    }
    cout << "NO";

    return 0;
}
