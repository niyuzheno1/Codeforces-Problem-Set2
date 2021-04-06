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
var c =  IntArray(1000,{0});
var d =  IntArray(1000,{0});
fun main(){
  var PiIOrLma : Int =  0;
  var t : Int =  0;
  t= rd(t);
  for(PiIOrLma in 0..(t-1)){
    var i : Int =  0;
    var ops : Long =  0;
    var x : Long =  0;
    var y : Long =  0;
    var z : Long =  0;
    x= rd(x);
    y= rd(y);
    z = 1000000000;
    ops = 0;
    for(i in 1..(12-1)){
      if(z * x > 1000000000){
        z = z/10;
      }
      else{
        if(y >= z*x){
          var w : Long =  0;
          w  = y/(z*w);
          ops = ops + w;
          y = y - w *(z*x);
        }
      }
    }
    println("${ops}");
  }
}