package boj16234;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        int answer = 0;

        int[][] area = new int[n][n];
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                area[i][j] = sc.nextInt();
            }
        }

        while (true) {
            int[][] union = new int[n][n];
            int index = 1;
            Queue<Node> q = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (union[i][j] != 0) {
                        continue;
                    }

                    q.add(new Node(i, j));
                    union[i][j] = index;
                    while (!q.isEmpty()) {
                        Node cur = q.poll();
                        union[cur.x][cur.y] = index;

                        for (int k = 0; k < 4; k++) {
                            int x = cur.x + dx[k];
                            int y = cur.y + dy[k];
                            if (x < 0 || x >= n || y < 0 || y >= n || union[x][y] != 0
                                    || Math.abs(area[cur.x][cur.y] - area[x][y]) < l
                                    || Math.abs(area[cur.x][cur.y] - area[x][y]) > r) {
                                continue;
                            }
                            q.add(new Node(x, y));
                            union[x][y] = index;
                        }
                    }
                    index++;
                }
            }

            if (index > n * n) {
                break;
            } else {
                answer++;
                int[] sum = new int[index + 1];
                int[] cnt = new int[index + 1];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        sum[union[i][j]] += area[i][j];
                        cnt[union[i][j]]++;
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        area[i][j] = sum[union[i][j]] / cnt[union[i][j]];
                    }
                }
            }
        }

        System.out.println(answer);
    }
}

class Node {

    int x;
    int y;

    Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}