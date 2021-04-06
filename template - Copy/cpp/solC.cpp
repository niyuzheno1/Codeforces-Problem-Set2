#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> a;
vector<int> b;
int query(int x){
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    return x;
}
void out(int x){
    printf("! %d\n", x);
    fflush(stdout);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    scanf("%d", &n);
    if(n == 1)
    {
        out(1);
        return 0;
    }
    a.resize(n+3);
    a[0] = a[n+1] = INT_MAX;
    a[1] = query(1);
    a[2] = query(2);
    a[n] = query(n);
    a[n-1] = query(n-1);
    b.resize(5);
    b[0] = a[0];
    b[1] = a[1];
    b[2] = a[n-1];
    b[3] = a[n];
    if(a[1] < a[2]){
        out(1);
        return 0;
    }
    if(a[n] < a[n-1]){
        out(n);
        return 0;
    }
    if(n <= 4){
        for(int i = 1; i <= n;++i){
            if(a[i] < a[i+1] && a[i] < a[i-1]){
                out(i);
                return 0;
            }
        }
        return 0;
    }
    // n >= 5
    int l = 3, r = n-2;
    while(l <= r){
        int mid = (l+r)>>1;
        a[mid] = query(mid);
        if(a[mid] < b[1]){
            swap(b[0],b[1]);
            b[1] = a[mid];
            l = mid+1;
        }else{
            swap(b[2],b[3]);
            b[2] = a[mid];
            r = mid-1;
        }
    }
    int midind = 0, mid = INT_MAX;
    for(int i = 1; i <= n; ++i){
        if(a[i] == 0) continue;
        if(a[i] < mid){
            mid = a[i];
            midind = i;
        }
    }
    a[midind-1] = query(midind-1);
    if(a[midind-1] < a[mid]){
        for(int i = 2; i < 30; --i){
            if(midind-i < 1) break;
            if(a[midind-i] != 0) break;
            a[midind-i] = query(midind-i);
        }
    }
    a[midind+1] = query(midind+1);
    if(a[midind+1] < a[mid]){
        for(int i = 2; i < 30; --i){
            if(midind+i > n) break;
            if(a[midind+i] != 0) break;
            a[midind+i] = query(midind+i);
        }
    }
    for(int i = 1; i <= n; ++i){
        if(a[i+1]  == 0 || a[i-1] == 0) continue;
        if(a[i+1] > a[i] && a[i-1] > a[i]){
            out(i);
            return 0;
        }
    }
    return 0;
}