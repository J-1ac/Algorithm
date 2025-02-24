package boj2630;

import java.util.Scanner;

public class Main {

    public static int w = 0;
    public static int b = 0;

    public static void quad(int x, int y, int d, int[][] area) {
        int val = area[x][y];
        for (int i = x; i < x + d; i++) {
            for (int j = y; j < y + d; j++) {
                if (area[i][j] != val) {
                    quad(x, y, d / 2, area);
                    quad(x + d / 2, y, d / 2, area);
                    quad(x, y + d / 2, d / 2, area);
                    quad(x + d / 2, y + d / 2, d / 2, area);
                    return;
                }
            }
        }
        if (val == 0) {
            w++;
        } else {
            b++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] area = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                area[i][j] = sc.nextInt();
            }
        }

        quad(0, 0, n, area);

        System.out.println(w);
        System.out.println(b);
    }
}
