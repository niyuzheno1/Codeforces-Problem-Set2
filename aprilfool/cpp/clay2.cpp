//no-unlocked
int n;
char S[100];
int s[100];
{
    rd(S@n);
    rep(i,n) s[i] = S[i] - '0';
    int ans = sum(s(n));
    wt(ans);
}