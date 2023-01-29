#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }
map<int, vector<int>> to;
map<int, map<string, int>> value;
map<int, ll> sizes;
set<int> bad;
int dfs(int loc) {
    if (sizes.count(loc)) {
        return abs(sizes[loc]);
    }
    for (auto x : to[loc]) {
        sizes[loc] += dfs(x);
    }
    return sizes[loc];
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    // int ans = 0;
    vector<int> locations = {0};
    int positions = 1;
    getline(cin, a);
    while (getline(cin, a)) {
        if (a[0] == '$') {
            if (a[2] == 'c') {
                string name = a.substr(5);
                if (name == "..") {
                    locations.pop_back();
                    continue;
                } else if (name == "/") {
                    locations = vector<int>();
                    locations.push_back(0);
                    continue;
                }
                if (!value[locations.back()].count(name)) {
                    value[locations.back()][name] = positions++;
                    to[locations.back()].push_back(value[locations.back()][name]);
                }
                locations.push_back(value[locations.back()][name]);
            } else {
            }
        } else {
            if (a[0] == 'd') {
                string name = a.substr(4);
                if (!value[locations.back()].count(name)) {
                    value[locations.back()][name] = positions++;
                    to[locations.back()].push_back(value[locations.back()][name]);
                }
            } else {
                stringstream ss(a);
                string length;
                ss >> length;
                string name;
                ss >> name;
                if (!value[locations.back()].count(name)) {
                    value[locations.back()][name] = positions++;
                    to[locations.back()].push_back(value[locations.back()][name]);
                }
                bad.insert(value[locations.back()][name]);
                sizes[value[locations.back()][name]] = -ll(stoll(length));
            }
        }
    }
    dfs(0);
    ll total = sizes[0];
    ll left = 70000000 - total;
    ll needed = 30000000 - left;
    ll ans = LLONG_MAX;
    for (auto x : sizes) {
        if (!bad.count(x.first) && x.second >= needed) {
            ans = min(ans, x.second);
        }
    }
    printf("%lli\n", ans);
    return 0;
}