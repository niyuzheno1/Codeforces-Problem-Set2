//no-unlocked
char S[110];
int N;
{
    rd(S@N);
    if(N == 1 || N == 2){
        wt("YES");
        return 0;
    }
    rep(i,0,N) S[i] = S[i] - 'A';
    bool flag = true;
    rep(i,2,N){
        if(S[i] == (S[i-1]+S[i-2])%26)
            continue;
        flag = false;
    }
    if(flag) wt("YES");
    if(!flag) wt("NO");
}