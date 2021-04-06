#include <iostream>
#include <vector>
#include <string>
using namespace std;
int FF[5];
int GG[5];
int F[5];
int G[5];
int add[5];
int n ;

#define pre(x) (x-1+4)%4

bool check(){
    bool ret = true;
    for(int i = 0; i < 4; ++i){
        if(F[i] >= 0 && F[i] <= G[i]){
            continue;
        }
        ret = false;
    }
    if(ret == true){
        // for(int i = 0; i < 4; ++i){
        //     cout << F[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0; i < 4; ++i){
        //     cout << G[i] << " ";
        // }
        // cout << endl;
    }
    return ret;
}

bool dfs(int x){
    if(x == 4){
        for(int i = 0; i < 4; ++ i){
            F[i] = FF[i]; 
            G[i] = GG[i];
        }
        for(int i = 0; i < 4; ++ i){
            if(add[i] == 1){
                --F[pre(i)];
                --G[pre(i)];
                --F[i];
                --G[i];
            }
        }
        for(int i = 0; i < 4; ++i){
            if(F[i] > n-2){
                return false;
            }
        }
        return check();
    }
    bool good = false;
    add[x] = 0;
    good = good || dfs(x+1);
    add[x] = 1;
    good = good || dfs(x+1);
    return good;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases = 0;
    cin >> tcases; 
    while(tcases -- ){
         cin >> n;
        for(int i = 0; i < 4; ++i) GG[i] = n;
        for(int i = 0; i < 4; ++i) cin >> FF[i];
        cout << (dfs(0) ? "YES" : "NO" )<<endl;
    }
    return 0;
}