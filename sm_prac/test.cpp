#include <iostream>
#include <vector>
using namespace std;

void printvector(vector<int> a){
    for(auto it=a.begin(); it!=a.end(); it++){
        cout << *it << endl;
    }
    cout << "-----------------------\n"; 
}

int main(){
    vector<int> a;
    
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    printvector(a);

    a.insert(a.begin(), 100);

    printvector(a);

    a.insert(a.begin()+2, 100);

    printvector(a);

    return 0;
}