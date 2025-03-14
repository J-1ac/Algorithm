package boj16928;

import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] area = new int[100];
        Arrays.fill(area, 101);

        Map<Integer, Integer> jumps = new HashMap<>();
        for (int i = 0; i < n + m; i++) {
            jumps.put(in.nextInt() - 1, in.nextInt() - 1);
        }

        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0));
        area[0] = 0;

        while (!q.isEmpty()) {
            Node cur = q.poll();
            if (area[cur.x] < cur.cnt) {
                continue;
            }

            if (jumps.containsKey(cur.x)) {
                int jumpX = jumps.get(cur.x);
                if (area[jumpX] > cur.cnt) {
                    area[jumpX] = cur.cnt;
                    q.add(new Node(jumpX, cur.cnt));
                }
                continue;
            }

            for (int i = 1; i <= 6; i++) {
                int nx = cur.x + i;
                int nc = cur.cnt + 1;

                if (nx < 100 && area[nx] > nc) {
                    area[nx] = nc;
                    q.add(new Node(nx, nc));
                }
            }
        }

        System.out.println(area[99]);
    }
}

class Node {

    int x;
    int cnt;

    Node(int x, int cnt) {
        this.x = x;
        this.cnt = cnt;
    }
}
