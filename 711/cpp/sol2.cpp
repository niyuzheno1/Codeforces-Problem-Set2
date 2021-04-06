#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
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
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
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
int Tcases;
int n;
int W;
int w[100000];
int main(){
  int t;
  rd(Tcases);
  for(t=(0);t<(Tcases);t++){
    int i;
    rd(n);
    rd(W);
    {
      int Q5VJL1cS;
      for(Q5VJL1cS=(0);Q5VJL1cS<(n);Q5VJL1cS++){
        rd(w[Q5VJL1cS]);
      }
    }
    multiset<int> s;
    for(i=(0);i<(n);i++){
      s.insert(w[i]);
    }
    int ans = 0;
    while(s.size()){
      ++ans;
      long long cw = W;
      while(true){
        auto h = s.upper_bound(cw);
        if(h == s.begin()){
          break;
        }
        --h;
        cw -= *h;
        s.erase(h);
      }
    }
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int Tcases,n,W;
// int w[1d5];
// 
// {
//     rd(Tcases);
//     rep(t,Tcases){
//         rd(n, W, w(n));
//         multiset<int> s;
//         rep(i,n) s.insert(w[i]);
//         int ans = 0;
//         while(s.size()){
//             ++ans;
//             ll cw = W;
//             while(true){
//                 auto h = s.upper_bound(cw);
//                 if(h == s.begin()) break;
//                 --h;
//                 cw -= *h;
//                 s.erase(h);
//             }
//         }
//         wt(ans);
//     }
// }