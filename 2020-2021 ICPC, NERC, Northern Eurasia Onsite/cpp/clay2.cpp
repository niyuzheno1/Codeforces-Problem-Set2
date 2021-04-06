//no-unlocked
const int MN = 110;
graph g;
int p[MN];
int e1[MN], e2[MN];
int ans[MN],sz;
int f[MN][MN];
int csz[MN];
void add_array(int x){
    arrInsert(sz, sz, ans,x);
}
int dfs(int root,int x){
    vector<pair<int,int>> vx;
    rep(i,g.es[root]){
        int m = g.edge[root][i];
        vx.push_back({csz[m],m});
    }
    if(f[root][x] != -1){
        return f[root][x];
    }
    if(x == 1 || x == 0){
        return f[root][x] = 0;
    }
    sort(vx.begin(), vx.end(), [&] (const pair<int,int> x, const pair<int,int> y){ return x.first > y.first; });
    int tx = x-1;
    int cur = 0, ans = 1e9;
    int m = vx.size();
    while(vx.size() >= 2 && tx > 0){
        if(tx - vx[0].first > vx[1].first){
            cur += vx[0].first*2;
            tx -= vx[0].first;
            vx.erase(vx.begin());
            continue;
        }else if(tx <= vx[0].first){
            rep(j,1,m){
                if(tx > vx[j].first) break;
                ans <?= cur + dfs(vx[j].second, tx)+1;
            }
        }
        
        {
            rep(j,1,m){
                if(tx > vx[0].first+vx[j].first) break;
                rep(k, 0, vx[j].first+1){
                    if(tx - k > vx[0].first) continue;
                    if(tx - k < 0) continue;
                    ans <?= cur + (tx - k)*2 + dfs(vx[j].second, k)+1 ;
                }
            }
            cur += vx[0].first*2;
            tx -= vx[0].first;
            vx.erase(vx.begin());
        }
    }
    if(vx.size() == 1 && tx > 0 ){
        if(vx[0].first < tx){
            return f[root][x] =  1e8;
        }
        ans <?= cur+1+dfs(vx[0].second,tx);
    }
    f[root][x] = ans;
    return ans;
}
void dfs3 (int root, int x){
    if(x <= 0) return;
    --x;
    add_array(root);
    rep(i,g.es[root]){
        int m = g.edge[root][i];
        dfs3(m, min(x,csz[m]));
        x -= min(x,csz[m]);
        add_array(root);
        if(x == 0)
            return;
        
    }
}
void dfs2(int root,int x){
    vector<pair<int,int>> vx;
    rep(i,g.es[root]){
        int m = g.edge[root][i];
        vx.push_back({csz[m],m});
    }
    if(x == 0) return;
    add_array(root);
    if(x == 1 ) return ;
    sort(vx.begin(), vx.end(), [&] (const pair<int,int> x, const pair<int,int> y){ return x.first > y.first; });
    int tx = x-1;
    int cur = 0;
    int ans = f[root][x];
    int m = vx.size();
    while(vx.size() >= 2 && tx > 0){
        if(tx - vx[0].first > vx[1].first){
            cur += vx[0].first*2;
            tx -= vx[0].first;
            vx.erase(vx.begin());
            dfs3(vx[0].second, vx[0].first);
            add_array(root);
            continue;
        }else if(tx <= vx[0].first){
            rep(j,1,m){
                if(tx > vx[j].first) break;
                if(ans == cur + dfs(vx[j].second, tx)+1){
                    dfs2(vx[j].second, tx);
                    return;
                }
            }
        }
        
        {
            rep(j,1,m){
                if(tx > vx[0].first+vx[j].first) break;
                rep(k, 0, vx[j].first+1){
                    if(tx - k > vx[0].first) continue;
                    if(tx - k < 0) continue;
                    if(ans == cur + (tx - k)*2 + dfs(vx[j].second, k)+1){
                        dfs3(vx[0].second, tx-k);
                        add_array(root);
                        dfs2(vx[j].second, k);
                        return;
                    }
                }
            }
            cur += vx[0].first*2;
            tx -= vx[0].first;
            dfs3(vx[0].second, vx[0].first);
            add_array(root);
            vx.erase(vx.begin());
        }
    }
    if(vx.size() == 1 && tx > 0 ){
        if(vx[0].first < tx){
            return;
        }
        if(ans == cur+1+dfs(vx[0].second,tx)){
            dfs2(vx[0].second,tx);
            return;
        }
    }
    f[root][x] = ans;
    return;
}
{
    int @Tcases;
    rep(Tcases){
        int n,k;
        sz =0; 
        rd(n,k,p(n-1));
        rep(i, n-1){
            e1[i] = p[i]-1;
            e2[i] = i+1;
        }
        rep(i,n)
            rep(j,n+2)
                f[i][j] = -1;
        g.setEdgeRootedTree(n,n-1,e1,e2);
        g.SubTreeSize(0,csz);
      
        wt(dfs(0,k));
        dfs2(0,k);
        wt((++ans)(sz));
    }
}