//no-unlocked
int Tcases; 
int n, k;
//x - decay value
//y - how many are in the front
//z - how many are in the back
Modint dp[1100][1100];
int ts[1100][1100];
int ct = 0;
Modint dfs(int x, int y, int z){
    if(x == 0){
        return 0;
    }
    if(y == 0){
        return 1;
    }
    if(ts[x][y] != ct){
        dp[x][y] = 0;
    }
    if(ts[x][y] == ct){
        return dp[x][y];
    }
    
    ts[x][y] = ct;
    Modint & ans = dp[x][y];
    ans = dfs(x, y-1, z+1);
    ans += dfs(x-1, z, y);
    return ans;
}

{
    rd(Tcases);
    rep(t,Tcases){
        ++ct;
        rd(n,k);
        wt(dfs(k, n, 0));
    }
}