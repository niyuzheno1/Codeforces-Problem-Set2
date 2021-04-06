#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> ltk;
vector<int> btk;
int n, k, x;
#define MAXN 100010
int a[MAXN];

#define prev(x) ((x+n-1)%n)

#define next(x) ((x+1)%n)

int sim[MAXN];
int cards[MAXN];
void step(){
    memset(cards,0,sizeof(cards));
    for (int i = 0; i < n; ++i){
        if(x == i) // imposter
            cards[next(i)] += sim[i];
        else{
            cards[prev(i)] += sim[i]/2;
            cards[next(i)] += (sim[i]+1)/2;
        }
    }
    memcpy(sim, cards, sizeof(cards));
}


        

int query(int x){
    int ret;
    #ifndef ONLINE_JUDGE
        ret = sim[x-1];
        step();
    #else
    cout << "? " << x << endl;
    cout.flush();
    
    cin >> ret;
    #endif
    return ret;
}
void answer(int x){
    cout << "! " << x << endl;
    cout.flush();
}

void init(){
    for(int i = 0; i < n; ++i) sim[i] = k;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        n = 800;
        k = 2;
        x = 401-1;
        init();
    #else
        cin >> n >> k;
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i = 0 ; i < 500; ++i){
        query(1);
    }
    if(n <= 500){
        for(int i = 0; i < n; ++i){
            a[i]=query(i+1);
        }
        for(int i = 0; i < n; ++i){
            if(a[i] == k && a[prev(i)] < k && a[next(i)] > k ){
                answer(i+1);
                return 0;
            }
        }
    }else{
        for(int i = 0; i <= n/500; ++i){
            int c = i * 500;
            c = c+1;
            if(c > n){c = n;}
            if(c == 0) {c = 1;}
            int res = query(c);
            if(res < k) {ltk.push_back(c);}
            if(res > k) {btk.push_back(c);}
        }
        for(int i = 0; i <= n/500; ++i){
            int c = i * 500;
            c = c+2;
            if(c > n){c = n;}
            if(c == 0) {c = 1;}
            int res = query(c);
            if(res < k) {ltk.push_back(c);}
            if(res > k) {btk.push_back(c);}
        }
        if(query(1) == k && query(n) < k && query(2) > k){
            
                answer(1);
                return 0;
            
        }else{
            sort(ltk.begin(), ltk.end());
            int l = ltk[0];
            int r = n-1;
            
            for(auto x: btk){
                if(x > l)
                    r = min(x, r);
            }
            while(l < r-1){
                int mid = (l+r)>>1;
                int v = query(mid+1);
                if(v == k){
                    answer(mid+1);
                    return 0;
                }else{
                    if( v > k){
                        r = mid;
                    }else{
                        l = mid;
                    }
                }
            }
            int m = query(l+1);
            if(m == k){
                answer(l+1);
            }else{
                answer(r+1);
            }
        }
    }
    return 0;
}