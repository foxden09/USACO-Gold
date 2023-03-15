#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
typedef vector<vint> v2d;
vint used; 
int sums[2], sumc[2];

//lesson: try smaller cases first
//bipartate graph
void dfs(int i, v2d& nbors, vint& clr, vint& clock){
    used[i] = true;
    sumc[clr[i]] += clock[i];
    sums[clr[i]]++;
    for(int n : nbors[i]){
        if(!used[n]){
            clr[n] = !clr[i];
            dfs(n, nbors, clr, clock);
        }
    }
}

int main() {
    freopen("p3.in", "r", stdin);
    freopen("p3.out", "w", stdout);
    int N; cin>>N;
    vint clock (N), clr (N); clock = vint(N); used = vint(N);
    FOR(i, N) cin>>clock[i];
    v2d nbors (N); 
    FOR(i, N-1){
        int a, b; cin>>a>>b; a--; b--;
        nbors[a].push_back(b);
        nbors[b].push_back(a);
    }
    dfs(0, nbors, clr, clock);
    FOR(i, 2){
        sumc[i] %= 12; 
        if(sumc[i]==0) sumc[i] = 12;
    }

    if(sumc[0]-sumc[1] == 1) cout<<sums[0]<<endl;
    else if(sumc[1]-sumc[0] == 1) cout<<sums[1]<<endl;
    else if(sumc[0]-sumc[1] == 0) cout<<sums[0]+sums[1]<<endl;
    else cout<<0<<endl;
}