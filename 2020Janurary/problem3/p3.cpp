#include <iostream>
#include <vector>
#include <string>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
vint e; 
int get(int x){ return e[x]<0 ? x : e[x] = get(e[x]); }
void unite(int a, int b){
    int x = get(a), y = get(b);
    if(x == y) return;
    if(e[y] < e[x]) swap(x, y);
    e[x] += e[y]; e[y] = x;
}

int main() {
    freopen("p3.in", "r", stdin);
    freopen("p3.out", "w", stdout);
    int N, M; cin>>N>>M;
    string cow; cin>>cow; 
    e = vint(N, -1);
    FOR(i, N-1){
        int a, b; cin>>a>>b; a--; b--;
        if(cow[a] == cow[b]) unite(a, b);
    }
    FOR(i, M){
        int a, b; cin>>a>>b; a--; b--;
        char c; cin>>c; 
        if(get(a)==get(b) && cow[a] != c) cout<<'0';
        else cout<<'1'; 
    } 
}
