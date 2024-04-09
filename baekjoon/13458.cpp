#include <iostream>
using namespace std;

/* how to solve
    총감독관 1명 + 필요한 부감독관 수
    감독관의 수가 21억을 넘을 수 있음
*/

int test[1000000];
int main(){
    int n, b, c;
    long long cnt=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> test[i];
    }
    cin >> b >> c;

    for(int i=0; i<n; i++){
        test[i]-=b;
        cnt++;
        if(test[i]<0) continue;
        if(test[i]%c==0) cnt+=test[i]/c;
        else             cnt+=test[i]/c+1;
    }

    cout << cnt;

    return 0;
}