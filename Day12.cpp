#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }
int xc[4] = {1, -1, 0, 0}, yc[4] = {0, 0, 1, -1};
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<string> grid;
    vector<vector<int>> dist;
    string a;
    pii start, en;
    while (getline(cin, a)) {
        for (int i = 0; i < sz(a); i++) {
            if (a[i] == 'S') {
                a[i] = 'a';
                start = {sz(grid), i};
            }
            if (a[i] == 'E') {
                a[i] = 'z';
                en = {sz(grid), i};
            }
        }
        grid.push_back(a);
        dist.push_back(vector<int>(sz(a), INT_MAX));
    }
    queue<pii> q;
    q.push(en);
    dist[en.first][en.second] = 0;
    while (sz(q)) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii nx = {cur.first + xc[i], cur.second + yc[i]};
            if (nx.first >= 0 && nx.first < sz(grid) && nx.second >= 0 && nx.second < sz(grid[0])) {
                if (grid[nx.first][nx.second] >= grid[cur.first][cur.second] - 1 && dist[nx.first][nx.second] > dist[cur.first][cur.second] + 1) {
                    dist[nx.first][nx.second] = dist[cur.first][cur.second] + 1;
                    q.push(nx);
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < sz(grid); i++) {
        for (int j = 0; j < sz(grid[0]); j++) {
            if (dist[i][j] != INT_MAX && grid[i][j] == 'a') {
                ans = min(ans, dist[i][j]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}