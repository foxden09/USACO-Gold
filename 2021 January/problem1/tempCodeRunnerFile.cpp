#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
typedef vector<vint> v2d;
int N, moves = 0;
vint used;

void dfs(int i, v2d &nbors){
    used[i] = true;
    int num = 1, x2 = 0; //produce enof for children
    while(num < nbors[i].size()+1){ num *= 2; x2++; }
    moves += x2;

    for(int n : nbors[i]){
        if(!used[n]){
            moves++;
            dfs(n, nbors);
        } 
    } 
}

int main() {
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
    cin>>N;
    v2d nbors (N); used.resize(N);
    FOR(i, N-1){
        int a, b; cin>>a>>b; a--; b--;
        nbors[a].push_back(b);
        nbors[b].push_back(a);
    }
    dfs(0, nbors);
    cout<<moves<<endl;
}