package boj14502;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
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

    public static int ans = Integer.MIN_VALUE;
    public static int n;
    public static int m;

    private static void checkArea(List<Point> current, int[][] area) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        Queue<Point> q = new LinkedList<>();
        int[][] temp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = area[i][j];
                if (temp[i][j] == 2) {
                    q.add(new Point(i, j));
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            temp[current.get(i).x][current.get(i).y] = 1;
        }

        while (!q.isEmpty()) {
            Point c = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = c.x + dx[i];
                int ny = c.y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                if (temp[nx][ny] == 0) {
                    temp[nx][ny] = 2;
                    q.add(new Point(nx, ny));
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 0) {
                    cnt++;
                }
            }
        }

        ans = Math.max(ans, cnt);
    }

    public static void comb(int rx, int ry, List<Point> current, int[][] area) {
        if (current.size() == 3) {
            checkArea(current, area);
            return;
        }
        for (int i = rx; i < n; i++) {
            // 행이 바뀔 때 열 index 초기화
            for (int j = (i == rx ? ry : 0); j < m; j++) {
                if (area[i][j] != 0) {
                    continue;
                }
                current.add(new Point(i, j));
                comb(i, j + 1, current, area);
                current.remove(current.size() - 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        int[][] area = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                area[i][j] = sc.nextInt();
            }
        }

        List<Point> current = new ArrayList<>();
        comb(0, 0, current, area);

        System.out.println(ans);
    }
}
