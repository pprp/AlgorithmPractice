#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <cstdio>

using namespace std;

const int maxn = 100000;
char ch[maxn];
stack <char> st;

long long work()
{
    int len = strlen(ch);
    long long sum = 0;
    for(int i = len-1 ; i >= 0; i--)
    {
        if(ch[i] >= '0' && ch[i] <= '9')
        {
            int record = ch[i] - '0';
            sum += record * pow(16,len-1-i);
        }
        else
        {
            int record = ch[i] - 'A';
            record += 10;
            sum += record * pow(16,len-1-i);
        }
    }
    return sum;
}

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
    int cas;
    cin >> cas;
    while(cas--)
    {
        scanf("%s",ch);
        long long ans = work();
        while(1)
        {
            int div = ans / 8;
            int remain = ans - div * 8;
            Pf(remain);
            ans = div;
            if(div <= 0)
                break;
        }
        while(!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;

    }


    return 0;
}
