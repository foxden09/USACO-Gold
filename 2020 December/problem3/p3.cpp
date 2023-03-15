#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
struct coor{ int x, y;
    bool operator<(const coor& c)const{ return tie(x, y) < tie(c.x, c.y); } };
int N;

int main() {
    freopen("p3.in", "r", stdin);
    freopen("p3.out", "w", stdout);
    cin>>N;
    vector<coor> c (N);
    FOR(i, N) cin>>c[i].x>>c[i].y;
    sort(c.begin(), c.end());

    vint ymax (N+1, -1e9);
    for(int i = N-1; i >= 0; i--) ymax[i] = max(ymax[i+1], c[i].y);

    int cc = 0, ymin = 1e9;
    FOR(i, N){
        ymin = min(ymin, c[i].y);
        if(ymin > ymax[i+1]) cc++;
    }
    cout<<cc<<endl;
}