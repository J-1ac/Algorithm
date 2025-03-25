package boj14719;

import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ans = 0;

        int h = sc.nextInt();
        int w = sc.nextInt();
        int[][] area = new int[h][w];

        for (int i = 0; i < w; i++) {
            int tempH = sc.nextInt();
            for (int j = 0; j < tempH; j++) {
                area[j][i] = 1;
            }
        }

        for (int i = 0; i < h; i++) {
            Stack<Integer> st = new Stack<>();
            for (int j = 0; j < w; j++) {
                int val = area[i][j];
                if (val == 1) {
                    while (!st.isEmpty() && st.peek() == 0) {
                        st.pop();
                        ans++;
                    }
                    st.push(val);
                } else if (val == 0) {
                    if (!st.isEmpty()) {
                        st.push(val);
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
