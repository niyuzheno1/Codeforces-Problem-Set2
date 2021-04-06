#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setEdgeRootedTree(int N__, int M, int A[], int B[], int root=0, int reorder=0, int cnv[] = NULL, void **mem = &wmem){
    int i;
    int j;
    int k;
    int*dist;
    int*q;
    int qs;
    int qe;
    int*ind;
    void*tmem;
    N = N__;
    tmem = ((char*)(*mem)) + (sizeof(int) * N + 15) + (sizeof(int*) * N + 15) + (sizeof(int) * M + 15 * N);
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], &tmem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
    walloc1d(&dist, N, &tmem);
    walloc1d(&q, N, &tmem);
    walloc1d(&ind, N, &tmem);
    if(cnv==NULL){
      walloc1d(&cnv, N, &tmem);
    }
    for(i=(0);i<(N);i++){
      dist[i] = -1;
    }
    dist[root] = 0;
    qs = qe = 0;
    q[qe++] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(dist[k]==-1){
          dist[k] = dist[i] + 1;
          q[qe++] = k;
        }
      }
    }
    if(reorder == 0){
      for(i=(0);i<(N);i++){
        cnv[i] = i;
      }
      for(i=(0);i<(N);i++){
        ind[i] = i;
      }
    }
    else{
      for(i=(0);i<(N);i++){
        cnv[i] = q[i];
      }
      for(i=(0);i<(N);i++){
        ind[cnv[i]] = i;
      }
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      es[ind[j]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i];
      k = B[i];
      if(dist[j] > dist[k]){
        swap(j, k);
      }
      j = ind[j];
      k = ind[k];
      edge[j][es[j]++] = k;
    }
  }
  void SubTreeSize(int root, int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int m;
    int*q;
    int qs = 0;
    int qe = 1;
    walloc1d(&q,N,&mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    res[root] = 0;
    q[0] = root;
    while(qs < qe){
      i = q[qs++];
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        if(res[k]==0){
          continue;
        }
        res[k] = 0;
        q[qe++] = k;
      }
    }
    for(m=(N)-1;m>=(0);m--){
      i = q[m];
      res[i] = 1;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        res[i] += res[k];
      }
    }
  }
}
;
const int MN = 110;
graph g;
int p[MN];
int e1[MN];
int e2[MN];
int ans[MN];
int sz;
int f[MN][MN];
int csz[MN];
void add_array(int x){
  arrInsert(sz, sz, ans,x);
}
int dfs(int root,int x){
  int i;
  vector<pair<int,int>> vx;
  for(i=(0);i<(g.es[root]);i++){
    int m = g.edge[root][i];
    vx.push_back({csz[m],m});
  }
  if(f[root][x] != -1){
    return f[root][x];
  }
  if(x == 1 || x == 0){
    return f[root][x] = 0;
  }
  sort(vx.begin(), vx.end(), [&] (const pair<int,int> x, const pair<int,int> y){ return x.first > y.first; });
  int tx = x-1;
  int cur = 0;
  int ans = 1e9;
  int m = vx.size();
  while(vx.size() >= 2 && tx > 0){
    if(tx - vx[0].first > vx[1].first){
      cur += vx[0].first*2;
      tx -= vx[0].first;
      vx.erase(vx.begin());
      continue;
    }
    else if(tx <= vx[0].first){
      int j;
      for(j=(1);j<(m);j++){
        if(tx > vx[j].first){
          break;
        }
        chmin(ans, cur + dfs(vx[j].second, tx)+1);
      }
    }
    {
      int j;
      for(j=(1);j<(m);j++){
        int k;
        if(tx > vx[0].first+vx[j].first){
          break;
        }
        for(k=(0);k<(vx[j].first+1);k++){
          if(tx - k > vx[0].first){
            continue;
          }
          if(tx - k < 0){
            continue;
          }
          chmin(ans, cur + (tx - k)*2 + dfs(vx[j].second, k)+1);
        }
      }
      cur += vx[0].first*2;
      tx -= vx[0].first;
      vx.erase(vx.begin());
    }
  }
  if(vx.size() == 1 && tx > 0 ){
    if(vx[0].first < tx){
      return f[root][x] =  1e8;
    }
    chmin(ans, cur+1+dfs(vx[0].second,tx));
  }
  f[root][x] = ans;
  return ans;
}
void dfs3 (int root, int x){
  int i;
  if(x <= 0){
    return;
  }
  --x;
  add_array(root);
  for(i=(0);i<(g.es[root]);i++){
    int m = g.edge[root][i];
    dfs3(m,min_L(x, csz[m]));
    x -=min_L(x, csz[m]);
    add_array(root);
    if(x == 0){
      return;
    }
  }
}
void dfs2(int root,int x){
  int i;
  vector<pair<int,int>> vx;
  for(i=(0);i<(g.es[root]);i++){
    int m = g.edge[root][i];
    vx.push_back({csz[m],m});
  }
  if(x == 0){
    return;
  }
  add_array(root);
  if(x == 1 ){
    return ;
  }
  sort(vx.begin(), vx.end(), [&] (const pair<int,int> x, const pair<int,int> y){ return x.first > y.first; });
  int tx = x-1;
  int cur = 0;
  int ans = f[root][x];
  int m = vx.size();
  while(vx.size() >= 2 && tx > 0){
    if(tx - vx[0].first > vx[1].first){
      cur += vx[0].first*2;
      tx -= vx[0].first;
      vx.erase(vx.begin());
      dfs3(vx[0].second, vx[0].first);
      add_array(root);
      continue;
    }
    else if(tx <= vx[0].first){
      int j;
      for(j=(1);j<(m);j++){
        if(tx > vx[j].first){
          break;
        }
        if(ans == cur + dfs(vx[j].second, tx)+1){
          dfs2(vx[j].second, tx);
          return;
        }
      }
    }
    {
      int j;
      for(j=(1);j<(m);j++){
        int k;
        if(tx > vx[0].first+vx[j].first){
          break;
        }
        for(k=(0);k<(vx[j].first+1);k++){
          if(tx - k > vx[0].first){
            continue;
          }
          if(tx - k < 0){
            continue;
          }
          if(ans == cur + (tx - k)*2 + dfs(vx[j].second, k)+1){
            dfs3(vx[0].second, tx-k);
            add_array(root);
            dfs2(vx[j].second, k);
            return;
          }
        }
      }
      cur += vx[0].first*2;
      tx -= vx[0].first;
      dfs3(vx[0].second, vx[0].first);
      add_array(root);
      vx.erase(vx.begin());
    }
  }
  if(vx.size() == 1 && tx > 0 ){
    if(vx[0].first < tx){
      return;
    }
    if(ans == cur+1+dfs(vx[0].second,tx)){
      dfs2(vx[0].second,tx);
      return;
    }
  }
  f[root][x] = ans;
  return;
}
int main(){
  int jPV_0s1p;
  wmem = memarr;
  int Tcases;
  rd(Tcases);
  for(jPV_0s1p=(0);jPV_0s1p<(Tcases);jPV_0s1p++){
    int i;
    int n;
    int k;
    sz =0;
    rd(n);
    rd(k);
    {
      int GgkpftXM;
      for(GgkpftXM=(0);GgkpftXM<(n-1);GgkpftXM++){
        rd(p[GgkpftXM]);
      }
    }
    for(i=(0);i<(n-1);i++){
      e1[i] = p[i]-1;
      e2[i] = i+1;
    }
    for(i=(0);i<(n);i++){
      int j;
      for(j=(0);j<(n+2);j++){
        f[i][j] = -1;
      }
    }
    g.setEdgeRootedTree(n,n-1,e1,e2);
    g.SubTreeSize(0,csz);
    wt_L(dfs(0,k));
    wt_L('\n');
    dfs2(0,k);
    {
      int O3U4gd88;
      if(sz==0){
        wt_L('\n');
      }
      else{
        for(O3U4gd88=(0);O3U4gd88<(sz-1);O3U4gd88++){
          wt_L(++ans[O3U4gd88]);
          wt_L(' ');
        }
        wt_L(++ans[O3U4gd88]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// const int MN = 110;
// graph g;
// int p[MN];
// int e1[MN], e2[MN];
// int ans[MN],sz;
// int f[MN][MN];
// int csz[MN];
// void add_array(int x){
//     arrInsert(sz, sz, ans,x);
// }
// int dfs(int root,int x){
//     vector<pair<int,int>> vx;
//     rep(i,g.es[root]){
//         int m = g.edge[root][i];
//         vx.push_back({csz[m],m});
//     }
//     if(f[root][x] != -1){
//         return f[root][x];
//     }
//     if(x == 1 || x == 0){
//         return f[root][x] = 0;
//     }
//     sort(vx.begin(), vx.end(), [&] (const pair<int,int> x, const pair<int,int> y){ return x.first > y.first; });
//     int tx = x-1;
//     int cur = 0, ans = 1e9;
//     int m = vx.size();
//     while(vx.size() >= 2 && tx > 0){
//         if(tx - vx[0].first > vx[1].first){
//             cur += vx[0].first*2;
//             tx -= vx[0].first;
//             vx.erase(vx.begin());
//             continue;
//         }else if(tx <= vx[0].first){
//             rep(j,1,m){
//                 if(tx > vx[j].first) break;
//                 ans <?= cur + dfs(vx[j].second, tx)+1;
//             }
//         }
//         
//         {
//             rep(j,1,m){
//                 if(tx > vx[0].first+vx[j].first) break;
//                 rep(k, 0, vx[j].first+1){
//                     if(tx - k > vx[0].first) continue;
//                     if(tx - k < 0) continue;
//                     ans <?= cur + (tx - k)*2 + dfs(vx[j].second, k)+1 ;
//                 }
//             }
//             cur += vx[0].first*2;
//             tx -= vx[0].first;
//             vx.erase(vx.begin());
//         }
//     }
//     if(vx.size() == 1 && tx > 0 ){
//         if(vx[0].first < tx){
//             return f[root][x] =  1e8;
//         }
//         ans <?= cur+1+dfs(vx[0].second,tx);
//     }
//     f[root][x] = ans;
//     return ans;
// }
// void dfs3 (int root, int x){
//     if(x <= 0) return;
//     --x;
//     add_array(root);
//     rep(i,g.es[root]){
//         int m = g.edge[root][i];
//         dfs3(m, min(x,csz[m]));
//         x -= min(x,csz[m]);
//         add_array(root);
//         if(x == 0)
//             return;
//         
//     }
// }
// void dfs2(int root,int x){
//     vector<pair<int,int>> vx;
//     rep(i,g.es[root]){
//         int m = g.edge[root][i];
//         vx.push_back({csz[m],m});
//     }
//     if(x == 0) return;
//     add_array(root);
//     if(x == 1 ) return ;
//     sort(vx.begin(), vx.end(), [&] (const pair<int,int> x, const pair<int,int> y){ return x.first > y.first; });
//     int tx = x-1;
//     int cur = 0;
//     int ans = f[root][x];
//     int m = vx.size();
//     while(vx.size() >= 2 && tx > 0){
//         if(tx - vx[0].first > vx[1].first){
//             cur += vx[0].first*2;
//             tx -= vx[0].first;
//             vx.erase(vx.begin());
//             dfs3(vx[0].second, vx[0].first);
//             add_array(root);
//             continue;
//         }else if(tx <= vx[0].first){
//             rep(j,1,m){
//                 if(tx > vx[j].first) break;
//                 if(ans == cur + dfs(vx[j].second, tx)+1){
//                     dfs2(vx[j].second, tx);
//                     return;
//                 }
//             }
//         }
//         
//         {
//             rep(j,1,m){
//                 if(tx > vx[0].first+vx[j].first) break;
//                 rep(k, 0, vx[j].first+1){
//                     if(tx - k > vx[0].first) continue;
//                     if(tx - k < 0) continue;
//                     if(ans == cur + (tx - k)*2 + dfs(vx[j].second, k)+1){
//                         dfs3(vx[0].second, tx-k);
//                         add_array(root);
//                         dfs2(vx[j].second, k);
//                         return;
//                     }
//                 }
//             }
//             cur += vx[0].first*2;
//             tx -= vx[0].first;
//             dfs3(vx[0].second, vx[0].first);
//             add_array(root);
//             vx.erase(vx.begin());
//         }
//     }
//     if(vx.size() == 1 && tx > 0 ){
//         if(vx[0].first < tx){
//             return;
//         }
//         if(ans == cur+1+dfs(vx[0].second,tx)){
//             dfs2(vx[0].second,tx);
//             return;
//         }
//     }
//     f[root][x] = ans;
//     return;
// }
// {
//     int @Tcases;
//     rep(Tcases){
//         int n,k;
//         sz =0; 
//         rd(n,k,p(n-1));
//         rep(i, n-1){
//             e1[i] = p[i]-1;
//             e2[i] = i+1;
//         }
//         rep(i,n)
//             rep(j,n+2)
//                 f[i][j] = -1;
//         g.setEdgeRootedTree(n,n-1,e1,e2);
//         g.SubTreeSize(0,csz);
//       
//         wt(dfs(0,k));
//         dfs2(0,k);
//         wt((++ans)(sz));
//     }
// }