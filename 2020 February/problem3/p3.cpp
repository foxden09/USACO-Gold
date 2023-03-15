#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
struct hole{ int a, b, w; 
    bool operator<(const hole& r)const{ return w < r.w; }};
int N, M;

vint e; 
int get(int x){ return e[x]<0 ? x : e[x] = get(e[x]); }
void unite(int a, int b){
    int x = get(a), y = get(b);
    if(x == y) return;
    if(e[y] < e[x]) swap(x, y);
    e[x] += e[y]; e[y] = x;
}

bool can(int x, vector<hole>& h, vint& cows){
    e = vint(M+1, -1);
    for(int i = x; i < M; i++){
        unite(h[i].a, h[i].b);
    }
    FOR(i, N){
        if(cows[i] == i+1) continue;
        if(get(i+1) != get(cows[i])) return false;
    }
    return true;
}

int main() {
    freopen("p3.in", "r", stdin);
    freopen("p3.out", "w", stdout);
    cin>>N>>M;
    vint cows (N);
    FOR(i, N) cin>>cows[i];
    vector<hole> h (M); 
    FOR(i, M) cin>>h[i].a>>h[i].b>>h[i].w;
    sort(h.begin(), h.end());

    int lo = 0, hi = M; 
    while(lo < hi){
        int mid = (lo+hi+1)/2;
        if(can(mid, h, cows)) lo = mid;
        else hi = mid-1;
    }
    if(h[lo].w == 0) cout<<-1<<endl;
    else cout<<h[lo].w<<endl;
}