package boj21610;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
        int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
        int[] ddx = {-1, -1, 1, 1};
        int[] ddy = {-1, 1, 1, -1};
        int[][] area = new int[n][n];
        boolean[][] cloud = new boolean[n][n];
        cloud[n - 2][0] = true;
        cloud[n - 2][1] = true;
        cloud[n - 1][0] = true;
        cloud[n - 1][1] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                area[i][j] = sc.nextInt();
            }
        }

        for (int i = 0; i < m; i++) {
            int d = sc.nextInt() - 1;
            int s = sc.nextInt();

            // 구름 이동
            boolean[][] nextCloud = new boolean[n][n];
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (cloud[x][y]) {
                        int nx = (x + dx[d] * s + n * 50) % n;
                        int ny = (y + dy[d] * s + n * 50) % n;
                        nextCloud[nx][ny] = true;
                    }
                }
            }
            cloud = nextCloud;

            // 비 내림
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (cloud[x][y]) {
                        area[x][y]++;
                    }
                }
            }

            // 물 복사
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (cloud[x][y]) {
                        int cnt = 0;
                        for (int j = 0; j < 4; j++) {
                            int nx = x + ddx[j];
                            int ny = y + ddy[j];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n || area[nx][ny] == 0) {
                                continue;
                            }
                            cnt++;
                        }
                        area[x][y] += cnt;
                    }
                }
            }

            // 구름 생성
            boolean[][] newCloud = new boolean[n][n];
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (area[x][y] >= 2 && !cloud[x][y]) {
                        newCloud[x][y] = true;
                        area[x][y] -= 2;
                    }
                }
            }
            cloud = newCloud;
        }

        int sum = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                sum += area[x][y];
            }
        }

        System.out.println(sum);
    }
}
