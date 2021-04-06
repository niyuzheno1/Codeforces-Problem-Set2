#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;

typedef pair<int,int> pii;
map<pii, int> ans;
void generate(){
    #ifndef ONLINE_JUDGE
        cin >> n;
        a.resize(n);
        for(auto & x : a){
            cin >> x;
        }
    #endif
}


int query(int l, int r){
    int x;
    if(l < 1 ){
        return query(1, r);
    }
    if(r > n){
        return query(l,n);
    }
    if(l == r){
        return 10000000;
    }
    if(ans[make_pair(l,r)] != 0){
        return ans[make_pair(l,r)];
    }
    #ifdef ONLINE_JUDGE
        printf("? %d %d\n", l, r);
        fflush(stdout);
        scanf("%d", &x);
        return ans[make_pair(l,r)] = x;
    #else
        vector<pair<int,int>> b;
        for(int i = l-1; i < r; ++i){
            b.push_back(make_pair(a[i],i+1));
        }
        sort(b.begin(), b.end());
        return ans[make_pair(l,r)]=b[b.size()-2].second;
    #endif 
    
}
void out(int x){
    #ifdef ONLINE_JUDGE
    printf("! %d\n", x);
    fflush(stdout);
    #else
    cout << x << endl;
    #endif 
}
#define MB 21
int between(int x, int y, int pos, int d){
    int ret = 0;
    int l = x, r = y;
    while(l+1 < r){
        int mid = (l+r) >> 1;
        int res = 0;
        if(d == 1)
            res =query(mid, y);
        else
            res = query(x, mid);
        if(res == pos){
            if(d == 1){
                l = mid;
            }else{
                r = mid;
            }
        }
        else{
            if(d == 1){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
    }
    if(r-l == 1 ){
        if(d == 1 && query(r,y) == pos){
            return r;
        }
        if(d==2 && query(x,l) == pos){
            return l;
        }
    }
    if(d == 1)
     return l;
    else
     return r; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef ONLINE_JUDGE
        scanf("%d", &n);
    #else
        generate();
    #endif 
    
    if(n == 1){
        out(n);
    }
    int pos = query(1,n);
    int dir = query(1,pos);
    int r1 = 0, r2= n+1;
    if(dir == pos)
         r1 = between(0,pos, pos, 1);
    else
        r2 = between(pos,n+1, pos, 2);
    //if((r1 == 1 && r1 == 0) && (r2 == n && r2 == n+1)){
    if(r1 <= 0 && r2 >= n+1){
        return 0;
    }
    //if(r1 != 1 && r1 != 0){
    if( r1 > 0){
        out(r1);
    }
    //if(r2 != n && r2 != n){
    if( r2 <= n){
        out(r2);
    }
    return 0;
}