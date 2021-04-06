//no-unlocked
char s[2d5];
int hist[28];
int selected[28];
char d[2d5];
char ans[2d5];
int n,m,am,T, pos;
{
    rd(T);
    rep(T){
        m = 0;
        am = 0;
        rd(s@n);
        rrep(c,'a', 'z'+1){
            rrep(i,n){
                selected[s[i]-'a'] = 0;
                hist[s[i]-'a'] = 0;
            }
            rep(i,n) selected[s[i]-'a'] = 1;
            pos = -1;
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
                if(flag && (pos == -1 || s[pos] <= s[i]))
                    pos = i;
                    
            }
            ans[am++] =  s[pos];
            m = 0;
            rep(i,pos+1,n){
                if(s[i] == s[pos]) continue;
                d[m++] = s[i];
            }
            rep(i,0,m){
                s[i] = d[i];
            }
            s[m] = 0;
            n = m;
            if(n <= 0) break;
        }
        rep(i,0,n){
            ans[am++] = s[i];
        }
        ans[am] = 0;
        wt(ans);
    }
}
//yyxs