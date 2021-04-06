//no-unlocked
char s[2d5];
char A[3d5];
int n ;
{
    int @Tcases;
    rep(Tcases){
        rd(n,s(n));
        rep(i,n) s[i] = s[i]-'0';
        int ones = sum(s(n));
        if(s[0] != 1 || s[n-1] != 1 || (n-ones) % 2 == 1){
            wt("NO");
            continue;
        }
        int cnt[2] = {0,0};
        
        rep(i,n) ++cnt[s[i]];
        A[0] = '(';
        A[n-1] = ')';
        rep(i,1,n-1){
            if(cnt[s[i]] % 2 == 0){
                A[i] = '(';
            }else{
                A[i] = ')';
            }
            --cnt[s[i]];
        }
        A[n] = 0;
        wt("YES");
        wt(A);
        rep(i,0,n){
            if(s[i] == 0){
                A[i] = A[i] == '(' ? ')' : '(';
            }
        }
        wt(A);
    }
}