package boj1167;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

class Node {

    int n;
    int d;

    public Node(int n, int d) {
        this.n = n;
        this.d = d;
    }
}

class Edge {
    int to;
    int weight;

    public Edge(int to, int weight) {
        this.to = to;
        this.weight = weight;
    }
}

public class Main {

    public static int v;
    public static int diameter;

    private static int bfs(List<List<Edge>> graph, int start) {
        int[] distances = new int[v + 1];
        boolean[] visited = new boolean[v + 1];
        Queue<Node> q = new LinkedList<>();

        q.add(new Node(start, 0));
        visited[start] = true;

        while (!q.isEmpty()) {
            Node current = q.poll();
            distances[current.n] = current.d;

            for (Edge edge : graph.get(current.n)) {
                int next = edge.to;
                int weight = edge.weight;

                if (!visited[next]) {
                    visited[next] = true;
                    q.add(new Node(next, current.d + weight));
                }
            }
        }

        int maxIndex = 1;
        int maxDistance = distances[1];

        for (int i = 2; i <= v; i++) {
            if (distances[i] > maxDistance) {
                maxIndex = i;
                maxDistance = distances[i];
            }
        }

        diameter = maxDistance;
        return maxIndex;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        v = sc.nextInt();

        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i <= v; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 1; i <= v; i++) {
            int node = sc.nextInt();
            while (true) {
                int connected = sc.nextInt();
                if (connected == -1) break;
                int weight = sc.nextInt();
                graph.get(node).add(new Edge(connected, weight));
            }
        }

        int farthestNode = bfs(graph, 1);
        bfs(graph, farthestNode);

        System.out.println(diameter);
    }
}
