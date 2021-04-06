//no-unlocked
int a[250010];
int occ[250010];
int b[500010];
int f[500010];
int lb;
int lf;
{
 int @t;
 rep(t){
    int @n;
    rd(a(n));
    lb = 0;
    lf = 0;
    rep(i,0,n+4){
     occ[i]= -1;
     b[i] = 0;
     f[i] = 0;
    }
    rep(i,0,n){
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
    rep(i,1,n+1){
       int x, info;
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
          }else{
             f[0] = x;
          }
          continue;
       }
       info = bsearch_max [ int, k, 0 , lf-1 ]  ( f[k] < x );
       if(info == lf-1){
        f[lf] = x;
        lf = lf + 1;
       }else{
          if(f[info] < x){
             f[info + 1] = x;
             if(info +1 > lf -1){
                lf = lf + 1;
             }
          }
          else
          {
            f[info] = x;
          }
       }
    }
    lf = lf  + 1;
    wt(lf);
 }
}
