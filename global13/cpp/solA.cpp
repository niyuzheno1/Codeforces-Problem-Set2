#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n,q;
#define MAXN 100010
int a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int ones = 0;
    for(int i = 0; i < n; ++i) cin >> a[i], ones += a[i];
    for(int i = 0; i < q; ++i){
        int q, x; cin >> q >>x;
        if(q == 1){
            x = x -1;
            a[x] ^= 1;
            if(a[x] == 0){
                ones = ones - 1;
            }else{
                ones = ones + 1;
            }
        }else{
            if(x <= ones){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}