package boj5558;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int n = sc.nextInt();
        char[][] area = new char[r][c];
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        int ans = 0;
        int x = 0;
        int y = 0;

        for (int i = 0; i < r; i++) {
            String line = sc.next();
            for (int j = 0; j < c; j++) {
                area[i][j] = line.charAt(j);
                if (area[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }

        for (int cheese = 1; cheese <= n; cheese++) {
            Queue<Node> q = new LinkedList<>();
            q.add(new Node(x, y, 0));
            boolean[][] visited = new boolean[r][c];

            while (!q.isEmpty()) {
                Node cur = q.poll();
                if (area[cur.x][cur.y] - '0' == cheese) {
                    x = cur.x;
                    y = cur.y;
                    ans += cur.d;
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]
                            || area[nx][ny] == 'X') {
                        continue;
                    }
                    visited[nx][ny] = true;
                    q.add(new Node(nx, ny, cur.d + 1));
                }
            }
        }

        System.out.println(ans);
    }

    public static class Node {

        int x;
        int y;
        int d;

        public Node(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }
}
