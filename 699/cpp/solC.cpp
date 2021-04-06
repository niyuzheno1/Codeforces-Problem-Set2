#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MAXN 100010
int n,m;
int a[MAXN];
int b[MAXN];
int f[MAXN];
int c[MAXN];
vector<int> mp[MAXN];
int timestamp = 0;
int ts[MAXN];
void solve(){
    int tot = 0;
    cin >> n >> m;
    map<int,int> fm;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    ++timestamp;
    for(int i = 1; i <= n; ++i) 
        if(a[i] != b[i]){
            if(ts[b[i]] != timestamp){
                ts[b[i]] = timestamp;
                mp[b[i]].clear();
            }
            mp[b[i]].push_back(i);
            ++tot;
        }else{
            fm[a[i]] = i;
        }
    for(int i = 1; i <= m; ++i){
        cin >> c[i];
        f[i] = 0;
    }
    for(int i = m; i >= 1; --i){
        if(ts[c[i]] != timestamp){
                ts[c[i]] = timestamp;
                mp[c[i]].clear();
        }
        if(mp[c[i]].size() > 0){
            f[i] = mp[c[i]].back();
            mp[c[i]].pop_back();
            --tot;
        }
    }
    bool flag = tot > 0;
    for(int i = 1; i <= m; ++i){
        if(f[i] == 0 && fm[c[i]] == 0){
            continue;
        }
        if(f[i] == 0){
            f[i]=fm[c[i]];
        }
        if(f[i] != 0){
            fm[c[i]] = f[i];
        }
    }
    flag = flag || (f[m] == 0);
    if(flag){
        cout << "NO" <<endl;
    }else{
        cout << "YES" <<endl;
        for(int i = m-1; i >= 1; --i){
            if(f[i] == 0){
                f[i] = f[i+1];
            }
        }
        for(int i = 1; i <= m; ++i) cout << f[i] << " ";
        cout <<endl;

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
    int tcases;
    cin >> tcases; 
    while(tcases--){
        solve();
    }
    return 0;
}