package boj1976;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean[][] adj = new boolean[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int connected = sc.nextInt();
                if (connected == 1) {
                    adj[i][j] = true;
                    adj[j][i] = true;
                }
                adj[i][i] = true;
            }
        }

        // 플로이드-워셜
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (adj[i][k] && adj[k][j]) {
                        adj[i][j] = true;
                    }
                }
            }
        }

        int[] route = new int[m];
        for (int i = 0; i < m; i++) {
            route[i] = sc.nextInt();
        }

        boolean possible = true;
        for (int i = 0; i < m - 1; i++) {
            if (!adj[route[i]][route[i + 1]]) {
                possible = false;
                break;
            }
        }

        System.out.println(possible ? "YES" : "NO");
    }
}
