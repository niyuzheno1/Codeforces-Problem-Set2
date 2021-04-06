#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
vector<int> a;
vector<int> b;
vector<pii> eve;
#define X first
#define Y second
int process(){
    //map<int,int> matches;
    int n = eve.size();
    int boxes = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(eve.begin(), eve.end());
    // for(int i = 0; i < a.size(); ++i){
    //     auto s = lower_bound(b.begin(), b.end(), a[i]);
    //     if(s == b.end() || *s != a[i]) continue;
    //     matches[a[i]] = 1;
    // }
    boxes = a.size();
    int maxrewards  =0 ;
    int matches = 0;
    for(int i = n-1; i >=0 ; --i){
        auto x = eve[i];
        if(x.Y == 1){
            // if(matches.count(x.X)){
            //     matches.erase(x.X);
            // }
            auto s = lower_bound(b.begin(), b.end(), x.X);
             if(s != b.end() && *s == x.X){
                 ++matches;
             }
            --boxes;
        }
        if(x.Y == 2){
            
            auto s1 = upper_bound(b.begin(), b.end(), x.X);

            int p1 = s1 == b.end() ?  b.size() : s1 - b.begin();
            auto s2 = upper_bound(b.begin(), b.end(), x.X-boxes);
            int p2 = 0;
            if(s2 == b.end()){
                p2 = b.size();
            }else{
                p2 = s2 - b.begin();
            }
            maxrewards = max(p1 - p2+matches,maxrewards );
        }
    }
    return max(maxrewards,matches);
}
#define MAXN 200010
int AA[MAXN];
int BB[MAXN];
#define mp make_pair
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int ts;
    cin >> ts;
    while(ts--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i) cin >> AA[i];
        for(int i = 0; i < m; ++i) cin >> BB[i];
        a.clear();
        b.clear();
        eve.clear();
        for(int i = 0; i < n; ++i)
        {
            if(AA[i] > 0){
                a.push_back(AA[i]);
                eve.push_back(mp(AA[i],1));
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            if(BB[i] > 0){
                b.push_back(BB[i]);
                eve.push_back(mp(BB[i],2));
            }
        }
        int ans = 0;
        ans +=  process();
        
        a.clear();
        b.clear();
        eve.clear();
        for(int i = 0; i < n; ++i)
        {
            if(AA[i] < 0 ){
                a.push_back(-AA[i]);
                eve.push_back(mp(-AA[i],1));
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            if(BB[i] < 0){
                b.push_back(-BB[i]);
                eve.push_back(mp(-BB[i],2));
            }
        }
        ans += process();
        cout << ans <<endl;
    }
    return 0;
}