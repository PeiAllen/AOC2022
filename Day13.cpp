#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }
vector<vector<int>> pain;
int solve(string a, int &i) {
    if (a[i] == '[') {
        if (a[i + 1] == ']') {
            i += 2;
            pain.push_back(vector<int>());
            return sz(pain) - 1;
        }
        int cur = sz(pain);
        pain.push_back(vector<int>());
        while (a[i] != ']') {
            i++;
            int te = solve(a, i);
            pain[cur].push_back(te);
        }
        i++;
        return cur;
    } else {
        int cur = i;
        while (isdigit(a[i])) {
            i++;
        }
        return -stoi(a.substr(cur, i - cur));
    }
}
int work(int a, int b) {
    for (int i = 0; i < min(sz(pain[a]), sz(pain[b])); i++) {
        if (pain[a][i] <= 0 && pain[b][i] <= 0) {
            if (abs(pain[a][i]) < abs(pain[b][i])) return 1;
            if (abs(pain[a][i]) > abs(pain[b][i])) return -1;
        } else if (pain[a][i] <= 0) {
            pain.push_back(vector<int>{pain[a][i]});
            int te = work(sz(pain) - 1, pain[b][i]);
            if (te) return te;
        } else if (pain[b][i] <= 0) {
            pain.push_back(vector<int>{pain[b][i]});
            int te = work(pain[a][i], sz(pain) - 1);
            if (te) return te;
        } else {
            int te = work(pain[a][i], pain[b][i]);
            if (te) return te;
        }
    }
    if (sz(pain[a]) < sz(pain[b])) return 1;
    if (sz(pain[a]) == sz(pain[b])) return 0;
    return -1;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a, b;
    ll sum = 0;
    pain.push_back(vector<int>());
    vector<int> packets;
    int ii = 0, jj = 0;
    int d1 = solve("[[2]]", ii);
    int d2 = solve("[[6]]", jj);
    packets.push_back(d1);
    packets.push_back(d2);
    while (getline(cin, a)) {
        getline(cin, b);
        int i = 0, j = 0;
        packets.push_back(solve(a, i));
        packets.push_back(solve(b, j));
        getline(cin, a);
    }
    sort(packets.begin(), packets.end(), [&](const auto &lhs, const auto &rhs) {
        return work(lhs, rhs) == 1;
    });
    ll ans = 1;
    for (int i = 0; i < sz(packets); i++) {
        if (packets[i] == d1) {
            ans *= (i + 1);
        }
        if (packets[i] == d2) {
            ans *= (i + 1);
        }
    }
    printf("%lli\n", ans);
    return 0;
}