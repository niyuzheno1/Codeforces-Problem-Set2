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
char S[110];
int N;
int main(){
  int i;
  N = rd(S);
  if(N == 1 || N == 2){
    wt_L("YES");
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    S[i] = S[i] - 'A';
  }
  bool flag = true;
  for(i=(2);i<(N);i++){
    if(S[i] == (S[i-1]+S[i-2])%26){
      continue;
    }
    flag = false;
  }
  if(flag){
    wt_L("YES");
    wt_L('\n');
  }
  if(!flag){
    wt_L("NO");
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char S[110];
// int N;
// {
//     rd(S@N);
//     if(N == 1 || N == 2){
//         wt("YES");
//         return 0;
//     }
//     rep(i,0,N) S[i] = S[i] - 'A';
//     bool flag = true;
//     rep(i,2,N){
//         if(S[i] == (S[i-1]+S[i-2])%26)
//             continue;
//         flag = false;
//     }
//     if(flag) wt("YES");
//     if(!flag) wt("NO");
// }