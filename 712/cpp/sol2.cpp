#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int ans[110][110];
const int dbg = 0;
int n;
queue<pair<int,int>> bin[2];
vector<pair<int,int>> ax[110+110];
int last = 0;
int ask(int b, int x, int y){
  ++last;
  ans[x][y] = b;
  wt_L(b);
  wt_L(' ');
  wt_L(x);
  wt_L(' ');
  wt_L(y);
  wt_L('\n');
  if(last == n*n){
    return 0;
  }
  int ret;
  rd(ret);
  return ret;
}
int main(){
  int i;
  rd(n);
  int low = n*n+2;
  int high = 0;
  for(i=(1);i<(n+1);i++){
    int j;
    for(j=(1);j<(n+1);j++){
      ax[i+j].push_back(make_pair(i,j));
      chmin(low, i+j);
      chmax(high, i+j);
    }
  }
  ++high;
  for(i=(low);i<(high);i++){
    for(auto x: ax[i]){
      bin[i%2].push(x);
    }
  }
  int resp;
  rd(resp);
  while(!bin[0].empty() || !bin[1].empty()){
    if(resp != 2){
      if(!bin[0].empty()){
        auto x = bin[0].front();
        bin[0].pop();
        resp = ask(2, x.first, x.second);
      }
      else{
        auto x = bin[1].front();
        bin[1].pop();
        int other = 0;
        for(i=(1);i<(4);i++){
          if(i == resp || i == 2){
            continue;
          }
          break;
        }
        resp = ask(i, x.first, x.second);
      }
      continue;
    }
    if(resp != 3){
      if(!bin[1].empty()){
        auto x = bin[1].front();
        bin[1].pop();
        resp = ask(3, x.first, x.second);
      }
      else{
        auto x = bin[0].front();
        bin[0].pop();
        int other = 0;
        for(i=(1);i<(4);i++){
          if(i == resp || i == 3){
            continue;
          }
          break;
        }
        resp = ask(i, x.first, x.second);
      }
      continue;
    }
  }
  if(dbg){
    for(i=(1);i<(n+1);i++){
      int j;
      for(j=(1);j<(n+1);j++){
        wt_L(ans[i][j]);
        wt_L(" ");
      }
      wt_L("");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// //interactive
// int ans[110][110];
// const int dbg = 0;
// int n;
// queue<pair<int,int>> bin[2];
// vector<pair<int,int>> ax[110+110];
// int last = 0;
// int ask(int b, int x, int y){
//     ++last;
//     ans[x][y] = b;
//     wt(b,x,y);
//     if(last == n*n){
//         return 0;
//     }
//     int ret; rd(ret);
//     return ret;
// }
// 
// {
//     
//     rd(n);
//     int low = n*n+2, high = 0;
//     rep(i,1,n+1)
//         rep(j,1,n+1)
//         {
//             ax[i+j].push_back(make_pair(i,j));
//             low <?= i+j;
//             high >?= i+j;
//         }
//     ++high;    
//     rep(i,low, high){
//         for(auto x: ax[i])
//             bin[i%2].push(x);
//     }
//     int resp;
//     rd(resp);
//     while(!bin[0].empty() || !bin[1].empty()){
//         if(resp != 2){
//             if(!bin[0].empty()){
//                 auto x = bin[0].front();bin[0].pop();
//                 resp = ask(2, x.first, x.second);
//             }else{
//                 auto x = bin[1].front();bin[1].pop();
//                 int other = 0;
//                 rep(i, 1, 4){
//                     if(i == resp || i == 2) continue;
//                     break;
//                 }
//                 resp = ask(i, x.first, x.second);
//             }
//             continue;
//         }
//         if(resp != 3){
//             if(!bin[1].empty())
//             {
//                 auto x = bin[1].front();bin[1].pop();
//                 resp = ask(3, x.first, x.second);
//             }
//             else{
//                 auto x = bin[0].front();bin[0].pop();
//                 int other = 0;
//                 rep(i, 1, 4){
//                     if(i == resp || i == 3) continue;
//                     break;
//                 }
//                 resp = ask(i, x.first, x.second);
//             }
//             continue;
//         }
//     }
//     if(dbg){
//         rep(i,1,n+1){
//             rep(j,1,n+1)
//             {
//                 wtF("{ans[i][j]} ");
//             }
//             wt("");
//         }
//     }
// }