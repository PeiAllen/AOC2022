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
    vector<vector<char>> arr(10);
    while (1) {
        getline(cin, a);
        if (isdigit(a[1])) break;
        int cnt = 1;
        for (int i = 1; i < sz(a); i += 4) {
            if (a[i] != ' ') {
                arr[cnt].push_back(a[i]);
            }
            cnt++;
        }
    }
    for (int i = 1; i < 10; i++) reverse(arr[i].begin(), arr[i].end());
    getline(cin, a);
    while (getline(cin, a)) {
        stringstream ss(a);
        string gar;
        string vala, valb, valc;
        ss >> gar >> vala >> gar >> valb >> gar >> valc;
        // cout << vala << " " << valb << " " << valc << endl;
        vector<char> te(arr[stoi(valb)].end() - stoi(vala), arr[stoi(valb)].end());
        // reverse(te.begin(), te.end());
        arr[stoi(valb)].resize(int(arr[stoi(valb)].size()) - stoi(vala));
        // cout << sz(arr[stoi(valb)]) << endl;
        arr[stoi(valc)].insert(arr[stoi(valc)].end(), te.begin(), te.end());
    }
    for (int i = 1; i < 10; i++) {
        printf("%c", arr[i].back());
    }
    printf("\n");
    // printf("%d\n", ans);
    return 0;
}