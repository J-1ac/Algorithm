#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve 
 * 조합
*/

void combination(int n, int m, int start, std::vector<int>& currentC) {         // 조합: 중복x 순서x n개의 수 중 m개를 뽑는 과정
    if (currentC.size() == m) {                 // m개 선택한 경우
        for(int i=0; i<m; i++){
            cout << currentC[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; ++i) {
        currentC.push_back(i);
        combination(n, m, i + 1, currentC);
        currentC.pop_back();
    }
}

int main(){
    int n, m; vector<int> c;
    cin >> n >> m;

    combination(n, m, 1, c);

    return 0;
}