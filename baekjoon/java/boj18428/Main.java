package boj18428;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    static int n;
    static char[][] area;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static List<int[]> teachers = new ArrayList<>();
    static boolean flag = false;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        area = new char[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                area[i][j] = sc.next().charAt(0);
                if (area[i][j] == 'T') {
                    teachers.add(new int[]{i, j});
                }
            }
        }

        dfs(0, new ArrayList<>());

        System.out.println(flag ? "YES" : "NO");
    }

    static void dfs(int startIdx, List<int[]> selected) {
        if (flag) {
            return;
        }

        if (selected.size() == 3) {
            char[][] newArea = new char[n][n];
            for (int i = 0; i < n; i++) {
                newArea[i] = area[i].clone();
            }

            for (int[] obstacle : selected) {
                int x = obstacle[0];
                int y = obstacle[1];
                newArea[x][y] = 'O';
            }

            for (int[] teacher : teachers) {
                for (int i = 0; i < 4; i++) {
                    int nx = teacher[0];
                    int ny = teacher[1];
                    while (true) {
                        nx += dx[i];
                        ny += dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || newArea[nx][ny] == 'O') {
                            break;
                        }
                        if (newArea[nx][ny] == 'S') {
                            return;
                        }
                    }
                }
            }
            flag = true;
            return;
        }

        for (int i = startIdx; i < n * n; i++) {
            int x = i / n;
            int y = i % n;

            if (area[x][y] != 'X') continue;

            selected.add(new int[]{x, y});
            dfs(i + 1, selected);
            selected.remove(selected.size() - 1);
        }
    }
}
