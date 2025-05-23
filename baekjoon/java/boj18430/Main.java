package boj18430;

import java.util.Scanner;

public class Main {
    static int ans = 0;
    static int n;
    static int m;
    static int[][] area;
    static int[][][] boomerangs = {
            {{0, 0}, {-1, 0}, {0, 1}},
            {{0, 0}, {-1, 0}, {0, -1}},
            {{0, 0}, {0, -1}, {1, 0}},
            {{0, 0}, {0, 1}, {1, 0}}
    };
    static boolean[][] visited;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        area = new int[n][m];
        visited = new boolean[n][m];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                area[i][j] = sc.nextInt();
            }
        }

        makeArms(0, 0, 0);

        System.out.println(ans);
    }

    static void makeArms(int x, int y, int sum){
        if (x == n) {
            ans = Math.max(ans, sum);
            return;
        }

        int nextX = x;
        int nextY = y + 1;
        if (nextY == m) {
            nextX++;
            nextY = 0;
        }

        if (!visited[x][y]) {
            for (int[][] b : boomerangs) {
                boolean canPlace = true;
                int tempSum = 0;
                int[][] cells = new int[3][2];

                for (int k = 0; k < 3; k++) {
                    int nx = x + b[k][0];
                    int ny = y + b[k][1];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) {
                        canPlace = false;
                        break;
                    }

                    cells[k][0] = nx;
                    cells[k][1] = ny;
                }

                if (canPlace) {
                    for (int k = 0; k < 3; k++) {
                        visited[cells[k][0]][cells[k][1]] = true;
                    }

                    tempSum = area[cells[0][0]][cells[0][1]] * 2
                            + area[cells[1][0]][cells[1][1]]
                            + area[cells[2][0]][cells[2][1]];

                    makeArms(nextX, nextY, sum + tempSum);

                    for (int k = 0; k < 3; k++) {
                        visited[cells[k][0]][cells[k][1]] = false;
                    }
                }
            }
        }

        makeArms(nextX, nextY, sum);
    }
}
