#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXN 1010
int bad[MAXN];
void solve(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i <= n; ++i) bad[i] = 0;
    for(int i = n; i >= 0; --i){
        if(k - i <= 0) continue;
        if(bad[i]) continue;
        if(i == k-i) continue;
        bad[k-i] = 1;
    }
    vector<int> vi;
    for(int i = 1; i <=n; ++i){
        if(bad[i] == 0) vi.push_back(i);
    }
    cout << vi.size() << endl;
    for(auto & x : vi){
        cout << x << " ";
    }
    cout <<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; 
    cin >> tcases;
    while(tcases--){
        solve();
    }
    return 0;
}