package boj1043;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int t = sc.nextInt();

        boolean[] knowsTruth = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < t; i++) {
            int person = sc.nextInt();
            knowsTruth[person] = true;
            q.add(person);
        }

        // 각 파티에 참석한 사람 리스트
        List<List<Integer>> parties = new ArrayList<>();
        // 각 사람이 참석한 파티 리스트
        List<List<Integer>> personToParties = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            personToParties.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int cnt = sc.nextInt();
            List<Integer> party = new ArrayList<>();
            for (int j = 0; j < cnt; j++) {
                int person = sc.nextInt();
                party.add(person);
                personToParties.get(person).add(i);
            }
            parties.add(party);
        }

        boolean[] visitedParty = new boolean[m];

        while (!q.isEmpty()) {
            int person = q.poll();
            for (int partyIdx : personToParties.get(person)) {
                if (visitedParty[partyIdx]) {
                    continue;
                }
                visitedParty[partyIdx] = true;
                for (int p : parties.get(partyIdx)) {
                    if (!knowsTruth[p]) {
                        knowsTruth[p] = true;
                        q.add(p);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            boolean flag = false;
            for (int person : parties.get(i)) {
                if (knowsTruth[person]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}