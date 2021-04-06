#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef priority_queue<int> pqq; 
#define MAXN 1010
#define MAXM 1000010
vector<int> a;
int book[MAXM];
int ts[MAXM];
int n;
typedef pair<int,int> pii;
#define mp make_pair
#define X first
#define Y second
bool add(int x, int tm){
    if(x < 0)
        return false;
    if(tm != ts[x]){
        ts[x] = tm;
        book[x] = 0;
    }
    book[x] = book[x] + 1;
    return true;
}
bool goodb(int x, int tm){
    if(book[x] == 0 || ts[x] != tm){
        return true;
    }
    return false;
}
void sub(int x, int tm){
    book[x] = book[x]-1;
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
    int tstamp = 1;
    while(tcases--){
        cin >> n;
        a.clear();
        n = 2*n;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        bool good = false;
        vector<pii> trace;
        ++tstamp;
        for(int i = 0; i < n-1; ++i){
            pqq pq; 
            int cnt = 0;
            ++cnt;
            ++tstamp;
            add(a[i], tstamp);
            int c = a[n-1];
            for(int j =n-2; j >= 0; --j){
                if(goodb(a[j],tstamp) == false) {
                    sub(a[j], tstamp);
                    --cnt;
                    continue;
                }
                ++cnt;
                add(c-a[j], tstamp);
                c = a[j];
            }
            if(cnt == 0){
                ++tstamp;
                good = true;
                cout << ("YES") << endl;
                cout << a[i] + a[n-1] << endl;
                cout << a[i]  << " " << a[n-1] << endl;
                add(a[i], tstamp);
                int c = a[n-1];
                for(int j =n-2; j >= 0; --j){
                    if(goodb(a[j],tstamp) == false) {
                        sub(a[j], tstamp);
                        continue;
                    }
                    cout << c-a[j]  << " " << a[j] << endl;
                    add(c-a[j], tstamp);
                    c = a[j];
                }
                break;
            }
        }
        if(!good){
            cout << "NO" << endl;
        }else{
            
        
        }
    }
    return 0;
}