#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define mp make_pair
#define small first
#define big second
pii process(ll n, vector<ll> & x){
    sort(x.begin(), x.end());
    pii ret;
    if(n % 2 == 0){
        ret.big = x[n/2];
        ret.small = x[n/2-1];
    }else{
        ret.small = ret.big = x[(n-1)/2];
    }
    return ret;
}

#define count(x) (x.big-x.small+1)

void solve(){
    ll n;
    cin >> n;
    vector<ll> ax(n), ay(n);
    for(ll i = 0 ; i < n ;++i){
        cin >> ax[i] >> ay[i];
    }
    auto px = process(n,ax);
    auto py = process(n,ay);
    cout << count(px) * count(py) <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll tcases; cin >> tcases;
    while(tcases--){
        solve();
    }
    return 0;
}