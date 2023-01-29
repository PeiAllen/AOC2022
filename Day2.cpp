#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }
int am[3][3];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    ll ans = 0;
    while (getline(cin, a)) {
        ans += (a[0] - 'A' + (a[2] - 'Y') + 3) % 3 + 1;
        ans += (a[2] - 'X') * 3;
    }
    printf("%lli\n", ans);
    return 0;
}