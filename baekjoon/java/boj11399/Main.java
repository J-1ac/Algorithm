package boj11399;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] cumSum = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);
        cumSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + arr[i];
        }

        System.out.println(Arrays.stream(cumSum).sum());

    }
}