package boj2310;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if (n == 0) {
                break;
            }
            sc.nextLine();

            List<List<String>> rooms = new ArrayList<>();
            rooms.add(new ArrayList<>());
            for (int i = 0; i < n; i++) {
                String[] tokens = sc.nextLine().split(" ");
                List<String> tmp = new ArrayList<>(
                        Arrays.asList(tokens).subList(0, tokens.length - 1));
                rooms.add(tmp);
            }

            boolean[][] visited = new boolean[n + 1][501];
            Queue<Node> q = new LinkedList<>();
            q.add(new Node(1, 0));
            visited[1][0] = true;
            boolean flag = false;

            while (!q.isEmpty()) {
                Node cur = q.poll();
                List<String> room = rooms.get(cur.index);

                // enter
                if (room.get(0).equals("L")) {
                    if (cur.money < Integer.parseInt(room.get(1))) {
                        cur.money = Integer.parseInt(room.get(1));
                    }
                } else if (room.get(0).equals("T")) {
                    if (cur.money < Integer.parseInt(room.get(1))) {
                        continue;
                    } else {
                        cur.money -= Integer.parseInt(room.get(1));
                    }
                }

                if (cur.index == n) {
                    System.out.println("Yes");
                    flag = true;
                    break;
                }

                // next
                for (int i = 2; i < room.size(); i++) {
                    if (visited[Integer.parseInt(room.get(i))][cur.money]) {
                        continue;
                    }
                    visited[Integer.parseInt(room.get(i))][cur.money] = true;
                    q.add(new Node(Integer.parseInt(room.get(i)), cur.money));
                }
            }

            if (!flag) {
                System.out.println("No");
            }
        }
    }

    public static class Node {

        int index;
        int money;

        public Node(int index, int money) {
            this.index = index;
            this.money = money;
        }
    }
}
