package boj14658;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int l = sc.nextInt();
        int k = sc.nextInt();

        int[][] stars = new int[k][2];
        for (int i = 0; i < k; i++) {
            stars[i][0] = sc.nextInt();
            stars[i][1] = sc.nextInt();
        }

        int best = 0;
        for (int xi = 0; xi < k; xi++) {
            for (int yj = 0; yj < k; yj++) {
                int left = stars[xi][0];
                int bottom = stars[yj][1];

                int cnt = 0;
                for (int s = 0; s < k; s++) {
                    int x = stars[s][0], y = stars[s][1];
                    if (left <= x && x <= left + l && bottom <= y && y <= bottom + l) {
                        cnt++;
                    }
                }
                best = Math.max(best, cnt);
            }
        }

        System.out.println(k - best);
    }
}
