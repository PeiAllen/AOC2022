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
        stringstream ss(a);
        string las, lbs, ras, rbs;
        getline(ss, las, '-');
        getline(ss, lbs, ',');
        getline(ss, ras, '-');
        getline(ss, rbs);
        int la = stoi(las), lb = stoi(lbs), ra = stoi(ras), rb = stoi(rbs);
        if (ra < la) swap(ra, la), swap(lb, rb);
        if (lb >= ra) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}