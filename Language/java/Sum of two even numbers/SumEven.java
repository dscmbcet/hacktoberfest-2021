import java.util.*;

public class SumEven {
    // for a given positive integer 'x',
    // print "YES" if x can be written as sum of two even numbers greater than 0.
    // print "NO" otherwise
    public static void main(String[] args) {
        int x;
        x = new Scanner(System.in).nextInt();

        if (x % 2 == 0) {
            System.out.println("YES");
        }

        else {
            System.out.println("NO");
        }
    }
}
