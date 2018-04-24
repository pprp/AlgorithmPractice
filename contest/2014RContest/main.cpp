#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
int main()
{
    ll tmp;
    int T;
    cin >> T;
    for(int qq = 1 ; qq <= T; qq++)
    {

        int n;
        cin >> n;
        bool tag = 1;
        for(int i = 0 ; i < n ; i++)
        {
             cin >> tmp;
             if(tmp % 3 != 0)tag = 0;
        }
        printf("Case #%d: ",qq);
        if(!tag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}
