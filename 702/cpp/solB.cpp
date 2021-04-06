#include<bits/stdc++.h>
using namespace std;

int dist[3][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tcases; cin >> tcases;
    while(tcases--){
        int c[3];
        c[0] = c[1] = c[2] = 0;
        int n; cin >> n;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            ++c[x%3];
        }   
        for(int i = 0; i < 3; ++i){
            for(int j = i; j < 3; ++j){
                dist[i][j] = (j-i); 
            }
            for(int j = 0; j < i; ++j){
                dist[i][j] = 3 - (i-j);
            }
        }
        for(int i = 0; i < 3; ++i){
            sum += c[i];
        }
        sum /= 3;
        int ans = 0;
        for(int i = 0; i < 3; ++i){
            while(c[i] < sum){
                for(int j = 0; j < 3; ++j){
                    if(c[j] > sum){
                        int delta = min(sum-c[i], c[j]-sum);
                        ans += dist[j][i] * delta;
                        c[i] += delta;
                        c[j] -= delta;
                        break;
                    }
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}