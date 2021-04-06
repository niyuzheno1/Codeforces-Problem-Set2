#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define xid second
#define val first
#define mp make_pair
vector<pii> vp;
#define MAXN 200010
ll sum[MAXN], n, m, a[MAXN], ans[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll tcases; cin >> tcases;
    bool dbg = false;
    int dbgcnt = 0;
    while(tcases--){
        vp.clear();
        cin >> n >> m;
        for(ll i = 0; i < n; ++ i) cin >> a[i];
        for(ll i = 0; i < m; ++ i){
            ll x; cin >> x; 
            vp.push_back(mp(x,i));
            ans[i] = -1;
        }
        ll bestsum = 0;
        for(ll i = 0; i < n; ++i){
            sum[i] = i > 0 ? sum[i-1] : 0;
            sum[i] += a[i];
            bestsum = max(bestsum, sum[i]);
        }
        sort(vp.begin(), vp.end());
        ll idx = 0, mpr = vp.size();
        ll offset = 0;
        ll turns = 0;
        for(idx = 0; idx < mpr; ++idx){
            if(sum[n-1] == 0)
                turns = 0;
            else
                turns = (vp[idx].val-bestsum+sum[n-1]-1)/sum[n-1];
            if(turns < 0 || vp[idx].val <= bestsum){
                turns = 0;
            }
            if(vp[idx].val > bestsum && sum[n-1] <= 0) break;
            offset = turns * sum[n-1];
            ans[vp[idx].xid] = turns*n;
            vp[idx].val -= offset;
        }
        idx = 0;
        sort(vp.begin(), vp.end());
        while(idx < mpr){
            
            for(ll i = 0; i < n; ++i){
                while(idx < mpr && vp[idx].val <= sum[i]){
                    ans[vp[idx].xid] = ans[vp[idx].xid]+i;
                    ++idx;
                }
            }
            if(sum[n-1] <= 0){
                break;
            }
        }
        for(ll i = 0; i < m; ++ i){
            cout << ans[i]  << " ";
        }
        
        cout << endl;

    }
 
    return 0;
}