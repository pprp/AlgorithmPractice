#include <iostream>
using namespace std;

long long a, b, ans;
int nCase, cCase;

long long calc(long long a, long long b) {
    long long ret = 0;
    while (b) {
        long long t = b;
        ret += a / b;
        b = a % b;
        a = t;
    }
    return ret + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> nCase;
    while (nCase--) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            ans = 1;
        } else if (a == 0 || b == 0) {
            ans = 2;
        } else {
            ans = calc(a, b);
        }
        cout << "Case #" << ++cCase << ": " << ans << endl;
    }
    return 0;
}
