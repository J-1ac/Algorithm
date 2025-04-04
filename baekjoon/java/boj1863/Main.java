package boj1863;

import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = 0;
        Stack<Integer> st = new Stack<>();

        for(int i=0; i<n; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();

            while(!st.isEmpty() && st.peek() > y){
                ans++;
                st.pop();
            }

            if((st.isEmpty() || st.peek() < y) && y!=0){
                st.push(y);
            }
        }

        while(!st.isEmpty()){
            ans++;
            st.pop();
        }

        System.out.println(ans);
    }
}
