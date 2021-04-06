//no-unlocked
int Tcases,n,W;
int w[1d5];

{
    rd(Tcases);
    rep(t,Tcases){
        rd(n, W, w(n));
        multiset<int> s;
        rep(i,n) s.insert(w[i]);
        int ans = 0;
        while(s.size()){
            ++ans;
            ll cw = W;
            while(true){
                auto h = s.upper_bound(cw);
                if(h == s.begin()) break;
                --h;
                cw -= *h;
                s.erase(h);
            }
        }
        wt(ans);
    }
}