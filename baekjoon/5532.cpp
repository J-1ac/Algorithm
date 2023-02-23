#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, a, b, c, d , kd, md;
    cin >> l >> a >> b >> c >> d;
    if(a%c==0) kd=(a/c);
    else kd=(a/c)+1;

    if(b%d==0) md=(b/d);
    else md=(b/d)+1;

    if(kd>=md) cout << l-kd;
    else cout << l-md;
    return 0;
}