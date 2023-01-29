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
    ll cycle = 1;
    ll val = 1;
    queue<pair<ll, ll>> toadd;
    while (getline(cin, a)) {
        stringstream ss(a);
        string x, y;
        ss >> x;
        if (x == "addx") {
            ss >> y;
            for (int i = 0; i < 2; i++) {
                if (abs(val - (cycle - 1) % 40) <= 1) {
                    printf("#");
                } else {
                    printf(".");
                }
                cycle++;
                if ((cycle - 1) % 40 == 0) printf("\n");
            }
            // printf("%lli\n", stoll(y));
            val += stoll(y);
        } else {
            if (abs(val - (cycle - 1) % 40) <= 1) {
                printf("#");
            } else {
                printf(".");
            }
            cycle++;
            if ((cycle - 1) % 40 == 0) printf("\n");
        }
    }
    printf("%lli\n", ans);
    return 0;
}