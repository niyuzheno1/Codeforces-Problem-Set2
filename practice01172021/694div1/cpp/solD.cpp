#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m; 
#define MAXN 300010

vector<int> e[MAXN];
int marked[MAXN];
int visited[MAXN];
void dfs(int x){
    if(visited[x]) return;
    visited[x] = 1;
    bool ismarked = false;
    for(auto y: e[x]){
        if(marked[y]){
            ismarked = true;
        }
    }
    if(ismarked == false) marked[x] = 1;
    for(auto y: e[x]){
        dfs(y);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; 
    cin >> tcases;
    while(tcases--){
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            e[i].clear();
            marked[i] = 0;
            visited[i] = 0;
        }
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(0);
        int cnt = 0;
        for(int i = 0; i < n; ++i) cnt += visited[i];
        if(cnt == n){
            cout << "YES" <<endl;
            vector<int> ans;
            for(int i = 0; i < n; ++i){
                if(marked[i])
                    ans.emplace_back(i+1);
            }
            cout << ans.size()<<endl;
            for(auto x: ans)
            {
                cout << x << " ";
            }
            cout << endl;
        }else{
            cout << "NO" <<endl;
        }
    }
    return 0;
}