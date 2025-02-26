package boj14940;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Point {

    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] area = new int[n][m];
        int[][] ans = new int[n][m];
        Point s;
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        Queue<Point> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                area[i][j] = sc.nextInt();
                if (area[i][j] == 2) {
                    q.add(new Point(i, j));
                }
            }
        }

        while (!q.isEmpty()) {
            Point current = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || area[nx][ny] != 1
                    || ans[nx][ny] != 0) {
                    continue;
                }

                ans[nx][ny] = ans[current.x][current.y] + 1;
                q.add(new Point(nx, ny));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (area[i][j] == 1 && ans[i][j] == 0) {
                    ans[i][j] = -1;
                }
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
    }
}
