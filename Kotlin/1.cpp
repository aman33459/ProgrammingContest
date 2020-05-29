import java.util.*

fun main(args: Array<String>) {
    //some missing changes
    val reader = Scanner(System.`in`)
    var t:Int = reader.nextInt()
    while(t > 0){
        // nextInt() reads the next integer from the keyboard
        var n:Int = reader.nextInt()
        var k:Int = reader.nextInt()
        var n1:Int = (n/(1+ k + k * k + k * k * k))
        var n2 = k*n1
        var n3 = k*n2
        var n4 = k*n3
        println("$n1 $n2 $n3 $n4")
        t= t -1;
    }
}
