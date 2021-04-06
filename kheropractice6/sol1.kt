import java.io.*;
import java.util.*;
import kotlin.system.exitProcess;
class Kattio : PrintWriter{
  @JvmField val r : BufferedReader;
  @JvmField var st = StringTokenizer("");
  constructor() : this(System.`in`,System.out) {}
constructor(i : InputStream, o : OutputStream) : super(o, false) { r = i.bufferedReader(); }
fun rLine() : String ?= r.readLine();
  fun read() : String{
while (st.hasMoreTokens().not()) st =
StringTokenizer(rLine() ?: return "", " ")
return st.nextToken();
};
  fun strs(n : Int) = List(n) { read(); };
  fun ln() = rLine()!!;
  fun lns(n: Int) = List(n) { ln() };
  fun int() = read().toInt();
  fun ints(n: Int) = List(n) { int() };
  fun db() = read().toDouble();
  fun rDbs(n: Int) = List(n) { db() };
  fun long() = read().toLong()
fun longs(n: Int) = List(n) { long() };
}
;
val io = Kattio();
private fun rd(x : Int) = io.int();
private fun rd(x : Long) = io.long();
var a =  IntArray(250010);
var b =  IntArray(500010);
var f =  IntArray(500010);
var lb : Int =  0;
var lf : Int =  0;
var occ =  IntArray(250010);
fun main(){
  var PiIOrLma : Int =  0;
  var t : Int =  0;
  t= rd(t);
  for(PiIOrLma in 0..(t-1)){
    var GIHf_YD2 : Int =  0;
    var i : Int =  0;
    var n : Int =  0;
    n= rd(n);
    for(GIHf_YD2 in 0..(n-1)){
      a[GIHf_YD2] = rd(a[GIHf_YD2]);
    }
    lb = 0;
    lf = 0;
    for(i in 0..(n+4-1)){
      occ[i]= -1;
      b[i] = 0;
      f[i] = 0;
    }
    for(i in 0..(n-1)){
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
    for(i in 1..(n+1-1)){
      var GN2MVvSr : Int =  0;
      var OUHHcm5g : Int =  0;
      var Yd8JT4OW : Int =  0;
      var info : Int =  0;
      var x : Int =  0;
      x = b[n-i];
      Yd8JT4OW = 0;
      GN2MVvSr = lf;
      while(Yd8JT4OW < GN2MVvSr){
        if((Yd8JT4OW + GN2MVvSr) and 1 <= 0){
          OUHHcm5g = (Yd8JT4OW + GN2MVvSr) shr 1;
        }
        else{
          OUHHcm5g = (Yd8JT4OW + GN2MVvSr + 1) shr 1;
        }
        if(OUHHcm5g >= lf){
          OUHHcm5g = lf-1;
        }
        if( f[OUHHcm5g]<=x ){
          Yd8JT4OW = OUHHcm5g;
        }
        else{
          GN2MVvSr = OUHHcm5g - 1;
        }
      }
      info =GN2MVvSr;
      if(info == lf){
        f[lf] = x;
        lf = lf + 1;
      }
      else{
        f[info] = x;
      }
    }
    lf = lf + 1;
    print(lf);
    print('\n');
  }
}
// KotLay version 20210309-1

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
//              if(occ[a[i]] != -1){
//          b[lb] = 2*occ[a[i]] + 1;
//       lb = lb + 1;
//       if(i > occ[a[i]] + 1){
//         b[lb] = 2*occ[a[i]];
//         lb = lb + 1;
//       }
//      }
//      occ[a[i]] = i;
//     }
//     n = lb;
//     rep(i,1,n+1){
//        int x, info;
//        x = b[n-i];
//        info = bsearch_max [ int, k, 0 , lf ] [ if(k >= lf){k = lf-1;}] ( f[k]<=x );
//        if(info == lf){
//         f[lf] = x;
//         lf = lf + 1;
//        }else{
//         f[info] = x;
//        }
//     }
//     lf = lf + 1;
//     wt(lf);
//  }
// }