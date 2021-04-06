//no-unlocked
ll n,m,x,T;
{
    rd(T);
    rep(T){
        rd(n,m,x);
        swap(n,m);
        ll row = (x+m-1)/m;
        ll col = (x-1)%m;
        wt(col * n + row);
    }
}
//yyxs