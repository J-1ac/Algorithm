package boj18427;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int h = sc.nextInt();
        sc.nextLine();

        List<List<Integer>> blocks = new ArrayList<>();
        blocks.add(new ArrayList<>());

        for (int i = 1; i <= n; i++) {
            String[] parts = sc.nextLine().split(" ");
            List<Integer> heights = new ArrayList<>();
            for (String s : parts) {
                if (!s.isEmpty()) {
                    heights.add(Integer.parseInt(s));
                }
            }
            blocks.add(heights);
        }
        int[][] dp = new int[n + 1][h + 1];
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            // 안 쌓는 경우
            for (int ch = 0; ch <= h; ch++) {
                dp[i][ch] = dp[i - 1][ch];
            }

            // 블록 쌓는 경우
            for (int bh : blocks.get(i)) {
                // 해당 블록 쌓을 수 있는 경우
                for (int ch = bh; ch <= h; ch++) {
                    dp[i][ch] = (dp[i][ch] + dp[i - 1][ch - bh]) % 10007;
                }
            }
        }

        System.out.println(dp[n][h]);
    }
}
