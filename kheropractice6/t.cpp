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
int a[250010];
int occ[250010];
int b[500010];
int f[500010];
int lb;
int lf;
int main(){
  int Lj4PdHRW;
  int t;
  rd(t);
  for(Lj4PdHRW=(0);Lj4PdHRW<(t);Lj4PdHRW++){
    int i;
    int n;
    rd(n);
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<(n);e98WHCEY++){
        rd(a[e98WHCEY]);
      }
    }
    lb = 0;
    lf = 0;
    for(i=(0);i<(n+4);i++){
      occ[i]= -1;
      b[i] = 0;
      f[i] = 0;
    }
    for(i=(0);i<(n);i++){
      if(occ[a[i]] != -1){
        b[lb] = 2*occ[a[i]] + 1;
        lb = lb + 1;
        if(i > occ[a[i]] + 1){
          b[lb] = 2*occ[a[i]];
          lb = lb + 1;
        }
      }
      occ[a[i]] = i;
    }
    n = lb;
    for(i=(1);i<(n+1);i++){
      int x;
      int info;
      x = b[n-i];
      if(lf == 0){
        f[lf] = x;
        lf = lf + 1;
        continue;
      }
      if(lf == 1){
        if(f[0] < x){
          f[1] = x;
          lf = lf+1;
        }
        else{
          f[0] = x;
        }
        continue;
      }
      int tU__gIr_;
      int a2conNHc;
      int hCmBdyQB;
      tU__gIr_ = 0;
      a2conNHc = lf-1;
      while(tU__gIr_ < a2conNHc){
        if((tU__gIr_ + a2conNHc)%2==0){
          hCmBdyQB = (tU__gIr_ + a2conNHc) / 2;
        }
        else{
          hCmBdyQB = (tU__gIr_ + a2conNHc + 1) / 2;
        }
        if( f[hCmBdyQB] < x ){
          tU__gIr_ = hCmBdyQB;
        }
        else{
          a2conNHc = hCmBdyQB - 1;
        }
      }
      info =a2conNHc;
      if(info == lf-1){
        f[lf] = x;
        lf = lf + 1;
      }
      else{
        if(f[info] < x){
          f[info + 1] = x;
          if(info +1 > lf -1){
            lf = lf + 1;
          }
        }
        else{
          f[info] = x;
        }
      }
    }
    lf = lf  + 1;
    wt_L(lf);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int a[250010];
// int occ[250010];
// int b[500010];
// int f[500010];
// int lb;
// int lf;
// {
//  int @t;
//  rep(t){
//     int @n;
//     rd(a(n));
//     lb = 0;
//     lf = 0;
//     rep(i,0,n+4){
//      occ[i]= -1;
//      b[i] = 0;
//      f[i] = 0;
//     }
//     rep(i,0,n){
//       	if(occ[a[i]] != -1){
//          b[lb] = 2*occ[a[i]] + 1;
// 	 lb = lb + 1;
// 	 if(i > occ[a[i]] + 1){
// 	   b[lb] = 2*occ[a[i]];
// 	   lb = lb + 1;
// 	 }
// 	}
// 	occ[a[i]] = i;
//     }
//     n = lb;
//     rep(i,1,n+1){
//        int x, info;
//        x = b[n-i];
//        if(lf == 0){
//           f[lf] = x;
//           lf = lf + 1;
//           continue;
//        }
//        if(lf == 1){
//           if(f[0] < x){
//              f[1] = x;
//              lf = lf+1;
//           }else{
//              f[0] = x;
//           }
//           continue;
//        }
//        info = bsearch_max [ int, k, 0 , lf-1 ]  ( f[k] < x );
//        if(info == lf-1){
//         f[lf] = x;
//         lf = lf + 1;
//        }else{
//           if(f[info] < x){
//              f[info + 1] = x;
//              if(info +1 > lf -1){
//                 lf = lf + 1;
//              }
//           }
//           else
//           {
//             f[info] = x;
//           }
//        }
//     }
//     lf = lf  + 1;
//     wt(lf);
//  }
// }
