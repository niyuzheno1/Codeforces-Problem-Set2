#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 200010
typedef pair<int,int> pii;
typedef priority_queue<int, vector<int>, std::greater<int> > PQ;
vector<pii> va;

int a[MAXN];
int b[MAXN];
int n,m;
#define X first
#define Y second
#define mp make_pair
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
    for(int i = 0; i < tcases; ++i){
        cin >> n >> m;
        va.resize(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        for(int i = 0; i < n; ++i) va[i] = mp(a[i],b[i]);
        sort(va.begin(), va.end());
        int csum = 0;
        PQ pq[3];
        for(int i = 0; i < n; ++i){
            pq[va[i].Y].push(va[i].X);
            csum += va[i].X;
            // update
            
            while(pq[1].size() >= 2 && !pq[2].empty()){
                int top2 =  pq[2].top(); pq[2].pop();
                int top11 = pq[1].top(); pq[1].pop();
                int top12 = pq[1].top(); pq[1].pop();
                if(csum - top11 - top12 >= m && top11 + top12 <= top2){
                    csum = csum - top11 - top12;
                    pq[2].push(top2);
                }else if(csum-top2 >= m){
                    csum = csum - top2;
                    pq[1].push(top11);
                    pq[1].push(top12);
                }else{
                    pq[2].push(top2);
                    pq[1].push(top11);
                    pq[1].push(top12);
                    break;
                }
            }
        
            while(!pq[1].empty()){
                if(csum - pq[1].top() < m) break;
                 csum = csum - pq[1].top();
                 pq[1].pop();
            }
        }
        if(csum < m){
            cout << -1 <<endl;
            continue;
        }
        cout << pq[1].size() + pq[2].size()*2 <<endl;
    }
    return 0;
}