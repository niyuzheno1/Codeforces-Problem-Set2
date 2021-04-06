#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
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
inline void rd(long long &x){
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
const long long N = 2000000+2;
long long n;
long long m;
long long a[N];
long long b[N];
int c[N];
int d[N];
int main(){
  int i;
  rd(n);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(n);Lj4PdHRW++){
      rd(a[Lj4PdHRW]);
      rd(b[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(n);i++){
    int dir = 0;
    if(a[i] > b[i]){
      swap(a[i],b[i]);
      dir = 1;
    }
    if(a[i] > n || b[i] <= n){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
    c[a[i]] = b[i];
    d[a[i]] = dir;
  }
  set<int> s;
  for(i=(0);i<(n+1);i++){
    s.insert(n+i);
  }
  vector<int> use;
  use.push_back(0);
  for(i=(1);i<(n+1);i++){
    s.erase(c[i]);
    if(i + *s.rbegin() == 2*n){
      use.push_back(i);
    }
  }
  int ans = 0;
  for(i=(1);i<(use.size());i++){
    int j;
    int l = use[i-1]+1;
    int r = use[i];
    int mn = 1e9;
    int mx = 1e9;
    int res = 0;
    for(j=(l);j<(r+1);j++){
      if(c[j] > mn){
        if(c[j] > mx){
          wt_L(-1);
          wt_L('\n');
          return 0;
        }
        res += (d[j] != 1);
        mx = c[j];
      }
      else{
        res += (d[j] != 0);
        mn = c[j];
      }
    }
    ans +=min_L(res, r-l+1-res);
  }
  wt_L(ans);
  wt_L('\n');
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const ll N = 2d6+2;
// ll n,m;
// ll a[N], b[N];
// int c[N], d[N];
// {
//     rd(n, (a,b)(n));
//     rep(i,0,n){
//         int dir = 0;
//         if(a[i] > b[i]){
//             swap(a[i],b[i]);
//             dir = 1;
//         }
//         if(a[i] > n || b[i] <= n){
//             wt(-1);
//             return 0;
//         }
//         c[a[i]] = b[i];
//         d[a[i]] = dir;
//     }
//     set<int> s;
//     rep(i,0,n+1) s.insert(n+i);
//     vector<int> use; use.push_back(0);
//     rep(i,1,n+1){
//         s.erase(c[i]);
//         if(i + *s.rbegin() == 2*n) use.push_back(i);
//     }
//     int ans = 0;
//     rep(i,1,use.size()){
//         int l = use[i-1]+1, r = use[i];
//         int mn = 1e9;
//         int mx = 1e9;
//         int res = 0;
//         rep(j,l,r+1){
//             if(c[j] > mn){
//                 if(c[j] > mx){
//                     wt(-1);
//                     return 0;
//                 }
//                 res += (d[j] != 1);
//                 mx = c[j];
//             }else{
//                 res += (d[j] != 0);
//                 mn = c[j];
//             }
//         }
//         ans += min(res, r-l+1-res);
//     }
// 
//     wt(ans);
// }