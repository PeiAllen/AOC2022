#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    vector<ll> ma;
    ll cur = 0;
    while (getline(cin, a)) {
        if (a.size() == 0) {
            ma.push_back(cur);
            cur = 0;
        } else {
            cur += stoi(a);
        }
    }
    ma.push_back(cur);
    sort(ma.begin(), ma.end(), greater<>());
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += ma[i];
    }
    printf("%lli\n", ans);
    return 0;
}