#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
typedef vector<vint> v2d;

int main() {
    freopen("p1.in", "r", stdin);
    freopen("p1.out", "w", stdout);
    int N, M, K; cin>>N>>M>>K;
    vint pos (N); FOR(i, N) pos[i] = i; 
    vint ord = pos;

    //simulate reversing M
    FOR(i, M){
        int l, r; cin>>l>>r; l--;
        reverse(ord.begin()+l, ord.begin()+r);
    }

    //find cycles
    v2d cyc(N+1);
    vint id (N), phase (N);
    int ID = 1;
    FOR(i, N){
        if(id[i] != 0) continue;
        int j = i; //ord[i]; 

        int currPhase = 0;
        do{
            id[j] = ID;
            cyc[ID].push_back(j); 
            phase[j] = currPhase;
            currPhase++;
            j = ord[j];
        } while(j != i);
        ID++;
    }

    //print 
    FOR(i, N){ 
        cout<<cyc[id[i]][(K+phase[i])%cyc[id[i]].size()]+1<<endl;
    }

}