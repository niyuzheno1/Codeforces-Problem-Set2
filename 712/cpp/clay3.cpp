//no-unlocked
ll n;
ll a[1d5],c[1d5];
{
    rd(n, (a,c)(n));
    ll sc = sum(c(n));
    sortA(n,a,c);
    ll mx = a[0]+c[0];
    rep(i,1,n){
        if(a[i] > mx){
            sc += a[i] - mx;
        }
        mx >?= a[i]+c[i];
    }
    wt(sc);
}