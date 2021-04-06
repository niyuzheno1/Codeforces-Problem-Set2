#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define MAXN 1010
vector<int> a;
multiset<int> ax;
int n;
typedef pair<int,int> pii;
#define mp make_pair
#define X first
#define Y second
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
        cin >> n;
        a.clear();
        ax.clear();
        n = 2*n;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            a.push_back(x);
            ax.insert(x);
        }
        sort(a.begin(), a.end());
        bool good = false;
        vector<pii> trace;
        for(int i = 0; i < n-1; ++i){
            auto b = ax;
            int c = a[n-1];
            b.erase(lower_bound(b.begin(), b.end(), a[n-1]));
            b.erase(lower_bound(b.begin(), b.end(), a[i]));
            while(b.size() > 0){
                int m = b.size();
                auto ux = b.rbegin();
                auto u = lower_bound(b.begin(), b.end(), *ux);
                auto v = lower_bound(b.begin(), b.end(), c-*u);
                if(u == b.end()||v == b.end() || u == v)
                {
                    break;
                }else{
                    if(*u + *v != c)
                        break;
                    c = *u;
                    b.erase(u);
                    b.erase(v);
                }
            }
            if(b.size() == 0){
                good = true;
                b = ax;
                c = a[n-1];
                trace.push_back(mp(a[i], a[n-1]));
                b.erase(lower_bound(b.begin(), b.end(), a[n-1]));
                b.erase(lower_bound(b.begin(), b.end(), a[i]));
                while(b.size() > 0){
                    int m = b.size();
                    auto ux = b.rbegin();
                    auto u = lower_bound(b.begin(), b.end(), *ux);
                    auto v = lower_bound(b.begin(), b.end(), c-*ux);
                    trace.push_back(mp(*u, *v));
                    {
                        c = *u;
                        b.erase(u);
                        b.erase(v);
                    }
                }
                break;
            }
        }
        if(!good){
            cout << "NO" << endl;
        }else{
            cout << ("YES") << endl;
            cout << trace[0].X + trace[0].Y << endl; 
            for(int i = 0; i < trace.size(); ++i){
                cout << trace[i].X << " " << trace[i].Y <<endl;
            }
        }
    }
    return 0;
}