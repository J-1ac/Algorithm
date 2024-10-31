#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n, k, a, b;
int nums[1000001];
int sums[1000001];

int main(int argc, char** argv){

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> nums[i];
        sums[i] = sums[i-1]+nums[i];
    }

    for(int i=0; i<k; i++){
        cin >> a >> b;
        printf("%.2f\n", float(sums[b] - sums[a-1])/float(b - a + 1));
    }

   return 0;
}