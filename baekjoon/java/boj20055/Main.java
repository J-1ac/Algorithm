package boj20055;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int ans = 0;
        int cnt = 0;
        int[] belt = new int[n * 2];
        boolean[] robots = new boolean[n * 2];

        for (int i = 0; i < n * 2; i++) {
            belt[i] = in.nextInt();
        }

        while (cnt < k) {
            ans++;

            int lastBelt = belt[2 * n - 1];
            boolean lastRobot = robots[2 * n - 1];
            for (int i = 2 * n - 1; i > 0; i--) {
                belt[i] = belt[i - 1];
                robots[i] = robots[i - 1];
            }
            belt[0] = lastBelt;
            robots[0] = lastRobot;

            if (robots[n - 1]) {
                robots[n - 1] = false;
            }

            for (int i = n - 2; i >= 0; i--) {
                if (robots[i] && !robots[i + 1] && belt[i + 1] > 0) {
                    robots[i] = false;
                    robots[i + 1] = true;
                    belt[i + 1]--;
                    if (belt[i + 1] == 0) {
                        cnt++;
                    }
                }
            }

            if (robots[n - 1]) {
                robots[n - 1] = false;
            }

            if (belt[0] > 0) {
                robots[0] = true;
                belt[0]--;
                if (belt[0] == 0) {
                    cnt++;
                }
            }
        }

        System.out.println(ans);
    }
}
