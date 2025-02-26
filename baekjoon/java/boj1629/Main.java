package boj1629;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();

        System.out.println(myPow(a, b, c));
    }

    private static long myPow(long a, long n, long mod) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return a % mod;
        }

        long half = myPow(a, n / 2, mod);

        if (n % 2 == 0) {
            return (half * half) % mod;
        } else {
            return ((half * half) % mod * a) % mod;
        }
    }

}
