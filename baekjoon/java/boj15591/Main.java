package boj15591;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static List<Edge>[] graph;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();

        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int usado = sc.nextInt();
            graph[a].add(new Edge(b, usado));
            graph[b].add(new Edge(a, usado));
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int k = sc.nextInt();
            int v = sc.nextInt();

            visited = new boolean[n + 1];
            int count = bfs(v, k);
            sb.append(count).append("\n");
        }

        System.out.print(sb);
    }

    static int bfs(int start, int minUsado) {
        Queue<Integer> queue = new LinkedList<>();
        visited[start] = true;
        queue.offer(start);
        int count = 0;

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (Edge edge : graph[cur]) {
                if (!visited[edge.to] && edge.usado >= minUsado) {
                    visited[edge.to] = true;
                    queue.add(edge.to);
                    count++;
                }
            }
        }

        return count;
    }

    static class Edge {

        int to, usado;

        Edge(int to, int usado) {
            this.to = to;
            this.usado = usado;
        }
    }
}