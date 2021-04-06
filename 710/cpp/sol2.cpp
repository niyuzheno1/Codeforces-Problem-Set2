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
char s[52];
int n;
int k;
int T;
int main(){
  int Lj4PdHRW;
  rd(T);
  for(Lj4PdHRW=(0);Lj4PdHRW<(T);Lj4PdHRW++){
    int i;
    rd(n);
    rd(k);
    rd(s);
    int first = -1;
    int last = -1;
    for(i=(0);i<(n);i++){
      if(s[i] == '*'){
        first = i;
        break;
      }
    }
    for(i=(n)-1;i>=(0);i--){
      if(s[i] == '*'){
        last = i;
        break;
      }
    }
    s[first] = 'x';
    s[last] = 'x';
    int pre;
    pre = first;
    int j;
    j = pre+1;
    while(last-j >= k){
      int pos = -1;
      for(i=(j + k)-1;i>=(j);i--){
        if(s[i] == '*'){
          pos = i;
          break;
        }
      }
      s[pos] = 'x';
      j = pos + 1;
    }
    int ans = 0;
    for(i=(0);i<(n);i++){
      ans += (s[i] == 'x') ? 1 : 0;
    }
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char s[52];
// int n,k, T;
// {
//     rd(T);
//     rep(T){
//         rd(n,k,s);
//         int first = -1,last = -1;
//         rep(i,n){
//             if(s[i] == '*') { first = i; break;}
//         }
//         rrep(i,n){
//             if(s[i] == '*') {last = i; break;}
//         }
//         s[first] = 'x';
//         s[last] = 'x';
//         int pre;
//         pre = first;
//         int j;
//         j = pre+1;
//         while(last-j >= k){
//             int pos = -1;
//             rrep(i, j, j + k){
//                 if(s[i] == '*'){
//                     pos = i;
//                     break;
//                 }
//             }
//             s[pos] = 'x';
//             j = pos + 1;
//         }
//         int ans = 0;
//         rep(i,n){
//             ans += (s[i] == 'x') ? 1 : 0;
//         }
//         wt(ans);
//     }
// }
// //yyxs