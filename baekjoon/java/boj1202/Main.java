package boj1202;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        Jewel[] jewels = new Jewel[n];
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            int v = sc.nextInt();
            jewels[i] = new Jewel(m, v);
        }
        Arrays.sort(jewels, (a, b) -> a.m - b.m);

        int[] bags = new int[k];
        for (int i = 0; i < k; i++) {
            bags[i] = sc.nextInt();
        }
        Arrays.sort(bags);

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        long ans = 0;
        int idx = 0;

        for (int i = 0; i < k; i++) {
            int c = bags[i];
            while (idx < n && jewels[idx].m <= c) {
                pq.add(jewels[idx].v);
                idx++;
            }
            if (!pq.isEmpty()) {
                ans += pq.poll();
            }
        }

        System.out.println(ans);
    }

    static class Jewel {

        int m;
        int v;

        public Jewel(int m, int v) {
            this.m = m;
            this.v = v;
        }
    }
}