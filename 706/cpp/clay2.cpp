//no-unlocked
int a[100010];
{
    int @t;
    rep(t){
        int @n, @k;
        int ans;
        rd(a(n));
        sortA(n,a);
        ans = n;
        if(k == 0){
            wt(n);
            continue;
        }
        if(a[0] != 0){
            int b = (a[n-1])/+2;
            rep(i,0,n){
                if(a[i] == b){
                    b = -1;
                }
            }
            
            if(b != -1){
                    ans = ans + 1;
            }
        }else{
            int mex;
            mex = 0;
            rep(i,0,n){
                if(a[i] != mex){
                    break;
                }
                mex = mex + 1;
            }
            
            if(mex == n){
                ans = ans + k;
            }else{
                int b = (mex + a[n-1])/+2;
                rep(i,0,n){
                    if(a[i] == b){
                        b = -1;
                    }
                }
                if(b != -1){
                    ans = ans + 1;
                }
            }
        }
        wt(ans);
    }
    
}