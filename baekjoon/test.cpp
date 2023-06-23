#include <iostream>
using namespace std;

int main(){
    int d[15]{};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            d[4*j]=i+j;
        }
    }

    for(int n :d) cout << n << '\t';
}