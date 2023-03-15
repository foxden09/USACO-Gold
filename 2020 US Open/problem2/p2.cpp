#include <iostream>
#include <vector>
#include <map>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
#define INF 1000000007
typedef vector<int> vint;
typedef long long ll;
int N; 

void calc_sums(map<ll, map<ll, ll>>& xy){    
    for(auto &[x, y] : xy){ 
        int prev = 0, tot = 0, i = 0;
        for(pair<int, int> yi : y) tot += yi.first;
        for(auto &[val, sum] : y){
            int diff = val-prev; 
            sum = tot + i*diff - (y.size()-i)*diff;

            tot = sum;
            prev = val;
            i++;
        }
    }
}

int main() {
    freopen("p2.in", "r", stdin);
    freopen("p2.out", "w", stdout);
    cin>>N;
    map<ll,  map<ll, ll>> xcol, yrow;
    FOR(i, N){
        int x, y; cin>>x>>y; x += 10000; y += 10000;
        xcol[x][y] = 0; 
        yrow[y][x] = 0;
    }

    vint rows (N), cols (N);
    calc_sums(xcol); calc_sums(yrow);

    ll ans = 0;
    for(auto& [x, ys] : xcol){
        for(auto& [y, sum] : ys){
            ans += (sum*yrow[y][x])%INF;
        }
    }
    cout<<ans%INF<<endl;
}