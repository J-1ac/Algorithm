package boj17140;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static int[][] arr = new int[100][100];
    public static int rc = 3;
    public static int cc = 3;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt() - 1;
        int c = sc.nextInt() - 1;
        int k = sc.nextInt();

        for (int i = 0; i < rc; i++) {
            for (int j = 0; j < cc; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int time = 0;
        while (time <= 100) {
            if (arr[r][c] == k) {
                System.out.println(time);
                return;
            }

            if (rc >= cc) {
                rOp();
            } else {
                cOp();
            }

            time++;
        }
        System.out.println(-1);
    }

    public static void rOp() {
        int rn = rc;
        int cn = cc;
        for (int i = 0; i < rn; i++) {
            Map<Integer, Integer> cntMap = new HashMap<>();
            for (int j = 0; j < cn; j++) {
                if (arr[i][j] == 0) {
                    continue;
                }
                cntMap.put(arr[i][j], cntMap.getOrDefault(arr[i][j], 0) + 1);
            }

            List<Integer> sortNum = new ArrayList<>(cntMap.keySet());
            sortNum.sort((a, b) -> {
                if (cntMap.get(a) == cntMap.get(b)) {
                    return a - b;
                }
                return cntMap.get(a) - cntMap.get(b);
            });

            List<Integer> rst = new ArrayList<>();
            for (int num : sortNum) {
                rst.add(num);
                rst.add(cntMap.get(num));
            }

            int size = Math.min(rst.size(), 100);
            cc = Math.max(cc, size);

            for (int j = 0; j < size; j++) {
                arr[i][j] = rst.get(j);
            }

            for (int j = rst.size(); j < cc; j++) {
                arr[i][j] = 0;
            }
        }
    }

    public static void cOp() {
        int rn = rc;
        int cn = cc;
        for (int i = 0; i < cn; i++) {
            Map<Integer, Integer> cntMap = new HashMap<>();
            for (int j = 0; j < rn; j++) {
                if (arr[j][i] == 0) {
                    continue;
                }
                cntMap.put(arr[j][i], cntMap.getOrDefault(arr[j][i], 0) + 1);
            }

            List<Integer> sortNum = new ArrayList<>(cntMap.keySet());
            sortNum.sort((a, b) -> {
                if (cntMap.get(a) == cntMap.get(b)) {
                    return a - b;
                }
                return cntMap.get(a) - cntMap.get(b);
            });

            List<Integer> rst = new ArrayList<>();
            for (int num : sortNum) {
                rst.add(num);
                rst.add(cntMap.get(num));
            }

            int size = Math.min(rst.size(), 100);
            rc = Math.max(rc, size);

            for (int j = 0; j < size; j++) {
                arr[j][i] = rst.get(j);
            }

            for (int j = rst.size(); j < rc; j++) {
                arr[j][i] = 0;
            }
        }
    }
}
