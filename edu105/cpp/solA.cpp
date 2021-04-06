#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 60
int a[MAXN];
int f[10];
int b[MAXN], n;

bool check(){
    for(int i = 0; i < n; ++i){
        b[i] = f[a[i]];
    }
    int z = 0;
    for(int i = 0; i < n; ++i){
        if(b[i] == 0){
            ++z;
        }else{
            --z;
        }
        if(z < 0){
            return false;
        }
    }
    if(z > 0)
        return false;
    return true;
}

bool dfs(int x){
    if(x == 3)
        return check();
    bool good = false;
    f[x] = 0;
    good = good || dfs(x + 1);
    f[x] = 1;
    good = good || dfs(x + 1);
    return good;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    while(tcases--){
        string s;
        cin >> s;
        n = s.length();
        for(int i = 0; i < n; ++i){
            a[i]=s[i]-'A';
        }
        auto x = dfs(0);
        if(x == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}