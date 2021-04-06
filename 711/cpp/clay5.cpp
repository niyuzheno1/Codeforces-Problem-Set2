//interactive
int n, k[510];
int A[510*510], B[500*510], C[500*510];
int ask(int x, int y){
    char resp[10];
    resp[0] = 0;
    wt("?", x, y);
    fflush(stdout);
    rd(resp);
    if(resp[0] == 'Y') return 1;
    return 0;
}
void answer(int x, int y){
    wt("!", x, y);
    fflush(stdout);
}

{
    rd(n, k(n));
    int tot = 0;
    rep(i,n){
        rep(j,i+1,n){
            A[tot] = abs(k[i]-k[j]);
            B[tot] = i+1;
            C[tot] = j+1;
            ++tot;
        }
    }
    sortA(tot, A, B, C);
    while(tot){
        --tot;
        if(ask(B[tot],C[tot])){
            answer(B[tot],C[tot]);
            exit(0);
        }
    }
    answer(0,0);
    exit(0);
}