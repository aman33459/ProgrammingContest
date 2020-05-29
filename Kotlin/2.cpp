import java.util.*
import java.util.Collections.min
import kotlin.math.min

fun main(args: Array<String>) {
    //some missing changes
    val reader = Scanner(System.`in`)
    var t:Int = reader.nextInt()
    while(t > 0){
        // nextInt() reads the next integer from the keyboard
        var n:Int = reader.nextInt()
        var k:Int = reader.nextInt()
        var k1:Int = reader.nextInt()

        val s = reader.next()

        var i :Int = 0;
        var ans : Int = 0;
        var  curr:Int = 0
        var f :Int = 0
        while(i < s.length) {
            if(s[i] == '1'){
                if(f == 0){
                    ans =ans + k
                    curr = k
                    f=1
                }
                else {
                    ans = ans + min(k,(k1-curr))
                    curr = min(k,k1-curr)
                }
            }
            else f=0;
            i++
        }
        println("$ans")
        //println("$s")
        t= t -1;
    }
}
