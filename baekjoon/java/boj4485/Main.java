package boj4485;

import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt = 1;
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        while (true) {
            int n = sc.nextInt();
            if (n == 0) {
                break;
            }

            int[][] area = new int[n][n];
            boolean[][] visited = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    area[i][j] = sc.nextInt();
                }
            }

            PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.p - b.p);
            pq.add(new Node(0, 0, area[0][0]));
            visited[0][0] = true;

            while (!pq.isEmpty()) {
                Node cur = pq.poll();
                if (cur.x == n - 1 && cur.y == n - 1) {
                    System.out.println("Problem " + cnt + ": " + cur.p);
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
                        continue;
                    }

                    pq.add(new Node(nx, ny, cur.p + area[nx][ny]));
                    visited[nx][ny] = true;
                }
            }

            cnt++;
        }
    }

    public static class Node {

        int x;
        int y;
        int p;

        public Node(int x, int y, int p) {
            this.x = x;
            this.y = y;
            this.p = p;
        }
    }
}
