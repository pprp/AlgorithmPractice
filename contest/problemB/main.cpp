#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

const int maxn = 100000+100;
typedef long long LL;
priority_queue<LL>que;
int n,T;
int V[maxn];
LL ST;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> V[i];
    ST = 0;
    for (int i=1; i<=n; i++) {
        scanf("%d",&T);
        que.push(-V[i]-ST);
        LL ans = 0;
        while (!que.empty() && que.top()>=(-ST-T)) {
                ans -= que.top()+ST;
                que.pop();
        }
        ST += T;
        ans += 1LL*T*que.size();
        printf("%I64d ",ans);
    }
    return 0;
}
