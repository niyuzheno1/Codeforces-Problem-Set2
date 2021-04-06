#include<bits/stdc++.h>
using namespace std;
#define MAXN 110
int a[MAXN];
int d[MAXN];

void dfs(int l, int r, int dep){
    if(l > r){
        return;
    }
    int idx = l;
    for(int i = l; i <= r; ++i){
        if(a[i] > a[idx]){
            idx = i;
        }
    }
    d[idx] = dep;
    dfs(l,idx-1, dep+1);
    dfs(idx+1,r, dep+1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    while(tcases--){
        int n; cin >> n;
        for(int i = 1; i <=n; ++i) cin >> a[i];
        dfs(1,n,0);
        for(int i = 1; i <=n; ++i)
            cout << d[i] << " ";
        cout << endl;
    }
    return 0;
}