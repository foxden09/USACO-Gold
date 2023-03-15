#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)
typedef vector<int> vint;
int N, Q; 
string clr; 

void calc(vint &pfx){ //prefix # of ranges beginning
    stack<char> s;
    FOR(i, N){
        if(i != 0) pfx[i] += pfx[i-1];
        char c = clr[i];
        while(!s.empty() && c < s.top()) s.pop();
        if(s.empty() || clr[i] != s.top()){
            s.push(clr[i]);   
            pfx[i]++;
        }
    }
}

int main() {
    freopen("p2.in", "r", stdin);
    freopen("p2.out", "w", stdout);
    cin>>N>>Q;
    cin>>clr;
    vint pfx (N), sfx (N);
    calc(pfx); reverse(clr.begin(), clr.end()); 
    calc(sfx); reverse(sfx.begin(), sfx.end()); 
    FOR(i, N) cout<<sfx[i]<<endl;

    FOR(q, Q){
        int a, b; cin>>a>>b; a--; b--;
        int qa = a==0 ? 0 : pfx[a-1];
        cout<<qa+sfx[b+1]<<endl;
    }
}