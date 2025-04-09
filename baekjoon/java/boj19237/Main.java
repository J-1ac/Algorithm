package boj19237;

import java.util.Scanner;

public class Main {

    public static Shark[][] area;
    public static Smell[][] smell;
    public static int[][][] dir;
    public static int[] dx = {-1, 1, 0, 0};
    public static int[] dy = {0, 0, -1, 1};
    public static int n;
    public static int m;
    public static int k;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();

        area = new Shark[n][n];
        smell = new Smell[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = sc.nextInt();
                if (val != 0) {
                    area[i][j] = new Shark(val - 1, 0);
                    smell[i][j] = new Smell(val - 1, k);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int curDir = sc.nextInt() - 1;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (area[x][y] != null && area[x][y].n == i) {
                        area[x][y].d = curDir;
                    }
                }
            }
        }

        dir = new int[m][4][4];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    dir[i][j][k] = sc.nextInt() - 1;
                }
            }
        }

        int time = 0;

        while (time < 1000 && m > 1) {
            time++;

            // 상어 이동
            moveShark();

            // 냄새 업데이트
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (smell[i][j] != null) {
                        smell[i][j].cnt--;
                        if (smell[i][j].cnt == 0) {
                            smell[i][j] = null;
                        }
                    }
                }
            }

            // 새로운 냄새 추가
            int count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (area[i][j] != null) {
                        smell[i][j] = new Smell(area[i][j].n, k);
                        count++;
                    }
                }
            }

            m = count;
        }

        System.out.println(m == 1 ? time : -1);
    }

    public static void moveShark() {
        Shark[][] nextArea = new Shark[n][n];

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (area[x][y] != null) {
                    Shark shark = area[x][y];
                    boolean moved = false;
                    int[] priority = dir[shark.n][shark.d];

                    // 냄새 없는 칸 우선 탐색
                    for (int d : priority) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || smell[nx][ny] != null) {
                            continue;
                        }

                        if (nextArea[nx][ny] == null || nextArea[nx][ny].n > shark.n) {
                            nextArea[nx][ny] = new Shark(shark.n, d);
                        }
                        moved = true;
                        break;
                    }

                    if (!moved) {
                        // 자기 냄새가 있는 칸 탐색
                        for (int d : priority) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                                continue;
                            }
                            if (smell[nx][ny] != null && smell[nx][ny].shark == shark.n) {
                                if (nextArea[nx][ny] == null || nextArea[nx][ny].n > shark.n) {
                                    nextArea[nx][ny] = new Shark(shark.n, d);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }

        area = nextArea;
    }

    static class Smell {

        int shark;
        int cnt;

        public Smell(int shark, int cnt) {
            this.shark = shark;
            this.cnt = cnt;
        }
    }

    static class Shark {

        int n;
        int d;

        public Shark(int n, int d) {
            this.n = n;
            this.d = d;
        }
    }
}
