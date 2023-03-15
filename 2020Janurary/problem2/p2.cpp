#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
struct cow{ int w, x, v, d; };
bool cmpx(cow l, cow r){ return l.x < r.x; }
bool cmpd(cow l, cow r){ return l.d < r.d; }

int main() {
    freopen("p2.in", "r", stdin);
    freopen("p2.out", "w", stdout);
    int N, L, sumw = 0; cin>>N>>L;
    vector<cow> cows (N), cowd (N); 
    FOR(i, N) { 
        cin>>cows[i].w>>cows[i].x>>cows[i].v;
        if(cows[i].v==1) cows[i].d = L-cows[i].x;
        else cows[i].d = cows[i].x;
        sumw += cows[i].w;
    }
    cowd = cows;
    sort(cows.begin(), cows.end(), cmpx);
    sort(cowd.begin(), cowd.end(), cmpd);
    
    //Find T
    int T = 0, totw = 0, l = 0, r = 0, col = 0;
    FOR(i, N){
        if(cowd[i].v == 1){
            totw += cows[N-r].w;
            r++;
        } 
        else{
            totw += cows[l].w;
            l++;
        }
        T = cowd[i].d; 
        if(totw >= sumw/2) break;
    }

    //Find collisions
    queue<int> q; //sliding window, within 2T, going right
    FOR(i, N){
        while(!q.empty() && cows[i].x-q.front() > 2*T) q.pop();
        
        if(cows[i].v == 1) q.push(cows[i].x);
        else col += q.size();
    }
    cout<<col<<endl;


}