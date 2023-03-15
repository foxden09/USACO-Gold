#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef long long ll;
typedef pair<ll, ll> myp;
vector<myp> inv;
ll N, M;

bool can(ll d){
    ll prev = -1e18, ans = 0;
    FOR(i, M){
        ll me = max(prev+d, inv[i].first); 
        if(me > inv[i].second) continue;
        ll rng = inv[i].second-me;
        ans += rng/d+1;
        prev = (rng/d)*d+me;
    }
    return ans >= N;
}

int main() {
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
    cin>>N>>M;
    inv.resize(M);
    FOR(i, M) cin>>inv[i].first>>inv[i].second;
    sort(inv.begin(), inv.end());

    ll lo = 1, hi = 1e18;
    while(lo < hi){
        ll mid = (lo+hi+1)/2;
        if(can(mid)) lo = mid;
        else hi = mid-1;
    }
    cout<<lo<<endl;
}