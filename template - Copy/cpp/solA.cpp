#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.length();
    string ans;
    for(int i = 0; i < n; ++i){
        if(i% 2== 0){
            ans += s[i] == 'a' ? 'b' : 'a';
        }else{
            ans += s[i] == 'z' ? 'y' : 'z';
        }
    }
    cout << ans <<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    while(tcases--){
        solve();
    }
    return 0;
}