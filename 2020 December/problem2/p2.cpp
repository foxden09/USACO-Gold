#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint; 

int main() {
    freopen("p2.in", "r", stdin);
    freopen("p2.out", "w", stdout);
    int N, M; cin>>N>>M;
    vint c1 (N), c2 (N); 
    FOR(i, N) cin>>c1[i]>>c2[i];

    vint c (M+1, -1), ans (N);
    int kick = 0;
    for(int i = N-1; i >= 0; i--){
        int j = c1[i], dis = c[j]; //taken cereal, displaced
        c[j] = i; //take fav
        while(dis != -1){ //if not empty
            if(c2[dis] == j){ kick++; break; } //was displaced's 2nd seed
            j = c2[dis]; //taken cereal

            if(c[j] != -1 && c[j] < dis){ kick++; break; } //not good enough
            int tmp = c[j];
            c[j] = dis;
            dis = tmp;
        }
        ans[i] = N-i-kick;
    }
    FOR(i, N) cout<<ans[i]<<endl;
}