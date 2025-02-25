package boj11659;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] cumSum = new int[n + 1];
        cumSum[0] = 0;

        for (int i = 1; i <= n; i++) {
            cumSum[i] = cumSum[i - 1] + sc.nextInt();
        }

        for (int i = 0; i < m; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            System.out.println(cumSum[e] - cumSum[s - 1]);
        }
    }
}
