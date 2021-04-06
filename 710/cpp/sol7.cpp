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
int hist[28];
int selected[28];
char d[200000];
char ans[200000];
int n;
int m;
int am;
int T;
int pos;
int main(){
  int Lj4PdHRW;
  rd(T);
  for(Lj4PdHRW=(0);Lj4PdHRW<(T);Lj4PdHRW++){
    int c, i;
    m = 0;
    am = 0;
    n = rd(s);
    for(c=('z'+1)-1;c>=('a');c--){
      int i;
      for(i=(n)-1;i>=(0);i--){
        selected[s[i]-'a'] = 0;
        hist[s[i]-'a'] = 0;
      }
      for(i=(0);i<(n);i++){
        selected[s[i]-'a'] = 1;
      }
      pos = -1;
      for(i=(n)-1;i>=(0);i--){
        int j;
        bool flag;
        flag = true;
        ++hist[s[i]-'a'];
        for(j=(0);j<('z'-'a'+1);j++){
          if(selected[j] > 0 && hist[j] == 0){
            flag = false;
            break;
          }
        }
        if(flag && (pos == -1 || s[pos] <= s[i])){
          pos = i;
        }
      }
      ans[am++] =  s[pos];
      m = 0;
      for(i=(pos+1);i<(n);i++){
        if(s[i] == s[pos]){
          continue;
        }
        d[m++] = s[i];
      }
      for(i=(0);i<(m);i++){
        s[i] = d[i];
      }
      s[m] = 0;
      n = m;
      if(n <= 0){
        break;
      }
    }
    for(i=(0);i<(n);i++){
      ans[am++] = s[i];
    }
    ans[am] = 0;
    wt_L(ans);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// char s[2d5];
// int hist[28];
// int selected[28];
// char d[2d5];
// char ans[2d5];
// int n,m,am,T, pos;
// {
//     rd(T);
//     rep(T){
//         m = 0;
//         am = 0;
//         rd(s@n);
//         rrep(c,'a', 'z'+1){
//             rrep(i,n){
//                 selected[s[i]-'a'] = 0;
//                 hist[s[i]-'a'] = 0;
//             }
//             rep(i,n) selected[s[i]-'a'] = 1;
//             pos = -1;
//             rrep(i,n){
//                 bool flag;
//                 flag = true;
//                 ++hist[s[i]-'a'];
//                 rep(j,0, 'z'-'a'+1){
//                     if(selected[j] > 0 && hist[j] == 0){
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag && (pos == -1 || s[pos] <= s[i]))
//                     pos = i;
//                     
//             }
//             ans[am++] =  s[pos];
//             m = 0;
//             rep(i,pos+1,n){
//                 if(s[i] == s[pos]) continue;
//                 d[m++] = s[i];
//             }
//             rep(i,0,m){
//                 s[i] = d[i];
//             }
//             s[m] = 0;
//             n = m;
//             if(n <= 0) break;
//         }
//         rep(i,0,n){
//             ans[am++] = s[i];
//         }
//         ans[am] = 0;
//         wt(ans);
//     }
// }
// //yyxs