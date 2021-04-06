#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
#define MAXN 100010
int a[MAXN];
int b[MAXN], mb;
int nxt[MAXN];
int subcnt[MAXN];
int ans = -1;
int f[MAXN][2];

void chmin(int & x, int y){
    if(y == -1) return;
    if(x > y)
    {
        x = y;
    }
    if(x == -1){
        x = y;
    }
}
void dfs(int x, int y, int c, int t){
    if(t > 2) return;
    if(f[x][(b[x+1] != b[y])] != -1){
        if(f[x][(b[x+1] != b[y])] < c){
            return;
        }
    }
    f[x][(b[x+1] != b[y])] = c;
    if(max(x,y) == mb || max(x,y) == mb-1){
        ans = ans == -1 ? c: min(ans,c);
        return;
    }
    int nx = nxt[x];
    int ny = nxt[x]-1;
    int nc = c + subcnt[ny] - subcnt[x+1] + (b[x+1] != b[y]);
    dfs(nx,ny,nc, 0);
    nx = x+1;
    ny = y;
    nc = c+ (b[x+1] != b[x]);
    dfs(nx,ny,nc, t+1);
}
void solve(){
    f[0][1] = 0;
    for(int x = 0; x < mb; ++x){
        for(int j = 0; j < 2; ++j){
            if(f[x][j] == -1) continue;
            int nx = nxt[x];
            int ny = nxt[x]-1;
            int nc = f[x][j] + subcnt[ny] - subcnt[x+1] + j;
            chmin(f[nx][(b[nx+1] != b[ny])], nc);
            nx = x+1;
            if(j == 1)continue;
            nx = x+1;
            ny = x-1;
            nc = f[x][j] + j;
            chmin(f[nx][(b[nx+1] != b[ny])], nc);

        }
    }
    int ans = -1;
    chmin(ans, f[mb][0]);
    chmin(ans, f[mb][1]);
    cout << ans <<endl;
}
void init(){
    memset(f,0xff,sizeof(f));
}

int main()
{
    init();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n = 0; cin >> n;
    a[0] = 0;
    for(int i = 1 ; i <= n; ++i ) cin >> a[i];
    mb = 1;
    for(int i = 1;  i <= n; ++i){
        if(a[i] != a[i-1]){
            b[mb] = a[i];
            ++mb;
        }
    }
    map<int,int> f;
    for(int i = 0; i < mb;++i) f[b[i]] = mb;
    for(int i = mb-1; i >= 0; --i){
        nxt[i] = f[b[i]];
        f[b[i]] = i;
    }
    for(int i = 1; i < mb; ++i){
        if(b[i] != b[i-1]){
            subcnt[i] = 1;
        }
        subcnt[i] += subcnt[i-1];
    }
    solve();
    return 0;
}