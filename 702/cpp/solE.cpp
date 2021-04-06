#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<pii> VP;
VP vp;
#define pid second
#define val first
#define mp make_pair
ll n; 
bool okay(ll idx){
    if(idx < 0) return false;
    if(idx >= n) return  true;
    ll sum = 0;
    for(ll i = 0; i <= idx; ++i){
        sum += vp[i].val;
    }
    for(ll i = idx+1; i < n; ++i){
        if(sum >= vp[i].val){
            sum += vp[i].val;
        }else{
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll tcases; cin >> tcases;
    while(tcases--){
        vp.clear();
        cin >> n;
        for(ll i = 1; i <=n; ++i){
            ll x; cin >> x;
            vp.push_back(mp(x,i));
        }
        sort(vp.begin(), vp.end());
        ll l = 0, r = n-1 , mid;
        while(l < r){
            mid = (l+r)>>1;
            if(okay(mid)){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        mid = (l+r)>>1;
        mid = mid - 3;
        while(!okay(mid)){
            ++mid;
        }
        if(mid >= n){
            cout << 0 << endl;
            continue;
        }
        cout << n - mid << endl;
        vector<ll> ans;
        for(ll i = mid; i < n; ++i){
            ans.push_back(vp[i].pid);
        }
        sort(ans.begin(), ans.end());
        for(auto &x : ans){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}