#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto & x : a){ cin >> x;}
    b[0] = 1;
    int last = a[0], cnt1 = 1, cnt2 = 0;
    for(int i = 1 ; i < n ; ++i){
        if(a[i] != last){
            last = a[i];
            b[i] = 1;
            ++cnt1;
        }
    }
    last = -1;
    for(int i = 0; i < n; ++i){
        if(b[i] == 0){
            if(last == -1){
                last = a[i];
                cnt2 = 1;
            }
            if(last != a[i]){
                ++cnt2;
                last = a[i];
            }
        }
    }
    cout << cnt1 + cnt2 <<endl;
    return 0;
}