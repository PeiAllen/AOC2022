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
    map<int, vector<ll>> monkeys;
    map<int, pair<int, ll>> op;
    map<int, pair<ll, vector<int>>> test;
    string a;
    int cnt = 0;
    map<int, ll> am;
    while (getline(cin, a)) {
        string start, ops, tests;
        getline(cin, start);
        getline(cin, ops);
        getline(cin, tests);
        stringstream items(start.substr(18));
        while (getline(items, a, ',')) {
            monkeys[cnt].push_back(stoll(a));
        }
        op[cnt].first = (ops[23] == '*');
        if (ops.substr(25) == "old") {
            op[cnt].first += 2;
        } else {
            op[cnt].second = stoll(ops.substr(25));
        }
        test[cnt].first = stoll(tests.substr(21));
        getline(cin, tests);
        test[cnt].second.push_back(stoll(tests.substr(29)));
        getline(cin, tests);
        test[cnt].second.push_back(stoll(tests.substr(30)));
        getline(cin, a);
        cnt++;
    }
    ll lcm = 1;
    for (auto x : test) {
        lcm = lcm / gcd(lcm, x.second.first) * x.second.first;
    }
    for (int i = 0; i < 10000; i++) {
        for (int monk = 0; monk < cnt; monk++) {
            am[monk] += sz(monkeys[monk]);
            for (auto x : monkeys[monk]) {
                if (op[monk].first == 0) {
                    x += op[monk].second;
                } else if (op[monk].first == 1) {
                    x *= op[monk].second;
                } else if (op[monk].first == 2) {
                    x += x;
                } else {
                    x *= x;
                }
                x %= lcm;
                monkeys[test[monk].second[!!(x % test[monk].first)]].push_back(x);
            }
            monkeys[monk] = vector<ll>();
        }
    }
    vector<ll> vals;
    for (auto x : am) {
        vals.push_back(x.second);
    }
    sort(vals.begin(), vals.end(), greater<>());
    printf("%lli\n", vals[0] * vals[1]);
    return 0;
}