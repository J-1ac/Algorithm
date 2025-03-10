package boj2467;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] liquids = new int[n];

        for (int i = 0; i < n; i++) {
            liquids[i] = sc.nextInt();
        }

        Arrays.sort(liquids);

        int ans = Integer.MAX_VALUE;
        int ansLeft = 0, ansRight = 0;
        int left = 0, right = n - 1;

        while (left < right) {
            int sum = liquids[left] + liquids[right];

            if (ans > Math.abs(sum)) {
                ans = Math.abs(sum);
                ansLeft = left;
                ansRight = right;
            }

            if (sum > 0) {
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                break;
            }
        }

        System.out.println(liquids[ansLeft] + " " + liquids[ansRight]);
    }
}
