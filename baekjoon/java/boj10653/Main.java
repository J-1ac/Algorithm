package boj10653;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        int[][] dp = new int[n][k + 1];
        int inf = 1000000000;
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], inf);
        }
        dp[0][0] = 0;

        for (int i = 1; i < n; i++) {
            for (int s = 0; s < i; s++) {
                int skip = i - s - 1;           // s → i 사이에 실제로 건너뛴 개수
                if (skip > k) {
                    continue;
                }
                int d = dist[s][i];
                for (int used = skip; used <= k; used++) {
                    int prev = dp[s][used - skip];
                    if (prev + d < dp[i][used]) {
                        dp[i][used] = prev + d;
                    }
                }
            }
        }

        int ans = inf;
        for (int used = 0; used <= k; used++) {
            ans = Math.min(ans, dp[n - 1][used]);
        }
        System.out.println(ans);
    }
}