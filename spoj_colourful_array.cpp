// https://www.spoj.com/problems/CLFLARR/

#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

vector<int> par,clr;

// it will help to find the next unpainted block
int findPar(int u){
    if(par[u]==u) return u;
    return par[u] = findPar(par[u]);
}

void solve() {
    int n,q;cin>>n>>q;
    vector<vector<int>> query(q);

    for(int i=0;i<q;i++){
        int l,r,c;cin>>l>>r>>c;
        query[i] = {l,r,c};
    }
    par.assign(n+5,0);
    clr.assign(n+5,0);
    for(int i=0;i<=n+1;i++){
        par[i] = i;
    }

  // using offline query from back to front
    for(int i=q-1;i>=0;i--){
        int l = query[i][0], r = query[i][1], c = query[i][2];
        int pos = findPar(l);
        while(pos<=r){
            clr[pos] = c;
            par[pos] = pos+1;
            pos = findPar(pos);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<clr[i]<<" ";
    }
    cout<<endl;
}

int32_t main() {
// #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
// #endif

    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
