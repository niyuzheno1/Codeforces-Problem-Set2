#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010
int n;
int a[MAXN];
int occ[MAXN];
typedef pair<int,int> pii;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    while(tcases--){
        cin >> n;
        map<int,int> fc;
        vector<int> tmp;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            tmp.push_back(a[i]);
        }
        sort(tmp.begin(), tmp.end());
        int last = -1, idx = 1;
        for(int i = 0; i < n; ++i) {
            if(last != tmp[i]){
                last = tmp[i];
                ++idx;
                fc[tmp[i]] = idx;
            }
        }
        for(int i = 0; i <= idx; ++i){
            occ[i] = 0;
        }
        for(int i = 0; i < n; ++i){
            ++occ[fc[a[i]]];
        }
        vector<int> pro;
        for(int i = 0; i <= idx; ++i){
            if(occ[i] != 0){
                pro.push_back(occ[i]);
            }
        }
        sort(pro.begin(), pro.end());
        int sum = 0;
        for(int i = 0; i < pro.size(); ++i){
            sum += pro[i];
        }
        int ans = INT_MAX, cnt = 0, lastj = 0;
        int m = pro.size();
        for(int i = 0; i < m; ++i){
            while(pro[lastj] != pro[i]){
                cnt += pro[lastj];
                ++lastj;
            }
            sum -= pro[i];
            ans = min(ans, cnt + sum - (m-i-1)*pro[i]);
            
        }
        cout << ans << endl;
    }
    return 0;
}