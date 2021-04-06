#include <iostream>
#include <vector>
#include <string>

using namespace std;
//minp * n // k != (minp + n-1)//k
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i = 1; i <= 10; ++i)
    {
        for(int j = 1; j <= 20; ++j){
            for(int k = 1; k <= 100; ++k){
                if(k * i / j != (k + i-1)/ j || (k * i % j ==0) || ((k + i-1)% j ==0 )){
                    //cout << i << "," << j << ":" << k <<endl;
                    cout << k <<endl;
                    break;
                }
            }
        }
    }
    return 0;
}