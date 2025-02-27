package boj15654;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static List<List<Integer>> perms = new ArrayList<>();

    public static void permutation(int[] nums, List<Integer> current, boolean[] visited, int n,
        int r) {
        if (current.size() == r) {
            perms.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                current.add(nums[i]);
                permutation(nums, current, visited, n, r);
                current.remove(current.size() - 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        Arrays.sort(nums);

        boolean[] visited = new boolean[n];
        permutation(nums, new ArrayList<>(), visited, n, m);

        for (List<Integer> perm : perms) {
            for (int i = 0; i < perm.size(); i++) {
                System.out.print(perm.get(i));
                if (i < perm.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}