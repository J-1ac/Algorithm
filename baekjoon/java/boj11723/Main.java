package boj11723;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        HashSet<Integer> s = new HashSet<>();
        int m = Integer.parseInt(br.readLine());

        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
            int x;

            switch (op) {
                case "add":
                    x = Integer.parseInt(st.nextToken());
                    s.add(x);
                    break;

                case "remove":
                    x = Integer.parseInt(st.nextToken());
                    s.remove(x);
                    break;

                case "check":
                    x = Integer.parseInt(st.nextToken());
                    if (s.contains(x)) {
                        sb.append("1\n");
                    } else {
                        sb.append("0\n");
                    }
                    break;

                case "toggle":
                    x = Integer.parseInt(st.nextToken());
                    if (s.contains(x)) {
                        s.remove(x);
                    } else {
                        s.add(x);
                    }
                    break;

                case "all":
                    for (int j = 1; j <= 20; j++) {
                        s.add(j);
                    }
                    break;

                case "empty":
                    s.clear();
                    break;
            }
        }
        System.out.print(sb.toString());
    }
}