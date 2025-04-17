package boj15683;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};

    public static int[][] area;
    static List<CCTV> cctvs = new ArrayList<>();
    static int n, m, answer = 64;

    static class CCTV {

        int x, y, kind;

        CCTV(int x, int y, int kind) {
            this.x = x;
            this.y = y;
            this.kind = kind;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        area = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                area[i][j] = sc.nextInt();
                if (1 <= area[i][j] && area[i][j] <= 5) {
                    cctvs.add(new CCTV(i, j, area[i][j]));
                }
            }
        }

        dfs(0, deepCopy(area));
        System.out.println(answer);
    }

    static void dfs(int idx, int[][] board) {
        if (idx == cctvs.size()) {
            answer = Math.min(answer, countBlind(board));
            return;
        }
        CCTV c = cctvs.get(idx);

        for (int[] dirs : dirSet(c.kind)) {
            int[][] next = deepCopy(board);
            for (int d : dirs) {
                mark(next, c.x, c.y, d);
            }
            if (answer != 0) {
                dfs(idx + 1, next);
            }
        }
    }

    static int[][] dirSet(int kind) {
        switch (kind) {
            case 1:
                return new int[][]{{0}, {1}, {2}, {3}};
            case 2:
                return new int[][]{{0, 2}, {1, 3}};
            case 3:
                return new int[][]{{0, 3}, {0, 1}, {1, 2}, {2, 3}};
            case 4:
                return new int[][]{{0, 1, 3}, {0, 1, 2}, {0, 2, 3}, {1, 2, 3}};
            default:
                return new int[][]{{0, 1, 2, 3}};
        }
    }

    static void mark(int[][] board, int x, int y, int dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        while (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] != 6) {
            if (board[nx][ny] == 0) {
                board[nx][ny] = -1;
            }
            nx += dx[dir];
            ny += dy[dir];
        }
    }

    static int[][] deepCopy(int[][] src) {
        int[][] dst = new int[n][];
        for (int i = 0; i < n; i++) {
            dst[i] = src[i].clone();
        }
        return dst;
    }

    static int countBlind(int[][] board) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    sum++;
                }
            }
        }
        return sum;
    }
}
