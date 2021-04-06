//no-unlocked
char s[2d5];
int hist[28];
int selected[28];
char d[2d5];
int n,m,T;
{
    rd(T);
    rep(T){
        rd(s@n);
        rep(i,n) {
            hist[s[i]-'a'] = 0;
            selected[s[i]-'a'] = 0;
        }
        rep(i,n) selected[s[i]-'a'] = 1;
        int pos = 0;
        rrep(i,n){
            bool flag;
            flag = true;
            ++hist[s[i]-'a'];
            rep(j,0, 'z'-'a'+1){
                if(selected[j] > 0 && hist[j] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag && s[pos] < s[i])
                pos = i;
            
        }
        m = 0;
        rep(i,n){
            if(i <= pos && s[i] == s[pos]){
                d[m++] = s[i];
            }
            if(i > pos){
                d[m++] = s[i];
            }
        }
        n = m;
        rep(i,n) {
            hist[s[i]-'a'] = 0;
            selected[s[i]-'a'] = 0;
        }
        rep(i,m){
            s[i] = d[i];
            ++hist[s[i]-'a'];
        }
        s[n] = 0;
        
        m = 0;
        char pre;
        pre = -1;
        rep(i,0,n){
            if( s[i] <= s[i+1] && hist[s[i]-'a'] > 1){
                --hist[s[i]-'a'];
                continue;
            }
            d[m++] = s[i];
            pre = s[i];
        }
        
        rep(i,0,m){
            s[i] = d[i];
        }
        s[m] = 0;
        
        wt(s);
    }
}
//yyxs