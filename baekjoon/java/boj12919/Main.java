package boj12919;

import java.util.Scanner;

public class Main {

    static String s;
    static String t;
    static int result = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine();
        t = sc.nextLine();

        dfs(t);
        System.out.println(result);
    }

    static void dfs(String cur) {
        if (cur.length() == s.length()) {
            if (cur.equals(s)) {
                result = 1;
            }
            return;
        }

        if (cur.charAt(cur.length() - 1) == 'A') {
            dfs(cur.substring(0, cur.length() - 1));
        }

        if (cur.charAt(0) == 'B') {
            String reversed = new StringBuilder(cur.substring(1)).reverse().toString();
            dfs(reversed);
        }
    }
}
