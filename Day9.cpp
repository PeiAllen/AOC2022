#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename T>
int sz(const T &a) { return int(a.size()); }
map<string,pii> change={{"R",{0,1}},{"L",{0,-1}},{"D",{1,0}},{"U",{-1,0}}};
int xc[8]={1,-1,0,0,1,-1,1,-1};
int yc[8]={0,0,1,-1,1,-1,-1,1};
int dist(pii a, pii b){
    return max(abs(a.first-b.first),abs(a.second-b.second));
}
int sdist(pii a, pii b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    set<pii> pos;
    vector<pii> loc;
    for(int i=0;i<10;i++){
        loc.push_back({0,0});
    }
    while (getline(cin, a)) {
        stringstream ss(a);
        string dir,value;
        ss>>dir>>value;
        for(int k=0;k<stoi(value);k++){            
            loc[0].first+=change[dir].first;
            loc[0].second+=change[dir].second;
            for(int j=1;j<10;j++){
                if(dist(loc[j-1],loc[j])>1){
                    bool done=false;
                    for(int i=0;i<4;i++){
                        pii nxt={loc[j].first+xc[i],loc[j].second+yc[i]};
                        if(sdist(loc[j-1],nxt)<=1){
                            done=true;
                            loc[j]=nxt;
                            break;
                        }
                    }
                    if(!done){
                        for(int i=4;i<8;i++){
                            pii nxt={loc[j].first+xc[i],loc[j].second+yc[i]};
                            if(dist(loc[j-1],nxt)<=1){
                                loc[j]=nxt;
                                break;
                            }
                        }
                    }
                }
            }
            // printf("%d %d %d %d\n",loc.first,loc.second,tail.first,tail.second);
            pos.insert(loc[9]);
        }
    }
    printf("%d\n",sz(pos));
    return 0;
}