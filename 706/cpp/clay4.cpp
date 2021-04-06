//no-unlocked
int p[100010];
int good[100010];
int pre[100010];
int pos[100010];
{
    int t;
    t = 1;
    rep(t){
        int @n;
        rd(p(n));
        rep(i,0,n){ good[i] = 1; pre[i] = 0; pos[i] = 0;}
        good[0] = 0;
        good[n-1] = 0;
        rep(i,1,n-1){ if(p[i] > p[i+1] && p[i] > p[i-1]) continue; good[i] = 0; }
        rep(i,1,n){ if(p[i] > p[i-1]) { pre[i] = pre[i-1] + 1;} else {pre[i] = 0;} }
        rep(i,2,n+1) {
            if(p[n-i] > p[n-i+1]){
                pos[n-i] = pos[n-i+1] + 1; 
            }else{
                pos[n-i] = 0;
            }
        }
        int maxlen = 0, cnt = 0;
        rep(i,0,n){
            int sf; 
            sf = 1;
            if(max(pre[i],pos[i]) == maxlen){
                cnt = cnt + 1;
            }
            if(pre[i] > maxlen){
                maxlen = pre[i];
                cnt = 0;
            }
            if(pos[i] > maxlen){
                maxlen = pos[i];
                cnt = 0;
            }
            if(pre[i] == pos[i]) continue;
            if(pre[i] % 2 == 0 && (pre[i]-1) > pos[i]) sf = 0;
            if(pos[i] % 2 == 0 && (pos[i]-1) > pre[i]) sf = 0;
            if(pre[i] % 2 == 1 && pre[i] > pos[i]) sf = 0;
            if(pos[i] % 2 == 1 && pos[i] > pre[i]) sf = 0;
            
            
            if(sf == 0){
                good[i] = 0;
            }
        }
        rep(i,0,n){
            if(good[i] == 0) continue;
            if(maxlen == pre[i] || maxlen == pos[i]){
                    good[i] = 2;
            }
        }

        rep(i,0,n){
            if(good[i] == 2 && cnt == 0){
                good[i] = 1;
                continue;
            }
            if(good[i] == 2){
                good[i] = 1;
            }
            if(max(pre[i],pos[i]) <= maxlen){
                good[i] = 0;
            }
        }
        
        wt(sum(good(n)));
    }
}