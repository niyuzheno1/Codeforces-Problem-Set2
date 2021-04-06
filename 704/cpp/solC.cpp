#include<bits/stdc++.h>
using namespace std;

int n,m;
string s,t;
#define MAXN 200010
int pre[MAXN];
int pos[MAXN];
int minv[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    cin >> s >> t;
    int cur = -1;
    for(int i = 0; i < n; ++i){
        minv[i] = n;
        if(cur >= m) cur = m-1;
        if(t[cur+1] == s[i] ){
            ++cur;
        }
        pre[i] = cur;
    }
    cur = m;
    for(int i = n-1; i >= 0; --i){
        if(cur <= 0) cur = 0;
        if(cur != 0 && t[cur-1] == s[i] ){
            --cur;
        }
        pos[i] = cur;
    }
    for(int i = 0; i < n; ++i){
        if(pre[i] == -1) continue;
        minv[pre[i]] = min( minv[pre[i]] , i);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(pre[i] >= pos[i] && pos[i] > 0 && pos[i] < m && t[pos[i]]==s[i]){
            ans = max(ans,i-minv[pos[i]-1]);
        }
    }
    cout << ans << endl;
    return 0;
}