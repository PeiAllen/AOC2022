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
    vector<string> arr;
    while (getline(cin, a)) {
        arr.push_back(a);
    }
    for(int i=0;i<sz(arr);i++){
        for(int j=0;j<sz(arr[i]);j++){
            ll te=1;
            ll am=0;
            for(int k=j-1;k>=0;k--){
                am++;
                if(arr[i][k]>=arr[i][j]){
                    break;
                }
            }
            te*=am;
            am=0;
            for(int k=j+1;k<sz(arr[i]);k++){
                am++;
                if(arr[i][k]>=arr[i][j]){
                    break;
                }
            }
            te*=am;
            am=0;
            for(int k=i-1;k>=0;k--){
                am++;
                if(arr[k][j]>=arr[i][j]){
                    break;
                }
            }
            te*=am;
            am=0;
            for(int k=i+1;k<sz(arr);k++){
                am++;
                if(arr[k][j]>=arr[i][j]){
                    break;
                }
            }
             te*=am;
            am=0;
            ans=max(ans,te);
        }
    }
    printf("%lli\n",ans);
    return 0;
}