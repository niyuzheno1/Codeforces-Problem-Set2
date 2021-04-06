//no-unlocked
char s[52];
int n,k, T;
{
    rd(T);
    rep(T){
        rd(n,k,s);
        int first = -1,last = -1;
        rep(i,n){
            if(s[i] == '*') { first = i; break;}
        }
        rrep(i,n){
            if(s[i] == '*') {last = i; break;}
        }
        s[first] = 'x';
        s[last] = 'x';
        int pre;
        pre = first;
        int j;
        j = pre+1;
        while(last-j >= k){
            int pos = -1;
            rrep(i, j, j + k){
                if(s[i] == '*'){
                    pos = i;
                    break;
                }
            }
            s[pos] = 'x';
            j = pos + 1;
        }
        int ans = 0;
        rep(i,n){
            ans += (s[i] == 'x') ? 1 : 0;
        }
        wt(ans);
    }
}
//yyxs