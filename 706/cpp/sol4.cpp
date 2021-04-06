#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
int p[100010];
int good[100010];
int pre[100010];
int pos[100010];
int main(){
  int Lj4PdHRW;
  int t;
  t = 1;
  for(Lj4PdHRW=(0);Lj4PdHRW<(t);Lj4PdHRW++){
    int i;
    int n;
    rd(n);
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<(n);e98WHCEY++){
        rd(p[e98WHCEY]);
      }
    }
    for(i=(0);i<(n);i++){
      good[i] = 1;
      pre[i] = 0;
      pos[i] = 0;
    }
    good[0] = 0;
    good[n-1] = 0;
    for(i=(1);i<(n-1);i++){
      if(p[i] > p[i+1] && p[i] > p[i-1]){
        continue;
      }
      good[i] = 0;
    }
    for(i=(1);i<(n);i++){
      if(p[i] > p[i-1]){
        pre[i] = pre[i-1] + 1;
      }
      else{
        pre[i] = 0;
      }
    }
    for(i=(2);i<(n+1);i++){
      if(p[n-i] > p[n-i+1]){
        pos[n-i] = pos[n-i+1] + 1;
      }
      else{
        pos[n-i] = 0;
      }
    }
    int maxlen = 0;
    int cnt = 0;
    for(i=(0);i<(n);i++){
      int sf;
      sf = 1;
      if(max_L(pre[i], pos[i])== maxlen){
        cnt = cnt + 1;
      }
      if(pre[i] > maxlen){
        maxlen = pre[i];
        cnt = 0;
      }
      if(pos[i] > maxlen){
        maxlen = pos[i];
        cnt = 0;
      }
      if(pre[i] == pos[i]){
        continue;
      }
      if(pre[i] % 2 == 0 && (pre[i]-1) > pos[i]){
        sf = 0;
      }
      if(pos[i] % 2 == 0 && (pos[i]-1) > pre[i]){
        sf = 0;
      }
      if(pre[i] % 2 == 1 && pre[i] > pos[i]){
        sf = 0;
      }
      if(pos[i] % 2 == 1 && pos[i] > pre[i]){
        sf = 0;
      }
      if(sf == 0){
        good[i] = 0;
      }
    }
    for(i=(0);i<(n);i++){
      if(good[i] == 0){
        continue;
      }
      if(maxlen == pre[i] || maxlen == pos[i]){
        good[i] = 2;
      }
    }
    for(i=(0);i<(n);i++){
      if(good[i] == 2 && cnt == 0){
        good[i] = 1;
        continue;
      }
      if(good[i] == 2){
        good[i] = 1;
      }
      if(max_L(pre[i], pos[i])<= maxlen){
        good[i] = 0;
      }
    }
    {
      int AlM5nNnR;
      int XJIcIBrW;
      if(n==0){
        XJIcIBrW = 0;
      }
      else{
        XJIcIBrW = good[0];
        for(AlM5nNnR=(1);AlM5nNnR<(n);AlM5nNnR++){
          XJIcIBrW += good[AlM5nNnR];
        }
      }
      wt_L(XJIcIBrW);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int p[100010];
// int good[100010];
// int pre[100010];
// int pos[100010];
// {
//     int t;
//     t = 1;
//     rep(t){
//         int @n;
//         rd(p(n));
//         rep(i,0,n){ good[i] = 1; pre[i] = 0; pos[i] = 0;}
//         good[0] = 0;
//         good[n-1] = 0;
//         rep(i,1,n-1){ if(p[i] > p[i+1] && p[i] > p[i-1]) continue; good[i] = 0; }
//         rep(i,1,n){ if(p[i] > p[i-1]) { pre[i] = pre[i-1] + 1;} else {pre[i] = 0;} }
//         rep(i,2,n+1) {
//             if(p[n-i] > p[n-i+1]){
//                 pos[n-i] = pos[n-i+1] + 1; 
//             }else{
//                 pos[n-i] = 0;
//             }
//         }
//         int maxlen = 0, cnt = 0;
//         rep(i,0,n){
//             int sf; 
//             sf = 1;
//             if(max(pre[i],pos[i]) == maxlen){
//                 cnt = cnt + 1;
//             }
//             if(pre[i] > maxlen){
//                 maxlen = pre[i];
//                 cnt = 0;
//             }
//             if(pos[i] > maxlen){
//                 maxlen = pos[i];
//                 cnt = 0;
//             }
//             if(pre[i] == pos[i]) continue;
//             if(pre[i] % 2 == 0 && (pre[i]-1) > pos[i]) sf = 0;
//             if(pos[i] % 2 == 0 && (pos[i]-1) > pre[i]) sf = 0;
//             if(pre[i] % 2 == 1 && pre[i] > pos[i]) sf = 0;
//             if(pos[i] % 2 == 1 && pos[i] > pre[i]) sf = 0;
//             
//             
//             if(sf == 0){
//                 good[i] = 0;
//             }
//         }
//         rep(i,0,n){
//             if(good[i] == 0) continue;
//             if(maxlen == pre[i] || maxlen == pos[i]){
//                     good[i] = 2;
//             }
//         }
// 
//         rep(i,0,n){
//             if(good[i] == 2 && cnt == 0){
//                 good[i] = 1;
//                 continue;
//             }
//             if(good[i] == 2){
//                 good[i] = 1;
//             }
//             if(max(pre[i],pos[i]) <= maxlen){
//                 good[i] = 0;
//             }
//         }
//         
//         wt(sum(good(n)));
//     }
// }