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
    int ans = 0;
    while (getline(cin, a)) {
        for (int i = 13; i < sz(a); i++) {
            vector<char> te(a.begin() + i - 13, a.begin() + i + 1);
            sort(te.begin(), te.end());
            te.erase(unique(te.begin(), te.end()), te.end());
            if (sz(te) == 14) {
                ans = i + 1;
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    return 0;
}