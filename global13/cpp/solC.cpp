#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
#define MAXN 5010
ll S[MAXN];
ll cnt[MAXN];
ll n;
#define pos second
#define val first
#define mp make_pair
typedef pair<ll,ll> pll;
void enumer(ll x){
    ll j = x;
    while(x < n){
        ll tmp = S[j];
        S[j] = S[j]-1;
        S[j] = max(S[j],(long long)1);
        j = j + tmp;
    }
}
void solve(){
    priority_queue<pll> pq;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        cin >> S[i];
        if(S[i] > n){
            ans += (S[i]-n);
            S[i] = n;
        }
    }

    cout << ans <<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases;
    cin >> tcases;
    while(tcases --){
        solve();
    }
    return 0;
}