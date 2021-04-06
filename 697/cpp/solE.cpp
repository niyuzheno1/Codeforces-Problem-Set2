#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
#define MAXN 1010
#define MODN 1000000007

ll factor[MAXN];

ll mul(ll x, ll y){
    return (x*y)%MODN;
}

void init(){
    factor[0] = 1;
    for(ll i = 1; i < MAXN; ++i){
        factor[i] = mul(i,factor[i-1]);
    }
}

 
ll power(ll base, ll exp) 
{ 
    ll t = 1LL; 
    while (exp > 0)  
    { 
        // for cases where exponent 
        // is not an even value 
        if (exp % 2 != 0) 
            t = (t * base) % MODN; 
        base = (base * base) % MODN; 
        exp /= 2; 
    } 
    return t % MODN; 
} 
ll inv(ll x){
    return power(x,MODN-2);
}
  

ll nCr(ll x, ll y){
    return mul(factor[x],inv(mul(factor[y],factor[x-y])));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    init();
    while(tcases--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(),a.end());
        int m = 0; // nCr(w, m)
        int w = 0;
        for(int i = n-k; i < n; ++i){
            if(a[i] != a[n-k]){
                break;
            }
            ++m;
        }
        for(int i = 0; i < n; ++i){
            if(a[i] == a[n-k]) ++w;
        }
        cout << nCr(w,m) <<endl;
    }
    return 0;
}