#include <iostream>
#include <vector>
#include <string>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcountll __popcnt
#endif

using namespace std;
bool match(long long a ,long long b){
    int i = 30;
    int j = 30;
    while(((1LL<<i) & a) == 0)
        --i;
    while(((1LL<<j) & b) == 0)
        --j;
    bool ret = false;
    while(i >= 0 && j >= 0){
        if((((1LL<<i) & a) != 0) ){
            if( (((1LL<<j) & b) != 0)){
                --i; --j;
                continue;
            }else{
                while(((1LL<<j) & b) == 0 && j >=0){
                    --j;
                }
                continue;
            }
        }
        if((((1LL<<i) & a) == 0)){
            if((((1LL<<j) & b) != 0))
                return false;
            --i; --j;
            continue;
        }
    }
    while(((1LL<<j) & b) == 0 && j >=0)
        --j;
    if(i < 0 && j < 0){
        ret = true;
    }
    return ret;
}

bool dfs(long long a, long long b){
    if(__builtin_popcountll(a) < __builtin_popcountll(b)){
        return false;
    }
    if(a > b){
        return false;
    }
     bool ret = false;
    if(__builtin_popcountll(a) == __builtin_popcountll(b)){
        ret = match(a,b);
    }
   
     for(int j = 0; j < 30; ++j){
            if(a & (1LL << j)){
                long long c = a + (1LL << j);
                ret = ret || dfs(c,b);
            }
     }
     return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int q; cin >> q;
    for(int i = 0; i < q; ++i){
        long long a,b; cin >> a >> b;
        if(__builtin_popcountll(a) < __builtin_popcountll(b)){
            cout << "NO" << endl;
            continue;
        }
        // bool good = false;
        // if(__builtin_popcountll(a) == __builtin_popcountll(b)) 
        //     good = match(a,b);
        // // for(int j = 0; j < 30; ++j){
        // //     if(a & (1LL << j)){
        // //         long long c = a + (1LL << j);
        // //         if(__builtin_popcountll(c) != __builtin_popcountll(b)) continue;
        // //         good = good || match(c,b);
        // //     }
        // // }
        // good = dfs(a,b);
        if(__builtin_popcountll(a^b) %2 ==0 ){
            cout << "YES"<<endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}