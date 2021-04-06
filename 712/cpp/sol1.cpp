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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
char s[200000];
char A[300000];
int n ;
int main(){
  int Lj4PdHRW;
  int Tcases;
  rd(Tcases);
  for(Lj4PdHRW=(0);Lj4PdHRW<(Tcases);Lj4PdHRW++){
    int i;
    rd(n);
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<(n);e98WHCEY++){
        rd(s[e98WHCEY]);
      }
    }
    for(i=(0);i<(n);i++){
      s[i] = s[i]-'0';
    }
    int WYIGIcGE;
    char t_ynMSdg;
    if(n==0){
      t_ynMSdg = 0;
    }
    else{
      t_ynMSdg = s[0];
      for(WYIGIcGE=(1);WYIGIcGE<(n);WYIGIcGE++){
        t_ynMSdg += s[WYIGIcGE];
      }
    }
    int ones = t_ynMSdg;
    if(s[0] != 1 || s[n-1] != 1 || (n-ones) % 2 == 1){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    int cnt[2] = {0,0};
    for(i=(0);i<(n);i++){
      ++cnt[s[i]];
    }
    A[0] = '(';
    A[n-1] = ')';
    for(i=(1);i<(n-1);i++){
      if(cnt[s[i]] % 2 == 0){
        A[i] = '(';
      }
      else{
        A[i] = ')';
      }
      --cnt[s[i]];
    }
    A[n] = 0;
    wt_L("YES");
    wt_L('\n');
    wt_L(A);
    wt_L('\n');
    for(i=(0);i<(n);i++){
      if(s[i] == 0){
        A[i] = A[i] == '(' ? ')' : '(';
      }
    }
    wt_L(A);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char s[2d5];
// char A[3d5];
// int n ;
// {
//     int @Tcases;
//     rep(Tcases){
//         rd(n,s(n));
//         rep(i,n) s[i] = s[i]-'0';
//         int ones = sum(s(n));
//         if(s[0] != 1 || s[n-1] != 1 || (n-ones) % 2 == 1){
//             wt("NO");
//             continue;
//         }
//         int cnt[2] = {0,0};
//         
//         rep(i,n) ++cnt[s[i]];
//         A[0] = '(';
//         A[n-1] = ')';
//         rep(i,1,n-1){
//             if(cnt[s[i]] % 2 == 0){
//                 A[i] = '(';
//             }else{
//                 A[i] = ')';
//             }
//             --cnt[s[i]];
//         }
//         A[n] = 0;
//         wt("YES");
//         wt(A);
//         rep(i,0,n){
//             if(s[i] == 0){
//                 A[i] = A[i] == '(' ? ')' : '(';
//             }
//         }
//         wt(A);
//     }
// }