package boj2169;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] area = new int[n][m];
        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                area[i][j] = sc.nextInt();
            }
        }

        dp[0][0] = area[0][0];
        for (int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i - 1] + area[0][i];
        }

        for (int i = 1; i < n; i++) {
            int[] left = new int[m];
            int[] right = new int[m];

            for (int j = 0; j < m; j++) {
                if (j == 0) {
                    left[j] = dp[i - 1][j] + area[i][j];
                } else {
                    left[j] = Math.max(left[j - 1], dp[i - 1][j]) + area[i][j];
                }
            }

            for (int j = m - 1; j >= 0; j--) {
                if (j == m - 1) {
                    right[j] = dp[i - 1][j] + area[i][j];
                } else {
                    right[j] = Math.max(right[j + 1], dp[i - 1][j]) + area[i][j];
                }
            }

            for (int j = 0; j < m; j++) {
                dp[i][j] = Math.max(left[j], right[j]);
            }
        }

        System.out.println(dp[n - 1][m - 1]);
    }
}
