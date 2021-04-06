//no-unlocked
const ll N = 2d6+2;
ll n,m;
ll a[N], b[N];
int c[N], d[N];
{
    rd(n, (a,b)(n));
    rep(i,0,n){
        int dir = 0;
        if(a[i] > b[i]){
            swap(a[i],b[i]);
            dir = 1;
        }
        if(a[i] > n || b[i] <= n){
            wt(-1);
            return 0;
        }
        c[a[i]] = b[i];
        d[a[i]] = dir;
    }
    // c : front number -> back number, d -> is the card flipped?
    set<int> s;
    rep(i,0,n+1) s.insert(n+i);
    vector<int> use; use.push_back(0);
    rep(i,1,n+1){
        s.erase(c[i]);
        if(i + *s.rbegin() == 2*n) use.push_back(i);
    }
    // use -> does the card need extra processing to match with other cards that are greater than the number.
    int ans = 0;
    rep(i,1,use.size()){
        int l = use[i-1]+1, r = use[i];
        int mn = 1e9;
        int mx = 1e9;
        int res = 0;
        rep(j,l,r+1){
            if(c[j] > mn){
                if(c[j] > mx){
                    wt(-1);
                    return 0;
                }
                res += (d[j] != 1);
                mx = c[j];
            }else{
                //  c[j] > mn;
                // c[j] < mn;
                res += (d[j] != 0);
                mn = c[j];
            }
        }
        ans += min(res, r-l+1-res);
    }

    wt(ans);
}
// , [l, c[l]], [l+1,c[l+1]], , ... , [c[l+2],l+2], [r,c[r]], 
// 