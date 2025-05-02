package boj1027;

import java.util.Scanner;

// 기울기 비교 -> 교차 곱셈.

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] height = new int[n];

        for (int i = 0; i < n; i++) {
            height[i] = sc.nextInt();
        }

        int maxVisible = 0;

        for (int i = 0; i < n; i++) {
            int visible = 0;

            for (int j = i + 1; j < n; j++) {
                boolean canSee = true;
                for (int k = i + 1; k < j; k++) {
                    if ((long) (height[k] - height[i]) * (j - i)
                            >= (long) (height[j] - height[i]) * (k - i)) {
                        canSee = false;
                        break;
                    }
                }
                if (canSee) {
                    visible++;
                }
            }

            for (int j = i - 1; j >= 0; j--) {
                boolean canSee = true;
                for (int k = i - 1; k > j; k--) {
                    if ((long) (height[k] - height[i]) * (j - i)
                            <= (long) (height[j] - height[i]) * (k - i)) {
                        canSee = false;
                        break;
                    }
                }
                if (canSee) {
                    visible++;
                }
            }
            maxVisible = Math.max(maxVisible, visible);
        }

        System.out.println(maxVisible);
    }
}