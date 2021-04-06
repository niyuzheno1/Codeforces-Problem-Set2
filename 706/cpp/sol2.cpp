#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
template<class S, class T> inline S divup_L(S a, T b){
  return (a+b-1)/b;
}
int a[100010];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int t;
  rd(t);
  for(Lj4PdHRW=(0);Lj4PdHRW<(t);Lj4PdHRW++){
    int n;
    rd(n);
    int k;
    rd(k);
    int ans;
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<(n);e98WHCEY++){
        rd(a[e98WHCEY]);
      }
    }
    sortA_L(n,a);
    ans = n;
    if(k == 0){
      wt_L(n);
      wt_L('\n');
      continue;
    }
    if(a[0] != 0){
      int i;
      int b =(divup_L((a[n-1]),2));
      for(i=(0);i<(n);i++){
        if(a[i] == b){
          b = -1;
        }
      }
      if(b != -1){
        ans = ans + 1;
      }
    }
    else{
      int i;
      int mex;
      mex = 0;
      for(i=(0);i<(n);i++){
        if(a[i] != mex){
          break;
        }
        mex = mex + 1;
      }
      if(mex == n){
        ans = ans + k;
      }
      else{
        int b =(divup_L((mex + a[n-1]),2));
        for(i=(0);i<(n);i++){
          if(a[i] == b){
            b = -1;
          }
        }
        if(b != -1){
          ans = ans + 1;
        }
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
// int a[100010];
// {
//     int @t;
//     rep(t){
//         int @n, @k;
//         int ans;
//         rd(a(n));
//         sortA(n,a);
//         ans = n;
//         if(k == 0){
//             wt(n);
//             continue;
//         }
//         if(a[0] != 0){
//             int b = (a[n-1])/+2;
//             rep(i,0,n){
//                 if(a[i] == b){
//                     b = -1;
//                 }
//             }
//             
//             if(b != -1){
//                     ans = ans + 1;
//             }
//         }else{
//             int mex;
//             mex = 0;
//             rep(i,0,n){
//                 if(a[i] != mex){
//                     break;
//                 }
//                 mex = mex + 1;
//             }
//             
//             if(mex == n){
//                 ans = ans + k;
//             }else{
//                 int b = (mex + a[n-1])/+2;
//                 rep(i,0,n){
//                     if(a[i] == b){
//                         b = -1;
//                     }
//                 }
//                 if(b != -1){
//                     ans = ans + 1;
//                 }
//             }
//         }
//         wt(ans);
//     }
//     
// }