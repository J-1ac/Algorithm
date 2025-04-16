package boj1806;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = sc.nextInt();
        int ans = Integer.MAX_VALUE;

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int left = 0;
        int right = 0;
        int ss = 0;
        while (right < n) {
            ss += arr[right];

            while (ss >= s) {
                ans = Math.min(ans, right - left + 1);
                ss -= arr[left];
                left++;
            }

            right++;
        }

        if (ans == Integer.MAX_VALUE) {
            System.out.println(0);
        } else {
            System.out.println(ans);
        }
    }
}
