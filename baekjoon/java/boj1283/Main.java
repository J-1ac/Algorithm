package boj1283;

import java.util.HashSet;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());

        HashSet<Character> set = new HashSet<>();

        while (n-- > 0) {
            String s = in.nextLine();
            String[] tokens = s.split(" ");
            boolean flag = false;

            for (int i = 0; i < tokens.length; i++) {
                if (!set.contains(Character.toLowerCase(tokens[i].charAt(0)))) {
                    set.add(Character.toLowerCase(tokens[i].charAt(0)));
                    flag = true;
                    StringBuilder ans = new StringBuilder(tokens[i]);
                    ans.insert(0, "[");
                    ans.insert(2, "]");
                    tokens[i] = ans.toString();
                    break;
                }
            }

            if (!flag) {
                for (int i = 0; i < tokens.length; i++) {
                    if (flag) {
                        break;
                    }
                    for (int j = 1; j < tokens[i].length(); j++) {
                        if (!set.contains(Character.toLowerCase(tokens[i].charAt(j)))) {
                            set.add(Character.toLowerCase(tokens[i].charAt(j)));
                            StringBuilder ans = new StringBuilder(tokens[i]);
                            ans.insert(j, "[");
                            ans.insert(j + 2, "]");
                            tokens[i] = ans.toString();
                            flag = true;
                            break;
                        }
                    }
                }
            }

            System.out.println(String.join(" ", tokens));
        }
    }

}
