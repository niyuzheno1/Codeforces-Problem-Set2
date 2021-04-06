#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXC 30
int counts[MAXC];
#define t(x) ((x)-'a')
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    while(tcases--){
        int n,m;
        cin >> n >> m;
        string s;
        string ans; 
        cin >> s;
        if(n % m){
            cout << -1 << endl; continue;
        }
        memset(counts, 0, sizeof(counts));
        for(int i = 0; i < n; ++i){
            ++counts[t(s[i])];
            counts[t(s[i])] %= m;
        }
        bool goodoutput = true;
        for(int j = 'a'; j <= 'z'; ++j){
                if(counts[t(j)] == 0) continue;
                goodoutput = false;
        }
        if(goodoutput){
            cout << s << endl;
            continue;
        }
        memset(counts, 0, sizeof(counts));
        int bestpos = -1;
        int inc = 0;
        for(int i = 0; i < n; ++i){
            if(s[i]+1 > 'z'){
                ++counts[t(s[i])];
                counts[t(s[i])] %= m;
                continue;
            }
            ++counts[t(s[i]+1)];
            counts[t(s[i]+1)] %= m;
            int ans = 0;
            for(int j = 'a'; j <= 'z'; ++j){
                if(counts[t(j)] == 0) continue;
                ans += m-counts[t(j)];
            }
            bool flag = true;
            if(n-i-1 < ans){
                flag = false;
            }
            if((n-i-1 - ans) % m != 0){
                flag = false;
            }
            if(flag){
                bestpos = i;
                inc = 1;
            }
            --counts[t(s[i]+1)];
            counts[t(s[i]+1)] = (counts[t(s[i]+1)]+m)%m;
            
            ++counts[t(s[i])];
            counts[t(s[i])] %= m;
        }
        memset(counts, 0, sizeof(counts));
        if(bestpos == -1){
            for(int i = 0; i < n; ++i)
                ans += 'z';
            cout << ans << endl;
            continue;
        }
        for(int i = 0; i < bestpos; ++i){
            ans += s[i];
            ++counts[t(s[i])];

        }
        ans += (s[bestpos] + 1);
        ++counts[t(s[bestpos]+1)];
        int ansx = 0;
        for(int j = 'a'; j <= 'z'; ++j){
            counts[t(j)] %= m;
            if(counts[t(j)] == 0) continue;
            ansx += m-counts[t(j)];
            counts[t(j)] = m-counts[t(j)];
        }
        int leftover = n-bestpos-1 - ansx;
        counts[t('a')] += leftover;
        for(int j = 'a'; j <= 'z'; ++j){
            while(counts[t(j)]){
                ans += j;
                --counts[t(j)];
            }
        }
        cout << ans << endl;
    }
    return 0;
}