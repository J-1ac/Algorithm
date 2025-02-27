package boj1865;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Edge {
    int from;
    int to;
    int weight;

    public Edge(int from, int to, int weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int w = sc.nextInt();

            List<Edge> edges = new ArrayList<>();

            for (int j = 0; j < m + w; j++) {
                int node1 = sc.nextInt();
                int node2 = sc.nextInt();
                int weight = sc.nextInt();
                if (j < m) {
                    edges.add(new Edge(node1, node2, weight));
                    edges.add(new Edge(node2, node1, weight));
                } else {
                    edges.add(new Edge(node1, node2, -weight));
                }
            }

            System.out.println(bellmanFord(n, edges) ? "YES" : "NO");

        }
    }

    private static boolean bellmanFord(int n, List<Edge> edges) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, 0);

        for (int i = 1; i <= n; i++) {
            boolean updated = false;

            for (Edge edge : edges) {
                if (dist[edge.to] > dist[edge.from] + edge.weight) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                    updated = true;

                    if (i == n) {
                        return true;
                    }
                }
            }

            if (!updated) {
                break;
            }
        }

        return false;
    }
}
