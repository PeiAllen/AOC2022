#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    ll ans = 0;
    string b, c;
    while (getline(cin, a)) {
        getline(cin, b);
        getline(cin, c);
        map<char, int> cnt;
        for (auto x : a) {
            cnt[x] = min(1, cnt[x] + 1);
        }
        for (auto x : b) {
            if (cnt[x] == 1) cnt[x] = 2;
        }
        for (auto x : c)
            if (cnt[x] == 2) cnt[x] = 3;
        for (auto x : cnt) {
            if (x.second == 3) {
                if (x.first >= 'A' && x.first <= 'Z') {
                    ans += x.first - 'A' + 27;
                } else
                    ans += x.first - 'a' + 1;
            }
        }
    }
    printf("%lli\n", ans);
    return 0;
}