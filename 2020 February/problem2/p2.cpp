#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef long long ll;
ll N, K, M; 

bool can(ll x){
    ll curr = N, y, k = 0;
    while(k < K){
        y = curr/x;
        if(y <= M){ curr -= (K-k)*M; break; }

        ll pr = curr-y*x, days = pr/y; 
        
         days++;
        if(k + days > K) days = K-k;
        k += days;
        //cout<<x<<" "<<y<<" "<<pr<<" "<<days<<" "<<K-k<<endl;
        curr -= y*days;   
        if(curr <= 0) return true;
    }
    return curr <= 0; 
}

int main() {
    freopen("p2.in", "r", stdin);
    freopen("p2.out", "w", stdout);
    cin>>N>>K>>M;

    ll lo = 1, hi = N; 
    while(lo < hi){
        ll mid = (lo+hi+1)/2;
        cout<<mid<<endl;
        if(can(mid)) lo = mid;
        else hi = mid-1;
    }
    cout<<lo<<endl;
}
