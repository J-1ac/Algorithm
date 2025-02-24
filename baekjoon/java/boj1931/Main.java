package boj1931;

import java.util.Arrays;
import java.util.Scanner;

class meeting {

    int s;
    int e;

    public meeting(int s, int e) {
        this.s = s;
        this.e = e;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), answer = 0, t = 0;

        meeting[] meetings = new meeting[n];
        for (int i = 0; i < n; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            meetings[i] = new meeting(s, e);
        }

        Arrays.sort(meetings, (m1, m2) -> {
            if (m1.e != m2.e) return Integer.compare(m1.e, m2.e);
            return Integer.compare(m1.s, m2.s);
        });

        for (meeting m : meetings) {
            if (m.s >= t) {
                t = m.e;
                answer++;
            }
        }

        System.out.println(answer);
    }
}