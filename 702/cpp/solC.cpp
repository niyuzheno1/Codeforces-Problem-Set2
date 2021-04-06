#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> f;
vector<ll> a; 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(ll i = 1; i <= 10000; ++i){
        f[i*i*i] = 1;
        a.push_back(i*i*i);
    }
    int tcases; cin >> tcases;
    for(int jj = 0; jj < tcases; ++jj){
        ll n; cin >>n;
        bool flag = false;
        for(int j = 0; j < a.size(); ++j){
            if(f[n-a[j]]){
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "NO" <<endl;
        }else{
            cout << "YES"<<endl;
        }
    } 
    return 0;
}