#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define X first
#define Y second
void solve(){
    int a, b, n;
    cin >> a >> b >> n;
    swap(a,b);
    vector<int> t; for(int i = 0, x= 0; i < n; ++i) cin >> x, t.push_back(x); 
    vector<pii> h; for(int i = 0, x; i < n; ++i) cin >> x, h.push_back(mp(t[i],x));
    sort(h.begin(), h.end());
    for(int i = 0; i < n-1; ++i){
        int u = (h[i].Y + b -1)/b;
        a -= h[i].X * u;
        if(a <= 0){
            cout << "NO" << endl;
            return;
        }
    } 
    int w = h[n-1].Y;
    int u = (w +b  -1)/b;
    u = u-1;
    a -= h[n-1].X * u;
    w -= (u+1) *b;
    if(a <= 0 || w > 0){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" <<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    while(tcases--){
        solve();
    }
    return 0;
}