//no-unlocked
const int MN = 1d5;
const int dbg = 0;
int n,d;
double a[MN];
ll b[MN];
double f[MN][10];
int c[MN][10][2];
int ans[MN],sz;
void add_array(int x){
    arrInsert(sz, sz, ans,x);
}
{
    rd(n,d, a(n));
    rep(i,n){
        b[i] = round(a[i]);
        a[i] = log(a[i])/log(1000);
    }
    rep(i,n){
        if(i!=0){
            rep(j,10){
                f[i][j] = f[i-1][j];
                c[i][j][0] = c[i-1][j][0];
                c[i][j][1] = c[i-1][j][1];
            }
            rep(j,10){
                if(f[i-1][j] + a[i] > f[i][(j*b[i])%10]){
                    f[i][(j*b[i])%10] = f[i-1][j] + a[i];
                    c[i][(j*b[i])%10][0] = i;
                    c[i][(j*b[i])%10][1] = j;
                }
            }
            if(f[i][b[i]%10] < a[i]){
                f[i][b[i]%10] = a[i];
                c[i][b[i]%10][0] = i;
                c[i][b[i]%10][1] = -1;    
            }
            continue;
        }
        if(i == 0){
            rep(j,10){
                f[i][j] = 0;
                c[i][j][0] = -1;
                c[i][j][1] = -1;
            }
            f[i][b[0]%10] = a[0];
            c[i][b[0]%10][0] = 0;
            c[i][b[0]%10][1] = -1;
        }
    }
    if(dbg){
        wt(f[n-1][d]);
    }
    if(f[n-1][d] == 0) { wt(-1); return 0;}
    int x = c[n-1][d][0], y = c[n-1][d][1];
    while(y != -1){
        add_array(b[x]);
        
        int u = x-1;
        if(u < 0) break;
        x = c[u][y][0];
        y = c[u][y][1];
    }
    if(x >= 0)
        add_array(b[x]);
    wt(sz);
    wt(ans(sz));
}