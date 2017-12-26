#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>

using namespace std;
stack<char>st;

void Pf(int i)
{
    if(i >= 0 && i <= 9)
    {
        st.push((char)i+'0');
    }
    else
    {
        st.push((char)(i-10+'A'));
    }
}

int main()
{
    int n;
    cin >> n;
    while(1)
    {
        int div = n/16;
        int remain = n - div*16;
        Pf(remain);
        n = div;
        if(div <= 0)
            break;
    }

    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0;
}
