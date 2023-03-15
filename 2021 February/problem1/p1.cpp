#include <iostream>
#include <vector>
#include <set>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
typedef vector<vint> v2d;

int main() {
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
    int N, K; cin>>N>>K;
    vint pos(N), kth (N); 
    vector<set<int>> ind (N);
    FOR(i, N){ pos[i] = i; ind[i].insert(i); }
    kth = pos;

    //index cycling
    FOR(i, K){
        int a, b; cin>>a>>b; a--; b--;
        int tmp = kth[b]; kth[b] = kth[a]; kth[a] = tmp;
        ind[kth[a]].insert(a);
        ind[kth[b]].insert(b);
    } 

    //kth position cycling
    v2d cyc; vint id (N, -1);
    int currID = 0;
    FOR(i, N){
        if(id[i] != -1) continue;
        cyc.push_back({});
        int j = i;
        do{
            id[j] = currID;
            cyc[currID].push_back(j);
            j = kth[j];
        } while(j != i);
        currID++;
    }

    vint ans(N);
    for(vint& c : cyc){
        set<int> all;
        for(int i : c){
            for(int idx : ind[i]){
                all.insert(idx);
            }
        }
        for(int i : c) ans[i] = all.size();
    }
    FOR(i, N) cout<<ans[i]<<endl;
}