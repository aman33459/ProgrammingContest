import java.util.*
import java.util.Collections.min
import kotlin.math.min

fun main(args: Array<String>) {
    //some missing changes
    val reader = Scanner(System.`in`)
    var t:Long = reader.nextLong()
    while(t > 0){
        // nextLong() reads the next Longeger from the keyboard
        var n: Int = reader.nextInt()
        var k: Long = reader.nextLong()
        var x : Long = reader.nextLong()
        var y : Long = reader.nextLong()
        var sum : Long = 0
        var a = Array<Long>(n){ Long.MAX_VALUE}
        for(i in 0..n-1){
            a[i] = reader.nextLong()
            sum = sum + a[i]
        }
        a.sort();
        var ok:Int=-1
        for(i in 0..n-1){
            if(a[i] >k) {
                ok=i
                break
            }
        }
       // prLongln("$ok $sum $n **")
        if(ok == -1){
            println("0")
        }
        else if((n-ok)*x <= y ){
            var tmp:Long = (n-ok)*x
            println("$tmp")
        }
        else{
            var temp :Long = sum/n;
            if(sum%n != 0L) temp++
            if(temp <=k) println("$y")
            else{
                var ans :Long = 0
                for(i in n-1 downTo 0){
                    if((i-ok+1)*x <= x+y) {
                        ans = ans + (i-ok+1)*x;
                        break;
                    }
                    ans = ans +x;
                    sum = sum - a[i]
                    temp = sum/n;
                    if(sum%n != 0L) temp++
                    if(temp <=k ) {
                        ans = ans + y
                        break
                    }
                }
                println("$ans")
            }
        }
        t= t -1;
    }
}
