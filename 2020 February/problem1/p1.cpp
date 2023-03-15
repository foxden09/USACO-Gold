#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
int N, K;
vint tree;

int bessie(int x){
    int xs = 0; vint notx; 
    FOR(i, N){
        xs += tree[i]/x;
        notx.push_back((tree[i]-(tree[i]/x)*x)%x);
    }
    if(xs < K/2) return -1;

    int bx = min(xs-K/2, K/2), bess = bx*x;
    sort(notx.begin(), notx.end(), greater<int>()); 
    FOR(i, min(K/2-bx, (int) notx.size())) bess += notx[i];
    return bess;
}

int main() {
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
    cin>>N>>K;
    tree.resize(N); 
    FOR(i, N) cin>>tree[i];
    sort(tree.begin(), tree.end(), greater<int>());
    
    int ans = 0;
    FOR(i, 1001) ans = max(bessie(i+1), ans);
    cout<<ans<<endl;
}