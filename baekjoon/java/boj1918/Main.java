package boj1918;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String notation = sc.nextLine();
        StringBuilder ans = new StringBuilder();

        Stack<Character> st = new Stack<>();
        Map<Character, Integer> opMap = new HashMap<>();
        opMap.put('+', 1);
        opMap.put('-', 1);
        opMap.put('*', 2);
        opMap.put('/', 2);

        for (int i = 0; i < notation.length(); i++) {
            char c = notation.charAt(i);

            if (c >= 'A' && c <= 'Z') {
                ans.append(c);
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.isEmpty() && st.peek() != '(') {
                    ans.append(st.pop());
                }
                st.pop();
            } else {
                while (!st.isEmpty() && st.peek() != '(' &&
                        opMap.get(st.peek()) >= opMap.get(c)) {
                    ans.append(st.pop());
                }
                st.push(c);
            }
        }

        while (!st.isEmpty()) {
            ans.append(st.pop());
        }

        System.out.println(ans);
    }
}
