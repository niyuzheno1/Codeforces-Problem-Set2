//no-unlocked
char sa[52],sb[52];
int la,lb, T;
{
    rd(T);
    rep(T){
        rd(sa@la);
        rd(sb@lb);
        int ans = la+lb;
        rep(i,0,la)
        {
            rep(j,0,lb)
            {
                rep(k,0,min(la-i,lb-j)){
                    if(sa[i+k] != sb[j+k]) break;
                    ans <?= max(i,0) + max(j,0) + max(la-i-k-1,0) +  max(lb-j-k-1,0);
                }
            }
        }
        wt(ans);
    }
}
//yyxs