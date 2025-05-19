package boj17071;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static final int MAX = 500000;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int k = sc.nextInt();

        boolean[][] visited = new boolean[2][MAX + 1];
        Queue<Integer> q = new LinkedList<>();
        q.add(x);
        visited[0][x] = true;

        int t = 0;
        while (!q.isEmpty()) {
            int bro = k + t * (t + 1) / 2;
            if (bro > MAX) break;

            if (visited[t % 2][bro]) {
                System.out.println(t);
                return;
            }

            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.poll();
                for (int next : new int[]{cur - 1, cur + 1, cur * 2}) {
                    if (next < 0 || next > MAX || visited[(t + 1) % 2][next]) continue;
                    visited[(t + 1) % 2][next] = true;
                    q.add(next);
                }
            }
            t++;
        }

        System.out.println(-1);
    }
}