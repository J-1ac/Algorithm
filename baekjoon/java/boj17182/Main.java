package boj17182;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[][] cost = new int[n][n];
        int[][] dp = new int[1 << n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cost[i][j] = sc.nextInt();
            }
        }

        for (int m = 0; m < n; m++) {
            for (int s = 0; s < n; s++) {
                for (int e = 0; e < n; e++) {
                    if (cost[s][e] > cost[s][m] + cost[m][e]) {
                        cost[s][e] = cost[s][m] + cost[m][e];
                    }
                }
            }
        }

        for (int i = 0; i < (1 << n); i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[1 << k][k] = 0;

        // TSP DP
        for (int visited = 0; visited < (1 << n); visited++) {
            for (int cur = 0; cur < n; cur++) {
                if ((visited & (1 << cur)) == 0) {
                    continue;
                }

                for (int next = 0; next < n; next++) {
                    if ((visited & (1 << next)) != 0) {
                        continue;
                    }

                    int nextVisited = visited | (1 << next);

                    if (dp[visited][cur] != Integer.MAX_VALUE) {
                        dp[nextVisited][next] = Math.min(
                                dp[nextVisited][next],
                                dp[visited][cur] + cost[cur][next]
                        );
                    }
                }
            }
        }

        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            answer = Math.min(answer, dp[(1 << n) - 1][i]);
        }

        System.out.println(answer);
    }
}
