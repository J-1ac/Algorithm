package boj11725;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> graphs = new ArrayList<>();
        int[] parents = new int[n + 1];
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i <= n; i++) {
            graphs.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < n - 1; i++) {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            graphs.get(n1).add(n2);
            graphs.get(n2).add(n1);
        }

        q.add(1);

        while (!q.isEmpty()) {
            int current = q.poll();
            for(int i=0; i<graphs.get(current).size(); i++){
                int next = graphs.get(current).get(i);
                if(parents[next] != 0)  continue;
                parents[next] = current;
                q.add(next);
            }
        }

        for (int i = 2; i <= n; i++) {
            System.out.println(parents[i]);
        }
    }
}
