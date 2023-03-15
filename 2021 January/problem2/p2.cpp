#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
#define F0R(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> v2d;
struct coor{ int c, r; };
bool xcmp(coor& c1, coor& c2){ return c1.c < c2.c; }
bool ycmp(coor& c1, coor& c2){ return c1.r < c2.r; }

int area(int a1, int b1, int a2, int b2, v2d& pfx){
    return pfx[a2][b2]+pfx[a1-1][b1-1]-pfx[a2][b1-1]-pfx[a1-1][b2];
}

int main() {
    freopen("p2.in", "r", stdin);
    freopen("p2.out", "w", stdout);
    int N; cin>>N;
    vector<coor> xc (N);
    FOR(i, N) cin>>xc[i].c>>xc[i].r;
    sort(xc.begin(), xc.end(), ycmp);
    FOR(i, N) xc[i].r = N-i;
    sort(xc.begin(), xc.end(), xcmp);
    FOR(i, N) xc[i].c = i+1;
    
    v2d pfx (N+1, vint(N+1));
    FOR(i, N) pfx[xc[i].r][xc[i].c] = 1;
    //FOR(i, N+1) { FOR(j, N+1) cout<<pfx[i][j]<<" "; cout<<endl; } cout<<endl;
    F0R(i, 1, N+1) F0R(j, 1, N+1){
        pfx[i][j] += pfx[i-1][j]+pfx[i][j-1]-pfx[i-1][j-1];
    }
    //FOR(i, N+1) { FOR(j, N+1) cout<<pfx[i][j]<<" "; cout<<endl; }

    ll ans = 1;
    FOR(i, N){
        for(int j = i; j < N; j++){
            int minr = min(xc[i].r, xc[j].r), maxr = max(xc[i].r, xc[j].r);
            int up = area(1, xc[i].c, minr-1, xc[j].c, pfx);
            int down = area(maxr+1, xc[i].c, N, xc[j].c, pfx);
            //cout<<xc[i].c<<" "<<xc[i].r<<" + "<<xc[j].c<<" "<<xc[j].r<<" : "<<up+1<<" x "<<down+1<<endl;
            ans += (up+1)*(down+1);
        }
    }
    cout<<ans<<endl;
}