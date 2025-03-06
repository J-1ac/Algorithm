package boj9465;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][2];
            int[][] dp = new int[n][2];

            for (int i = 0; i < n; i++) {
                a[i][0] = sc.nextInt();
            }
            for (int i = 0; i < n; i++) {
                a[i][1] = sc.nextInt();
            }

            if (n == 1) {
                System.out.println(Math.max(a[0][0], a[0][1]));
                continue;
            }

            dp[0][0] = a[0][0];
            dp[0][1] = a[0][1];
            dp[1][0] = dp[0][1] + a[1][0];
            dp[1][1] = dp[0][0] + a[1][1];

            for (int i = 2; i < n; i++) {
                dp[i][0] = Math.max(dp[i - 1][1], Math.max(dp[i - 2][0], dp[i - 2][1])) + a[i][0];
                dp[i][1] = Math.max(dp[i - 1][0], Math.max(dp[i - 2][0], dp[i - 2][1])) + a[i][1];
            }

            System.out.println(Math.max(dp[n - 1][0], dp[n - 1][1]));
        }
    }
}
