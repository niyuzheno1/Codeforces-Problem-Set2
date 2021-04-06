#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
#define MAXN 100010
ll c[MAXN];
ll a[MAXN];
ll b[MAXN];
ll n; 
ll compute1(ll x, ll csum){
    ll l;
    ll r;
    if(x == 1){
        l = 1;
        r = c[1];
    }else{
        l = c[1];
        r = 1;
    }
    ll maxc = 0;
    for(ll i = 1; i < n; ++i)
    {
        maxc = max(maxc, csum + llabs(r-l));
        if(l < r){
            if(a[i+1] < b[i+1]){
                csum += llabs(l-a[i+1]);
                csum += llabs(r-b[i+1]);
                csum += 2;
                l = 1;
                r = c[i+1];
                
            }else if(a[i+1] > b[i+1]){
                csum += llabs(l-b[i+1]);
                csum += llabs(r-a[i+1]);
                csum += 2;
                l = c[i+1];
                r = 1;
            }else{
                l = 1;
                r = c[i+1];
                csum = 2;
            }
        }else{
            if(a[i+1] < b[i+1]){
                
                csum += llabs(l-b[i+1]);
                csum += llabs(r-a[i+1]);
                csum += 2;
                l = c[i+1];
                r = 1;
            }else if(a[i+1] > b[i+1]){
                csum += llabs(l-a[i+1]);
                csum += llabs(r-b[i+1]);
                csum += 2;
                l = 1;
                r = c[i+1];
            }else{
                l = 1;
                r = c[i+1];
                csum = 2;
            }
        }
        
    }
    maxc = max(maxc, csum + llabs(r-l));
    return maxc;
}

void solve(){
    cin >> n;
    for(int i = 0; i <= n+10; ++i){
        c[i] = a[i] = b[i] = 0;
    }
    for(ll i = 0; i < n; ++i)
        cin >> c[i];
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    for(ll i = 0; i < n; ++i)
        cin >> b[i];
    
    ll curx = compute1(1, llabs(a[1]-b[1])+2);
    ll cury = compute1(2, llabs(a[1]-b[1])+2);
    cout << max(curx, cury) << endl;
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