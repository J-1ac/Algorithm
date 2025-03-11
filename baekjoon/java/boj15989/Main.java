package boj15989;

import java.util.Scanner;

/**
 * n−k 를 만들 때 마지막 수가 k이하 인 모든 방법의 합
 * dp[n,1] = dp[n-1,1];
 * dp[n,2] = dp[n-2,1] + dp[n-2,2];
 * dp[n,3] = dp[n-3,1] + dp[n-3,2] + dp[n-3,3];
 */

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        int dp[][] = new int[100001][3];
        dp[1] = new int[]{1, 0, 0};
        dp[2] = new int[]{1, 1, 0};
        dp[3] = new int[]{1, 1, 1};

        for (int i = 4; i <= 10000; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
            dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
        }

        while (t-- > 0) {
            int n = in.nextInt();
            System.out.println(dp[n][0] + dp[n][1] + dp[n][2]);
        }
    }
}
