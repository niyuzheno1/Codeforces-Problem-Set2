//no-unlocked
char s[110];
{
    int @t;
    rep(t){
        int @n, @k;
        rd(s(n));
        if(k == 0){
            wt("Yes");
        }else{
            bool flag;
            flag = true;
            rep(i,0,k){
                if(s[i] != s[n-i-1]){
                    flag = false;
                }
            }
            if(2 * k == n){
                flag = false;
            }
            if(!flag){
                wt("No");
            }else{
                wt("Yes");
            }
        }
    }
}