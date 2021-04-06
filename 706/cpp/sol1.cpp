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
char s[110];
int main(){
  int Lj4PdHRW;
  int t;
  rd(t);
  for(Lj4PdHRW=(0);Lj4PdHRW<(t);Lj4PdHRW++){
    int n;
    rd(n);
    int k;
    rd(k);
    {
      int e98WHCEY;
      for(e98WHCEY=(0);e98WHCEY<(n);e98WHCEY++){
        rd(s[e98WHCEY]);
      }
    }
    if(k == 0){
      wt_L("Yes");
      wt_L('\n');
    }
    else{
      int i;
      bool flag;
      flag = true;
      for(i=(0);i<(k);i++){
        if(s[i] != s[n-i-1]){
          flag = false;
        }
      }
      if(2 * k == n){
        flag = false;
      }
      if(!flag){
        wt_L("No");
        wt_L('\n');
      }
      else{
        wt_L("Yes");
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char s[110];
// {
//     int @t;
//     rep(t){
//         int @n, @k;
//         rd(s(n));
//         if(k == 0){
//             wt("Yes");
//         }else{
//             bool flag;
//             flag = true;
//             rep(i,0,k){
//                 if(s[i] != s[n-i-1]){
//                     flag = false;
//                 }
//             }
//             if(2 * k == n){
//                 flag = false;
//             }
//             if(!flag){
//                 wt("No");
//             }else{
//                 wt("Yes");
//             }
//         }
//     }
// }