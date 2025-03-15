package boj2493;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] answers = new int[n];
        Stack<Node> st = new Stack<>();

        StringTokenizer stz = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int h = Integer.parseInt(stz.nextToken());
            while(!st.isEmpty()){
                if(h <= st.peek().h){
                    answers[i] = st.peek().i;
                    break;
                }
                st.pop();
            }

            if(st.isEmpty()){
                answers[i] = 0;
            }

            st.add(new Node(i + 1, h));
        }

        for(int ans : answers) {
            bw.write(ans + " ");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}

class Node {
    int i;
    int h;
    Node(int i, int h) {
        this.i = i;
        this.h = h;
    }
}