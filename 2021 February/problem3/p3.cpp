#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
typedef vector<vint> v2d;
int N; 

int calc_best(v2d& grid){
    int best = 0;
    FOR(i, N){ //calculate best way to alternate each column OR row
        int odd = 0, even = 0;
        FOR(j, N){
            if(j % 2 == 0) even += grid[i][j];
            else odd += grid[i][j];
        }
        best += max(odd, even);
    }
    return best;
}

int main() {
    freopen("p3.in", "r", stdin);
    freopen("p3.out", "w", stdout);
    cin>>N;
    v2d grid (N, vint(N)), grid2 = grid;
    FOR(i, N) FOR(j, N) { cin>>grid[i][j]; grid2[j][i] = grid[i][j]; } 

    cout<<max(calc_best(grid), calc_best(grid2))<<endl;
}