#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<int,int> reflect;
int h, m;
pair<int,int> getback(int x, int y){
    string minu = to_string(x);
    string hour = to_string(y);
    while(minu.length() < 2) minu = "0" + minu;
    while(hour.length() < 2) hour = "0" + hour;
    reverse(hour.begin(),hour.end());
    reverse(minu.begin(),minu.end());
    int hx = 0;
    int mx = 0;
    for(int i = 0; i < hour.length(); ++i){
        if(!reflect.count(hour[i]-'0'))
            return make_pair(-1,-1);
        hx *= 10;
        hx += reflect[hour[i]-'0'];
    }
    for(int i = 0; i < minu.length(); ++i){
        if(!reflect.count(minu[i]-'0'))
            return make_pair(-1,-1);
        mx *= 10;
        mx += reflect[minu[i]-'0'];
    }
    if(hx < h && mx < m){
    return make_pair(hx,mx);
        
    }
    return make_pair(-1,-1);
}
pair<int,int> from_ctime(string x){
    int hr = 0, minu = 0;
    int i =0;
    while(x[i] != ':'){
        hr *= 10;
        hr += (x[i]-'0');
        ++i;
    }
    ++i;
    while(i < x.length()){
        minu *= 10;
        minu += x[i] -'0';
        ++i;
    }
    return make_pair(hr,minu);
}

void to_time(int x, int y){
    string hour = to_string(x);
    string minu = to_string(y);
    while(minu.length() < 2) minu = "0" + minu;
    while(hour.length() < 2) hour = "0" + hour;
    cout << hour << ":" << minu << endl;
}

int distance(pair<int,int> a, pair<int,int> b){
    int ha = a.first * m + a.second;
    int hb = b.first * m + b.second;
    if(ha >= hb){
        return ha - hb;
    }
    return -hb + h*m+ha;
}

bool lessthan(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    return distance(a,c) < distance(b,c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    reflect[0] = 0;
    reflect[1] = 1;
    reflect[2] = 5;
    reflect[5] = 2;
    reflect[8] = 8;
    int tcases;
    cin >> tcases;
    while(tcases--){
        cin >> h >> m;
        string x;
        cin >> x;
        auto u = from_ctime(x);
        int reth = 0, retm = 0;
        for(int i = 0; i < h; ++i){
            
            for(int j = 0; j < m; ++j){
                
                auto tmp = getback(i,j);
                if(tmp.first == -1) continue;
                
                if( lessthan(tmp, make_pair(reth, retm), u)) {
                    reth = i, retm = j;
                }
            }
        }
        to_time(reth,retm);

    }
    return 0;
}