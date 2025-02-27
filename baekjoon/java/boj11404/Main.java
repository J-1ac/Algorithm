package boj11404;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] d = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(d[i], 10000000);
            d[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            d[a][b] = Math.min(d[a][b], c);
        }

        floydWarshall(d);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] == 10000000) {
                    System.out.print(0);
                } else {
                    System.out.print(d[i][j]);
                }
                if (j <= n - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }

    private static void floydWarshall(int[][] d) {
        int n = d.length;

        for (int m = 1; m < n; m++) {
            for (int s = 1; s < n; s++) {
                for (int e = 1; e < n; e++) {
                    d[s][e] = Math.min(d[s][e], d[s][m] + d[m][e]);
                }
            }
        }
    }
}
