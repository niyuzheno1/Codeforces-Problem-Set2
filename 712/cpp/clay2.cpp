//no-unlocked
//interactive
int ans[110][110];
const int dbg = 0;
int n;
queue<pair<int,int>> bin[2];
vector<pair<int,int>> ax[110+110];
int last = 0;
int ask(int b, int x, int y){
    ++last;
    ans[x][y] = b;
    wt(b,x,y);
    if(last == n*n){
        return 0;
    }
    int ret; rd(ret);
    return ret;
}

{
    
    rd(n);
    int low = n*n+2, high = 0;
    rep(i,1,n+1)
        rep(j,1,n+1)
        {
            ax[i+j].push_back(make_pair(i,j));
            low <?= i+j;
            high >?= i+j;
        }
    ++high;    
    rep(i,low, high){
        for(auto x: ax[i])
            bin[i%2].push(x);
    }
    int resp;
    rd(resp);
    while(!bin[0].empty() || !bin[1].empty()){
        if(resp != 2){
            if(!bin[0].empty()){
                auto x = bin[0].front();bin[0].pop();
                resp = ask(2, x.first, x.second);
            }else{
                auto x = bin[1].front();bin[1].pop();
                int other = 0;
                rep(i, 1, 4){
                    if(i == resp || i == 2) continue;
                    break;
                }
                resp = ask(i, x.first, x.second);
            }
            continue;
        }
        if(resp != 3){
            if(!bin[1].empty())
            {
                auto x = bin[1].front();bin[1].pop();
                resp = ask(3, x.first, x.second);
            }
            else{
                auto x = bin[0].front();bin[0].pop();
                int other = 0;
                rep(i, 1, 4){
                    if(i == resp || i == 3) continue;
                    break;
                }
                resp = ask(i, x.first, x.second);
            }
            continue;
        }
    }
    if(dbg){
        rep(i,1,n+1){
            rep(j,1,n+1)
            {
                wtF("{ans[i][j]} ");
            }
            wt("");
        }
    }
}