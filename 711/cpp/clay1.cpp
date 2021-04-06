//no-unlocked
int Tcases;
ll n;
ll sumd(ll x){
    ll ret = 0;
    while( x > 0){
        ret += x%10;
        x/=10;
    }
    return ret;
}

{
    rd(Tcases);
    rep(t,Tcases){
        rd(n);
        while(gcd(n,sumd(n)) <= 1) ++ n;
        wt(n);
    }
}