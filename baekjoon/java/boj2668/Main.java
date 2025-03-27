package boj2668;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {

    static int[] arr;
    static boolean[] visited;
    static Set<Integer> result = new HashSet<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        arr = new int[n + 1];
        visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                findCycle(i, new LinkedHashSet<>());
            }
        }

        List<Integer> ans = new ArrayList<>(result);

        Collections.sort(ans);
        System.out.println(ans.size());
        ans.forEach(System.out::println);
    }

    static void findCycle(int curr, Set<Integer> path) {
        visited[curr] = true;
        path.add(curr);

        int next = arr[curr];

        if (!visited[next]) {
            findCycle(next, path);
        } else if (path.contains(next)) {
            boolean inCycle = false;
            for (int node : path) {
                if (node == next) {
                    inCycle = true;
                }
                if (inCycle) {
                    result.add(node);
                }
            }
        }
    }
}
