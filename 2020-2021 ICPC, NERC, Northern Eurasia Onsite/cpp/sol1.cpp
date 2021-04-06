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
inline void rd(double &x){
  int k;
  int m=0;
  int p=0;
  double r = 1;
  x = 0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m = 1;
      break;
    }
    if(k=='.'){
      p = 1;
      break;
    }
    if('0'<=k&&k<='9'){
      x = k - '0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k=='.'){
      p = 1;
      continue;
    }
    if(k<'0'||k>'9'){
      break;
    }
    if(p){
      r *= 0.1;
      x += r * (k - '0');
    }
    else{
      x = x * 10 + k - '0';
    }
  }
  if(m){
    x = -x;
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
int WRITER_DOUBLE_DIGIT = 15;
inline int writerDigit_double(){
  return WRITER_DOUBLE_DIGIT;
}
inline void writerDigit_double(int d){
  WRITER_DOUBLE_DIGIT = d;
}
inline void wt_L(double x){
  const int d = WRITER_DOUBLE_DIGIT;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
const int MN = 100000;
const int dbg = 0;
int n;
int d;
double a[MN];
long long b[MN];
double f[MN][10];
int c[MN][10][2];
int ans[MN];
int sz;
void add_array(int x){
  arrInsert(sz, sz, ans,x);
}
int main(){
  int i;
  rd(n);
  rd(d);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(n);Lj4PdHRW++){
      rd(a[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(n);i++){
    b[i] = round(a[i]);
    a[i] = log(a[i])/log(1000);
  }
  for(i=(0);i<(n);i++){
    if(i!=0){
      int j;
      for(j=(0);j<(10);j++){
        f[i][j] = f[i-1][j];
        c[i][j][0] = c[i-1][j][0];
        c[i][j][1] = c[i-1][j][1];
      }
      for(j=(0);j<(10);j++){
        if(f[i-1][j] + a[i] > f[i][(j*b[i])%10]){
          f[i][(j*b[i])%10] = f[i-1][j] + a[i];
          c[i][(j*b[i])%10][0] = i;
          c[i][(j*b[i])%10][1] = j;
        }
      }
      if(f[i][b[i]%10] < a[i]){
        f[i][b[i]%10] = a[i];
        c[i][b[i]%10][0] = i;
        c[i][b[i]%10][1] = -1;
      }
      continue;
    }
    if(i == 0){
      int j;
      for(j=(0);j<(10);j++){
        f[i][j] = 0;
        c[i][j][0] = -1;
        c[i][j][1] = -1;
      }
      f[i][b[0]%10] = a[0];
      c[i][b[0]%10][0] = 0;
      c[i][b[0]%10][1] = -1;
    }
  }
  if(dbg){
    wt_L(f[n-1][d]);
    wt_L('\n');
  }
  if(f[n-1][d] == 0){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  int x = c[n-1][d][0];
  int y = c[n-1][d][1];
  while(y != -1){
    add_array(b[x]);
    int u = x-1;
    if(u < 0){
      break;
    }
    x = c[u][y][0];
    y = c[u][y][1];
  }
  if(x >= 0){
    add_array(b[x]);
  }
  wt_L(sz);
  wt_L('\n');
  {
    int V9aVTaxx;
    if(sz==0){
      wt_L('\n');
    }
    else{
      for(V9aVTaxx=(0);V9aVTaxx<(sz-1);V9aVTaxx++){
        wt_L(ans[V9aVTaxx]);
        wt_L(' ');
      }
      wt_L(ans[V9aVTaxx]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 1d5;
// const int dbg = 0;
// int n,d;
// double a[MN];
// ll b[MN];
// double f[MN][10];
// int c[MN][10][2];
// int ans[MN],sz;
// void add_array(int x){
//     arrInsert(sz, sz, ans,x);
// }
// {
//     rd(n,d, a(n));
//     rep(i,n){
//         b[i] = round(a[i]);
//         a[i] = log(a[i])/log(1000);
//     }
//     rep(i,n){
//         if(i!=0){
//             rep(j,10){
//                 f[i][j] = f[i-1][j];
//                 c[i][j][0] = c[i-1][j][0];
//                 c[i][j][1] = c[i-1][j][1];
//             }
//             rep(j,10){
//                 if(f[i-1][j] + a[i] > f[i][(j*b[i])%10]){
//                     f[i][(j*b[i])%10] = f[i-1][j] + a[i];
//                     c[i][(j*b[i])%10][0] = i;
//                     c[i][(j*b[i])%10][1] = j;
//                 }
//             }
//             if(f[i][b[i]%10] < a[i]){
//                 f[i][b[i]%10] = a[i];
//                 c[i][b[i]%10][0] = i;
//                 c[i][b[i]%10][1] = -1;    
//             }
//             continue;
//         }
//         if(i == 0){
//             rep(j,10){
//                 f[i][j] = 0;
//                 c[i][j][0] = -1;
//                 c[i][j][1] = -1;
//             }
//             f[i][b[0]%10] = a[0];
//             c[i][b[0]%10][0] = 0;
//             c[i][b[0]%10][1] = -1;
//         }
//     }
//     if(dbg){
//         wt(f[n-1][d]);
//     }
//     if(f[n-1][d] == 0) { wt(-1); return 0;}
//     int x = c[n-1][d][0], y = c[n-1][d][1];
//     while(y != -1){
//         add_array(b[x]);
//         
//         int u = x-1;
//         if(u < 0) break;
//         x = c[u][y][0];
//         y = c[u][y][1];
//     }
//     if(x >= 0)
//         add_array(b[x]);
//     wt(sz);
//     wt(ans(sz));
// }