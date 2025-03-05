package boj15663;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

    static StringBuilder sb = new StringBuilder();

    public static void backtrack(int[] nums, int depth, int m, boolean[] visited, List<Integer> current) {
        if (depth == m) {
            for (int num : current) {
                sb.append(num).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // 현재 재귀 깊이에서 같은 숫자가 중복해서 선택되지 않도록 처리
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            current.add(nums[i]);
            backtrack(nums, depth + 1, m, visited, current);
            visited[i] = false;
            current.remove(current.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] input = new int[n];

        for (int i = 0; i < n; i++) {
            input[i] = in.nextInt();
        }

        Arrays.sort(input);
        boolean[] visited = new boolean[n];
        backtrack(input, 0, m, visited, new ArrayList<>());
        System.out.println(sb.toString());
    }
}
