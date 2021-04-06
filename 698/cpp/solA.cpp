#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
#define MAXN 100050
ll am[2][MAXN];
ll bm[2][MAXN];
bool gen(ll * u, int n, int sw, ll p){
    ll s = 0;
    bool flag = true;
    ll * a = am[sw];
    for(int i = 0; i < n; ++i){
            if ((u[i]-2*s) % p != 0)
                flag = false;
            if ((u[i]-2*s) <= 0)
                flag = false;
            ll x = (u[i]-2*s)/p;
            s += x;
            *a = x;
            ++a;
            p = p - 2;
    }
    if(flag == false)
        return false;
    else
        return true;
}
void solve(){
    int tt = 0; cin >> tt;
    for (int t = 0; t < tt; ++ t){
        int n; cin >> n;
        vector<ll> d(2*n);
        for(auto & x : d) cin >> x;
        bool flag = true;
        ll p =  2*n;
        ll s = 0;
        ll * a[2];
        a[0] = bm[0];
        a[1] = bm[1];
        sort(d.begin(),d.end(), std::greater<ll>());
        for(int i= 0; i < d.size(); ++i){
            *a[i%2]=d[i];
            ++a[i%2];
        }
        auto a0 = gen(bm[0],n, 0, p);
        auto a1 = gen(bm[1],n, 1, p);
        if(a0 == false || a1 == false)
            flag = false;
        else{
            for(int i = 0; i < n; ++i)
                if(am[0][i] != am[1][i])
                    flag = false;
            sort(am[0], am[0]+n);
            for(int i = 0; i < n-1; ++i)
                if(am[0][i] == am[0][i+1])
                    flag = false;
        }
        if(flag == false){
            printf("NO\n");
            continue;
        }
        else{
            printf("YES\n");
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}